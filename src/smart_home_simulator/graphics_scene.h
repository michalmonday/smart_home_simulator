/*
    Based on: https://gist.github.com/benjbaron/532a476560f3d7085bda
*/

#ifndef GRAPHICS_SCENE_H
#define GRAPHICS_SCENE_H

#include <QtGui>
#include <QGraphicsRectItem>
#include <QGraphicsView>
//#include <QApplication>
#include <QGraphicsSceneMouseEvent>
#include "graphics_item.h"



class GraphicsScene : public QGraphicsScene
{
public:
    GraphicsScene();
    ~GraphicsScene() override;

    QGraphicsView * GetVisibleView();

    QPointF GetScreenCenterScenePos();

    virtual void keyReleaseEvent(QKeyEvent *event) override; // public because MainWindow::keyReleaseEvent(QKeyEvent *event) needed to pass the event to it
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void keyPressEvent(QKeyEvent * event) override;

private:
    QPointF cursor_pos;
    QGraphicsItem * hovered_item;

    // QGraphicsScene interface
protected:
    void drawItems(QPainter *painter, int numItems, QGraphicsItem *items[], const QStyleOptionGraphicsItem options[], QWidget *widget) override;
};

extern GraphicsScene *scene_;
extern QTimer timer;

#endif // GraphicsScene_H


