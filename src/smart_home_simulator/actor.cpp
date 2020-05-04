#include "actor.h"=
#include "graphics_scene.h"
#include "grid.h"
#include "smart_device.h"
#include "controller_screen.h"
#include "sd_light.h"
#include "audio.h"
#include "sd_infra_red_sensor.h"

#define LEG_SWITCH_INTERVAL 140
// marker vertical size = size of dude / MARKER_SIZE_DIVIDER
#define MARKER_SIZE_DIVIDER 5
//#define MARKER_PEN      QPen(Qt::darkGreen, 5)
#define MARKER_PEN      QPen(QColor(0, 0x80, 0, 120), boundingRect().height() / 25)
#define MARKER_BRUSH    QBrush(QColor(255, 247, 0, 20))

#define MARKER_OPACITY_ON_HOVER 0.25

//  1/7th of the screen is not accessible for the player and the view moves if he attempts to cross it
//  similar to Pokemon games
#define SCREEN_NO_MOVE_REGION_DIVIDER 7

#define SHIFT_SPEED_INCREASE 3.0

Actor::Actor(QGraphicsItem *parent)
    : QGraphicsPixmapItem (parent),
      mov_h(0),
      mov_v(0),
      speed(GRID_GRANULARITY/10),
      last_leg_switch(GetTickCount()),
      marker(nullptr),
      is_in_building(false),
      containing_room(nullptr)

{

    anim_pixmaps.still = QPixmap("resources/images/actor/dude.png").scaledToHeight(GRID_GRANULARITY*10);
    anim_pixmaps.left_up = QPixmap("resources/images/actor/dude_left_leg_up.png").scaledToHeight(GRID_GRANULARITY*10);
    anim_pixmaps.right_up = QPixmap("resources/images/actor/dude_right_leg_up.png").scaledToHeight(GRID_GRANULARITY*10);

    pixmap = &anim_pixmaps.still;
    setPixmap(*pixmap);

    scene_->addItem(this);

    setPos(scene_->GetScreenCenterScenePos());
    while(collidingItems(Qt::IntersectsItemShape).size() != collidingItems(Qt::ContainsItemShape).size()) {
        QPointF pos = scenePos();
        pos.setY(pos.y() + GRID_GRANULARITY);
        setPos(pos);
        UpdateViewport();
    }

    connect(&timer, &QTimer::timeout, this, &Actor::Move);

    setFlag(QGraphicsItem::ItemIsFocusable);
    setZValue(98.0);

    QRectF r = boundingRect();
    marker = new QGraphicsEllipseItem(0, 0, r.width() * 2, r.height() / MARKER_SIZE_DIVIDER);
    marker->setVisible(false);
    marker->setPen(MARKER_PEN);
    marker->setBrush(MARKER_BRUSH);
    setZValue(99.0);
    UpdateMarkerPos();
    scene_->addItem(marker);

    setAcceptHoverEvents(true);


    last_non_colliding_x = scenePos().x();
    last_non_colliding_y = scenePos().y();
}

Actor::~Actor()
{
    if (marker) {
        scene_->removeItem(marker);
        delete marker;
    }
}

void Actor::Stop() {
    mov_h = 0;
    mov_v = 0;
    pixmap = &anim_pixmaps.still;
    setPixmap(*pixmap);

    if (audio->last_played_sound_effect == "footstep_2.wav")
        audio->effects_player->stop();
}

/*  Some items like light glow are not derived from GraphicsItem.
    But all rooms are derived from GraphicsItem.
    This function will get the first GraphicsItem (probably rect/ellipse/polygon) containing
    the player. It will ignore the light glow item (fixing previous bug where player was blocked by the glow when it contained him).  */
QGraphicsItem * GetContainingRoomItem(QList<QGraphicsItem *> items) {
    for (auto &item : items)
        if (dynamic_cast<GraphicsItem *>(item))
            return item;
    return nullptr;
}

int GetItemsToIgnoreCount(QList<QGraphicsItem*> items) {
    int count = 0;
    for (QGraphicsItem * item: items)
        if (dynamic_cast<QGraphicsTextItem *>(item) ||
            dynamic_cast<SmartDevice *>(item) ||
            dynamic_cast<QGraphicsSimpleTextItem *>(item) ||
            dynamic_cast<QGraphicsEllipseItem *>(item) ||
            dynamic_cast<QGraphicsPixmapItem *>(item) ||
            dynamic_cast<QGraphicsPathItem *>(item))
            count++;

    return count;
}

