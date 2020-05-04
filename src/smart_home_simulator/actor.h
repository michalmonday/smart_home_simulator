#ifndef ACTOR_H
#define ACTOR_H

#include "graphics_item.h"

#include <QGraphicsPixmapItem>
#include <QTimer>

struct ActorAnimPixmaps {
    QPixmap still, left_up, right_up;
};

// inheriting from QObject for the sake of using slots/signals https://stackoverflow.com/questions/4774291/q-object-throwing-undefined-reference-to-vtable-error
/* Chapter 5, p.149 - Game programming using Qt 5 */
class Actor : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT


protected:
    /*  Variables and functions used for detecting that we entered/left building/rooms  */
    bool is_in_building;
    QGraphicsItem *containing_room;
    virtual void onBuildingLeft(QGraphicsItem *old_room);
    virtual void onBuildingEntered(QGraphicsItem *new_room);
    virtual void onRoomLeft(QGraphicsItem *old_room);
    virtual void onRoomEntered(QGraphicsItem *new_room);

public:
    explicit Actor(QGraphicsItem *parent = nullptr);
    virtual ~Actor() override;

    void Stop();

    // QGraphicsItem interface
protected:
    virtual void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
    virtual void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) override;
    virtual void dragMoveEvent(QGraphicsSceneDragDropEvent *event) override;
    virtual void dropEvent(QGraphicsSceneDragDropEvent *event) override;
    virtual void focusInEvent(QFocusEvent *event) override;
    virtual void focusOutEvent(QFocusEvent *event) override;
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

    void UpdateMarkerPos();
    void UpdateViewport();

    bool IsCollidingWithDoors();

protected:
    ActorAnimPixmaps anim_pixmaps;
    QPixmap *pixmap;
    int mov_h, mov_v; //horizontal negative = left, horizontal positive = right, vertical is equivalent
    int speed;
    unsigned long last_leg_switch;
    QGraphicsEllipseItem *marker;

    qreal last_non_colliding_x;
    qreal last_non_colliding_y;
protected slots:
    virtual void Move();
};

#endif // ACTOR_H
