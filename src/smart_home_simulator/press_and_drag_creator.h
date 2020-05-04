#ifndef PRESS_AND_DRAG_CREATOR_H
#define PRESS_AND_DRAG_CREATOR_H

#include "graphics_item.h"
#include "creator.h"

class PressAndDragCreator : public Creator
{
public:
    PressAndDragCreator();
    ~PressAndDragCreator() override;

    void SetItemType(int t);

    bool mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    bool mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    bool mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    bool keyPressEvent(QKeyEvent * event) override;
    bool keyReleaseEvent(QKeyEvent * event) override;

private:
    QPointF cursor_pos;
    int type;
    bool is_user_adding_item; // true when LMB pressed, false when LMB released
    GraphicsItem * item_to_add;
    QPointF item_to_add_origin_pos;

    QGraphicsLineItem *line;

    void CalculateItemSizePos(QPointF cursor_pos, QPointF &new_pos, QPointF &new_size);
};

extern PressAndDragCreator * press_and_drag_creator;

#endif // PRESS_AND_DRAG_CREATOR_H