void Actor::Move() {
    //qDebug() << "Actor::Move, GetTickCount() = " << GetTickCount();
    bool is_moving = (mov_h || mov_v);
    qreal speed_mult = GetKeyState(VK_SHIFT) & ~1 ? SHIFT_SPEED_INCREASE : 1;

    qreal x = scenePos().x();
    qreal y = scenePos().y();
    if (mov_h)
        x += mov_h * speed * speed_mult;

    if (mov_v)
        y += mov_v * speed * speed_mult;

    if (!is_moving) {
        Stop();
    }
    else {        
        setPos(x, y);

        /* here we could check if the new position of actor collides with any room */

        QList<QGraphicsItem *> containing_items = collidingItems(Qt::ContainsItemShape);
        QList<QGraphicsItem *> intersecting_items = collidingItems(Qt::IntersectsItemShape);

        // Subtract the items that should not affect the movement of the player (labels, smart devices, markers)
        int inter_sz = intersecting_items.size() - GetItemsToIgnoreCount(intersecting_items); // -1 because there's always the marker item touching colliding with dude
        int cont_sz = containing_items.size() - GetItemsToIgnoreCount(containing_items);

        QGraphicsItem * current_containing_room = GetContainingRoomItem(containing_items);

        if (inter_sz && inter_sz != cont_sz && !IsCollidingWithDoors()) {
            is_moving = false;
            setPos(last_non_colliding_x, last_non_colliding_y);

            //qDebug() << "inter_sz = " << inter_sz << ", cont_sz = " << cont_sz;
        } else {
            last_non_colliding_x = x;
            last_non_colliding_y = y;
        }

        /* If player wasn't in the building previously and room contains him */
        if (inter_sz && inter_sz == cont_sz && !is_in_building) {
            is_in_building = true;
            containing_room = current_containing_room;
            onBuildingEntered(containing_room);
        }

        /* If player was previously in the building and doesn't collide with any rooms */
        if (is_in_building && !inter_sz) {
            is_in_building = false;

            onBuildingLeft(containing_room);
            containing_room = nullptr;
        }

        /* If player is in the building and the previously detected containing room is different from the currently detected containing room. */
        if (is_in_building && cont_sz > 0) {
            if (current_containing_room != containing_room) {
                //qDebug() << "changed room, old room = " << containing_room << ", new room = " << containing_items[0];
                onRoomLeft(containing_room);
                onRoomEntered(current_containing_room);

                containing_room = current_containing_room;
            }
        }

        /*  Walking animation  */
        if (GetTickCount() > last_leg_switch + LEG_SWITCH_INTERVAL / speed_mult) {
            last_leg_switch = GetTickCount();
            if (pixmap == &anim_pixmaps.left_up) pixmap = &anim_pixmaps.right_up;
            else pixmap = &anim_pixmaps.left_up;
            setPixmap(*pixmap);

           // audio->PlayEffect("footstep_2.wav");

        }

        if (pixmap == &anim_pixmaps.still) {
            pixmap = &anim_pixmaps.left_up;
            setPixmap(*pixmap);
            last_leg_switch = GetTickCount();
        }
        UpdateMarkerPos();
        UpdateViewport();
   }
}

void Actor::onBuildingLeft(QGraphicsItem *old_room) {
    qDebug() << "Building left";
    onRoomLeft(old_room);
}

void Actor::onBuildingEntered(QGraphicsItem *new_room) {
    qDebug() << "Building entered";
    //audio->PlayEffect("Blip_Select.wav");

    onRoomEntered(new_room);
}

void Actor::onRoomLeft(QGraphicsItem *old_room) {
    qDebug() << "Room left";

    QList<QGraphicsItem *> intersecting_items = old_room->collidingItems(Qt::IntersectsItemShape);
    for (auto &item : intersecting_items) {
        if (controller_screen->auto_lights)
            if (Light *light = dynamic_cast<Light *>(item))
                light->TurnOff();

        if (InfraRedSensor * irs = dynamic_cast<InfraRedSensor *>(item))
            irs->SetPresenceDetected(false);
    }
}

void Actor::onRoomEntered(QGraphicsItem *new_room) {
    qDebug() << "Room entered";

    QList<QGraphicsItem *> intersecting_items = new_room->collidingItems(Qt::IntersectsItemShape);
    for (auto &item : intersecting_items) {
        if (controller_screen->auto_lights)
            if (Light *light = dynamic_cast<Light *>(item))
                light->TurnOn();

        if (InfraRedSensor * irs = dynamic_cast<InfraRedSensor *>(item))
            irs->SetPresenceDetected(true);
    }
}

void Actor::UpdateMarkerPos() {
    QPointF dude_center = scenePos() + boundingRect().bottomRight() / 2;
    QPointF dude_pos = scenePos();

    QPointF marker_sz = marker->boundingRect().bottomRight();

    marker->setPos(
                dude_center.x() - marker_sz.x() / 2,
                dude_pos.y() + boundingRect().height() - marker_sz.y() / 2
                );
}

