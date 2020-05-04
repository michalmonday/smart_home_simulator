#include "polygon_creator.h"
#include "grid.h"
#include "graphics_scene.h"
#include "graphics_item.h"
#include "creator.h"

#include <limits>

#define PREVIEW_ELLIPSE_SIZE 10
#define PREVIEW_ELLIPSE_COLOR QColor(0, 74, 194, 50)

#define PREVIEW_LINES_COLOR Qt::black
#define PREVIEW_LINES_WIDTH 3

#define LINES_ON_LAST_POINT_PREVIEW_COLOR QColor(255, 234, 0)

PolygonCreator *polygon_creator;

PolygonCreator::PolygonCreator()
    : polygon_on_last_point_preview(new QGraphicsPolygonItem())
{
    position_preview_ellipse = new QGraphicsEllipseItem(-PREVIEW_ELLIPSE_SIZE/2, -PREVIEW_ELLIPSE_SIZE/2, PREVIEW_ELLIPSE_SIZE, PREVIEW_ELLIPSE_SIZE);
    position_preview_ellipse->setBrush(PREVIEW_ELLIPSE_COLOR);
    scene_->addItem(position_preview_ellipse);
    //position_preview_ellipse->setVisible(false);

    QColor c(DEFAULT_ITEM_COLOR);
    c.setAlpha(c.alpha() / 2);
    polygon_on_last_point_preview->setBrush(QBrush(c));
    polygon_on_last_point_preview->setVisible(false);
    scene_->addItem(polygon_on_last_point_preview);
}

PolygonCreator::~PolygonCreator() {
    delete polygon_on_last_point_preview;
}

void PolygonCreator::Reset() {
    ResetPreviewLines();
    polygon.clear();
    HidePositionPreviewEllipse();
}

bool PolygonCreator::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    return true;
}

bool PolygonCreator::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    QPointF cursor_pos = event->scenePos();
    if (position_preview_ellipse) {
        position_preview_ellipse->setPos(grid->GetClosestPoint(cursor_pos));
    }

    if (polygon.count()) {
        QLineF l = preview_lines.last()->line();
        l.setP1(grid->GetClosestPoint(cursor_pos));
        preview_lines.last()->setLine(l);
    }

    if (polygon.count() > 2 && polygon.indexOf(position_preview_ellipse->scenePos().toPoint()) == 0) {
        if (!polygon_on_last_point_preview->isVisible()) {
            QPolygon polygon_copy(polygon);
            polygon_copy.append(position_preview_ellipse->scenePos().toPoint());
            polygon_on_last_point_preview->setPolygon(polygon_copy);
            polygon_on_last_point_preview->setVisible(true);
            for (auto & line : preview_lines){
                QPen p = line->pen();
                p.setColor(LINES_ON_LAST_POINT_PREVIEW_COLOR);
                line->setPen(p);
            }
        }
    }
    else if (polygon_on_last_point_preview->isVisible()) {
        polygon_on_last_point_preview->setVisible(false);
        for (auto & line : preview_lines) {
            QPen p = line->pen();
            p.setColor(PREVIEW_LINES_COLOR);
            line->setPen(p);
        }
    }
    return false;
}

bool PolygonCreator::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        QPointF new_point = grid->GetClosestPoint(event->scenePos());
        QGraphicsLineItem *line = new QGraphicsLineItem(QLineF(polygon.count() ? polygon.last() : new_point, new_point));
        QPen line_pen(PREVIEW_LINES_COLOR, PREVIEW_LINES_WIDTH, Qt::DashLine);
        line_pen.setCosmetic(true);
        line->setPen(line_pen);
        preview_lines.push_back(line);
        scene_->addItem(line);

        polygon << new_point.toPoint();

        if (polygon.count() > 2 && polygon.indexOf(new_point.toPoint()) == 0) {
            GraphicsItem * item = new GraphicsItem(ITEM_POLYGON);
            item->SetPolygon(polygon);
            item->SetSize(GetSize()); // diff between highest and lowest
            item->setPos(0,0);
            qDebug() << "polygon size = " << GetSize() << ", pos = " << GetPos();
            scene_->addItem(item);
            polygon.clear();
            ResetPreviewLines();

            polygon_on_last_point_preview->setVisible(false);
        }
    }

    if (event->button() == Qt::RightButton) {

        if (polygon.count()) {
            scene_->removeItem(preview_lines.last());
            preview_lines.removeLast();
            polygon.removeLast();

            qDebug() << "PolygonCreator::mousePressEvent - right button, last point deleted";
        }
        else {
            Reset();
            SetCreator(base_idle_creator);
        }
    }
    return true;
}

bool PolygonCreator::keyPressEvent(QKeyEvent * event) {
    return false;
}

bool PolygonCreator::keyReleaseEvent(QKeyEvent * event) {
    int key = event->key();

    if (key == Qt::Key_Escape) {
        Reset();
        SetCreator(base_idle_creator);
    }
    return false;
}

void PolygonCreator::HidePositionPreviewEllipse() {
    position_preview_ellipse->setPos(10, 10);
}

void PolygonCreator::ResetPreviewLines() {
    for (auto &line : preview_lines) {
        scene_->removeItem(line);
    }
    preview_lines.clear();
}

QPoint PolygonCreator::GetPos() {
    int lowest_x = INT_MAX;
    int lowest_y = INT_MAX;

    for (QPoint &p : polygon) {
        if (p.x() < lowest_x)
            lowest_x = p.x();

        if (p.y() < lowest_y)
            lowest_y = p.y();
    }

    return QPoint(lowest_x, lowest_y);
}

QPoint PolygonCreator::GetSize() {
    QPoint start_pos = GetPos();

    int highest_x = INT_MIN;
    int highest_y = INT_MIN;

    for (QPoint &p : polygon) {
        if (p.x() > highest_x)
            highest_x = p.x();

        if (p.y() > highest_y)
            highest_y = p.y();
    }

    return QPoint(highest_x, highest_y) - start_pos;
}



