#include "graphics_item.h"
#include "grid.h"
#include "actor.h"
#include "smart_device.h"




GraphicsItem::GraphicsItem(int type) {
    qDebug() << "GraphicsItem::GraphicsItem constructor, type = " << type;
    hovered = false;
    item_type = type;
    size_x = size_y = DEFAULT_ITEM_SIZE;

    setFlags(ITEM_FLAGS);
    setCursor(Qt::PointingHandCursor);
    setAcceptHoverEvents(true);
    setZValue(0.1);

    is_doors = false;
    color = DEFAULT_ITEM_COLOR;

    //setAcceptDrops(true); // enables dragEnter dragLeave events
}

GraphicsItem::~GraphicsItem()
{
}

QRectF GraphicsItem::boundingRect() const
{
    if (item_type == ITEM_POLYGON)
        return polygon.boundingRect();

    if (item_type == ITEM_SMART_DEVICE) {
        const SmartDevice *sd = dynamic_cast<const SmartDevice *>(this);
        if (sd) {
            QSize sz = sd->GetPixmapSize();
            return QRectF(0,0, sz.width(), sz.height());
        }
    }

    return QRectF(0, 0, size_x, size_y);
}

QPainterPath GraphicsItem::shape() const
{
    if (item_type == ITEM_POLYGON) {
        QPainterPath path;
        path.addPolygon(polygon);
        return path;
    }

    if (item_type == ITEM_ELLIPSE) {
        QPainterPath path;
        path.addEllipse(boundingRect());
        return path;
    }

    return QGraphicsItem::shape();
}

QPainterPath GraphicsItem::opaqueArea() const
{
    return QGraphicsItem::opaqueArea();
}

void GraphicsItem::SetSize(QPointF size) {
    qDebug() << "GraphicsItem::SetSize, size = " << size;

    size_x = (int)size.x();
    size_y = (int)size.y();

    prepareGeometryChange();
}

void GraphicsItem::SetPolygon(QPolygon p) {
    polygon = p;
}


void GraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    QGraphicsItem::mousePressEvent(event);
}

void GraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    prepareGeometryChange();

    QGraphicsItem::mouseMoveEvent(event);
}

void GraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    Qt::MouseButton btn = event->button();
    if (btn == Qt::MouseButton::RightButton) {
        clearFocus();
        setSelected(false);
    }
    QGraphicsItem::mouseReleaseEvent(event);
}

void GraphicsItem::keyPressEvent(QKeyEvent * event) {
    QGraphicsItem::keyPressEvent(event);
}

void GraphicsItem::keyReleaseEvent(QKeyEvent *event) {
    QGraphicsItem::keyReleaseEvent(event);
}

void GraphicsItem::PaintSelectionDashedBoundingRect(QPainter * painter) {
    QPen p = QPen(Qt::DashLine);
    p.setCosmetic(true); // keeps the size of pen consistent regardless of zoom
    painter->setPen(p);
    painter->setBrush(QBrush(Qt::transparent));
    painter->drawRect(boundingRect());
}

void GraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QRectF rect(0, 0, size_x, size_y);

    QPen pen_;
    QBrush brush_;
    bool is_selected = option->state & QStyle::State_Selected;

    pen_ = DEFAULT_ITEM_PEN;
    brush_ = (is_doors ? DOORS_ITEM_COLOR : color);

    if (is_selected && creator == base_idle_creator) {
        // pen_ = SELECTED_PEN;
        // brush_ = (is_doors ? SELECTED_DOOR_COLOR : SELECTED_COLOR);

        QColor clr = brush_.color();
        clr.setAlpha( (clr.alpha() * 4) % 255 );
        brush_.setColor(clr);
    } else {

        // brush_ = (is_doors ? DOORS_ITEM_COLOR : DEFAULT_ITEM_COLOR);
    }

    if (hovered && creator == base_idle_creator) {
        //pen_ = HOVER_PEN;
        pen_.setWidth(pen_.width() + 2);
        PaintSelectionDashedBoundingRect(painter); // could be replaced with QRubberBand (but it's alright)
    }

    bool is_simulation_mode = pMainWindow->ui->radioButton_Simulation->isChecked();
    if (is_simulation_mode && !is_doors) {
        //pen_.setColor(Qt::white);
        //brush_.setColor(QColor(10,10,10, 30));
    }


    pen_.setCosmetic(true); // makes it consistent regardless of zoom (otherwise it would be barely visible when zoomed-out)
    painter->setPen(pen_);
    painter->setBrush(brush_);

    if (item_type == ITEM_RECT) {
        painter->drawRect(rect);
    } else if (item_type == ITEM_ELLIPSE) {
        painter->drawEllipse(rect);
    } else if (item_type == ITEM_POLYGON) {
        painter->drawPolygon(polygon);
    } else if (item_type == ITEM_SMART_DEVICE) {
        // moved this to SmartDevice
    }
}

QVariant GraphicsItem::itemChange(GraphicsItemChange change, const QVariant &value) {
   // qDebug() << "GraphicsItem::itemChange change = " << change << ", value = " << value;
    if (change == ItemPositionChange && scene()) {
        return grid->GetClosestPoint(value.toPointF());
    }

    return QGraphicsItem::itemChange(change, value);
}

void GraphicsItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event) {
    /* This event gets triggered when mouse enters area over the item with top-z value
    z = "depth", if 2 elements are over each other, then the one with higher z value gets selected.
    */
    hovered = true;
    update();
}

void GraphicsItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) {
    /* This event gets triggered when mouse leaves area over the item with top-z value */
    hovered = false;
    update();
}

/*
void GraphicsItem::dragEnterEvent(QGraphicsSceneDragDropEvent *event) {
    qDebug() << "GraphicsItem::dragEnterEvent, item_ID = " << item_ID;
}

void GraphicsItem::dragLeaveEvent(QGraphicsSceneDragDropEvent *event) {
    qDebug() << "GraphicsItem::dragLeaveEvent, item_ID = " << item_ID;
}
*/

void GraphicsItem::SetItemType(int id) {
    item_type = id;
}

int GraphicsItem::GetItemType() {
    return item_type;
}


void GraphicsItem::SetPixmapColor(QPixmap &p, QColor c) {
    int supplied_alpha = c.alpha();
    QImage tmp = p.toImage();
    for(int y = 0; y < tmp.height(); y++)
    {
      for(int x= 0; x < tmp.width(); x++)
      {
        int orig_alpha = tmp.pixelColor(x,y).alpha();
        if (orig_alpha) c.setAlpha(supplied_alpha);
        else c.setAlpha(orig_alpha);
        tmp.setPixelColor(x,y, c);
      }
    }
    p = QPixmap::fromImage(tmp);
}

bool GraphicsItem::ToggleDoors() {
    is_doors = !is_doors;
    update();
    return is_doors;
}

bool GraphicsItem::IsDoors() {
    return is_doors;
}

void GraphicsItem::SetColor(QColor c)
{
    c.setAlpha(color.alpha());
    color = c;
}