void Actor::UpdateViewport() {
    QGraphicsView * v = scene_->GetVisibleView();
    QWidget* v_port = v->viewport();
    QPointF dude_screen_pos = v->mapFromScene( mapToScene(boundingRect().center()) );
    QPointF screen_center_scene_pos = v->mapToScene(v_port->rect().bottomRight()/2);
    int no_move_size_h = v_port->rect().width() / SCREEN_NO_MOVE_REGION_DIVIDER;
    int no_move_size_v = v_port->rect().height() / SCREEN_NO_MOVE_REGION_DIVIDER;
    QRectF move_zone = v_port->rect().marginsRemoved(QMargins(no_move_size_h,no_move_size_v,no_move_size_h,no_move_size_v));

    //int no_move_sz = std::min(v_port->rect().width(), v_port->rect().height()) / SCREEN_NO_MOVE_REGION_DIVIDER;
    //QRectF move_zone = v_port->rect().marginsRemoved(QMargins(no_move_sz,no_move_sz,no_move_sz,no_move_sz));

    QPolygonF dude_screen_rect_p = v->mapFromScene( mapToScene(boundingRect()) );
    qreal l,r,t,b,  // move_zone rect
          d_l, d_r, d_t, d_b,  // dude rect
          h_diff = 0, v_diff = 0;  // how far dude exceeds the screen boundary

    // get dude rect
    d_l = dude_screen_rect_p[0].x();// - marker->boundingRect().width()/5;
    d_t = dude_screen_rect_p[0].y();
    d_r = dude_screen_rect_p[1].x();// + marker->boundingRect().width()/5;
    d_b = dude_screen_rect_p[2].y();// + marker->boundingRect().height()/2;
    move_zone.getCoords(&l,&t,&r,&b);

    // if dude is out of move zone horizontally
    if (d_l < l) h_diff = d_l - l;
    if (d_r > r) h_diff = d_r - r;
    if (d_t < t) v_diff = d_t - t;
    if (d_b > b) v_diff = d_b - b;

    if (h_diff || v_diff)
        v->centerOn(screen_center_scene_pos + QPointF(h_diff, v_diff));
}

void Actor::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    QGraphicsPixmapItem::dragEnterEvent(event);
}

void Actor::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    QGraphicsPixmapItem::dragLeaveEvent(event);
}

void Actor::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    QGraphicsPixmapItem::dragMoveEvent(event);
}

void Actor::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    QGraphicsPixmapItem::dropEvent(event);
}

void Actor::focusInEvent(QFocusEvent *event)
{
    qDebug() << "Actor::focusInEvent";
    if (marker) {
        marker->setOpacity(1);
        marker->setVisible(true);
    }
    QGraphicsPixmapItem::focusInEvent(event);
}

void Actor::focusOutEvent(QFocusEvent *event)
{
    qDebug() << "Actor::focusOutEvent";
    if (marker) {
        marker->setVisible(false);
    }

    QGraphicsPixmapItem::focusOutEvent(event);
}

void Actor::keyPressEvent(QKeyEvent *event)
{  
    switch(event->key()) {
        case Qt::Key_Left:  mov_h = -1; break;
        case Qt::Key_Right: mov_h = 1;  break;
        case Qt::Key_Up:    mov_v = -1; break;
        case Qt::Key_Down:  mov_v = 1;  break;
        default: QGraphicsPixmapItem::keyPressEvent(event);
    }
}

void Actor::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key()) {
        case Qt::Key_Left:  mov_h = mov_h == -1 ? 0 : mov_h; break;
        case Qt::Key_Right: mov_h = mov_h == 1  ? 0 : mov_h; break;
        case Qt::Key_Up:    mov_v = mov_v == -1 ? 0 : mov_v; break;
        case Qt::Key_Down:  mov_v = mov_v == 1  ? 0 : mov_v; break;
        default: QGraphicsPixmapItem::keyReleaseEvent(event);
    }
}

void Actor::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //QGraphicsPixmapItem::mousePressEvent(event);
}

void Actor::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsPixmapItem::mouseMoveEvent(event);
}

void Actor::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    //QGraphicsPixmapItem::mouseReleaseEvent(event);
}

void Actor::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsPixmapItem::mouseDoubleClickEvent(event);
}

void Actor::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    //qDebug() << "Actor::hoverEnterEvent";
    if (marker && !hasFocus()) {
        marker->setOpacity(MARKER_OPACITY_ON_HOVER);
        marker->setVisible(true);
        //qDebug() << "Actor::hoverEnterEvent marker should be visible";
    }
}

void Actor::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    if (marker) {
        if (!hasFocus())
            marker->setVisible(false);
        else marker->setOpacity(1);
    }
}

QVariant Actor::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    return QGraphicsPixmapItem::itemChange(change, value);
}


bool Actor::IsCollidingWithDoors() {
    QList<QGraphicsItem *> intersecting_items = collidingItems(Qt::IntersectsItemShape);
    for (auto &intersecting_item : intersecting_items) {
        if (GraphicsItem *item = dynamic_cast<GraphicsItem *>(intersecting_item)) {
            if (item->IsDoors()) {
                return true;
            }
        }
    }
    return false;
}






