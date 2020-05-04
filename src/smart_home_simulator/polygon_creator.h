#ifndef POLYGON_CREATOR_H
#define POLYGON_CREATOR_H

#include "creator.h"

#include <QtCore>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QPolygon>
#include <QGraphicsLineItem>

class PolygonCreator : public Creator
{
public:
    PolygonCreator();
    ~PolygonCreator() override;

    void Reset();

    bool DrawingStarted();

    bool mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    bool mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    bool mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    bool keyPressEvent(QKeyEvent * event) override;
    bool keyReleaseEvent(QKeyEvent * event) override;

    void HidePositionPreviewEllipse();

private:
    bool is_drawing;
    QPolygon polygon;
    QVector<QPointF> points;
    QVector<QGraphicsLineItem*> preview_lines;
    QGraphicsEllipseItem * position_preview_ellipse;
    QGraphicsPolygonItem * polygon_on_last_point_preview;

    void ResetPreviewLines();

    QPoint GetPos();
    QPoint GetSize();

};

extern PolygonCreator *polygon_creator;

#endif // POLYGON_CREATOR_H
