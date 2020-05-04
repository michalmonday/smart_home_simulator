#include "press_and_drag_creator.h"
#include "graphics_scene.h"
#include "grid.h"

PressAndDragCreator *press_and_drag_creator;

PressAndDragCreator::PressAndDragCreator()
    : item_to_add(nullptr), line(nullptr)
{
}

PressAndDragCreator::~PressAndDragCreator() {

}

void PressAndDragCreator::SetItemType(int t) {
    type = t;
}

bool PressAndDragCreator::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if(event->button() == Qt::LeftButton) {
        event->accept();

        if (type == ITEM_RECT || type == ITEM_ELLIPSE) {
            is_user_adding_item = true;

            item_to_add = new GraphicsItem(type);
            item_to_add->setFlags(ITEM_FLAGS);
            item_to_add->setPos(grid->RoundToGranularity(cursor_pos, "floor"));
            item_to_add->SetSize(QPointF(grid->GetGranularity(), grid->GetGranularity()));
            scene_->addItem(item_to_add);
            item_to_add_origin_pos = cursor_pos;
            qDebug() << "PressAndDragCreator::mousePressEvent" ;    
            return true;
        }

        if (type == ITEM_LINE) {
            is_user_adding_item = true;

            bool ignore_grid = event->modifiers() & Qt::AltModifier;
            QPointF pos = ignore_grid ? cursor_pos : grid->GetClosestPoint(cursor_pos);
            line = new QGraphicsLineItem(pos.x(), pos.y(), pos.x()+1, pos.y()+1);
            line->setFlags(ITEM_FLAGS);
            QPen pen(Qt::black, 2);
            pen.setCosmetic(true);
            line->setPen(pen);
            scene_->addItem(line);
            return true;
        }
    }

    return false;
}

bool PressAndDragCreator::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    cursor_pos = event->scenePos();

    if (item_to_add || line) {
        event->accept();

        if (type == ITEM_LINE) {
            QLineF l = line->line();
            bool ignore_grid = event->modifiers() & Qt::AltModifier;
            QPointF pos = ignore_grid ? cursor_pos : grid->GetClosestPoint(cursor_pos);
            l.setP2(pos);
            line->setLine(l);
            return true;
        }

        QPointF new_pos, new_size;
        CalculateItemSizePos(cursor_pos, new_pos, new_size);
        item_to_add->SetSize(new_size);
        item_to_add->setPos(new_pos);
        qDebug() << "PressAndDragCreator::mouseMoveEvent, new_pos = " << new_pos;
        return true;
    }

    return false;
}

bool PressAndDragCreator::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    item_to_add = nullptr;
    line = nullptr;

    if (event->button() == Qt::RightButton)
        SetCreator(base_idle_creator);

    return false;
}

bool PressAndDragCreator::keyPressEvent(QKeyEvent * event) {
    return false;
}

bool PressAndDragCreator::keyReleaseEvent(QKeyEvent * event) {
    int key = event->key();

    if (key == Qt::Key_Escape || key == Qt::Key_Delete) {
        SetCreator(base_idle_creator);
    }

    return false;
}

void PressAndDragCreator::CalculateItemSizePos(QPointF cursor_pos, QPointF &new_pos, QPointF &new_size) {
    new_pos = QPointF(
                grid->RoundToGranularity(qMin(cursor_pos.x(), item_to_add_origin_pos.x()), "floor"),
                grid->RoundToGranularity(qMin(cursor_pos.y(), item_to_add_origin_pos.y()), "floor")
                );

    QPointF end_pos = QPointF(
                grid->RoundToGranularity(qMax(cursor_pos.x(), item_to_add_origin_pos.x()), "ceil"),
                grid->RoundToGranularity(qMax(cursor_pos.y(), item_to_add_origin_pos.y()), "ceil")
                );

    new_size = end_pos - new_pos;
}
