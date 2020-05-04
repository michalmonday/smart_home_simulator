#include "graphics_scene.h"
#include "grid.h"
#include "polygon_creator.h"
#include "smart_device_creator.h"
#include "press_and_drag_creator.h"
#include "creator.h"

#include <limits>

GraphicsScene *scene_;
QTimer timer;

GraphicsScene::GraphicsScene() {
   hovered_item = nullptr;

   timer.setInterval(15);
   timer.start();
}

GraphicsScene::~GraphicsScene() {
}

QGraphicsView *GraphicsScene::GetVisibleView()
{
    QList<QGraphicsView*> scene_views = views();
    for(auto & view: views())
    {
        QWidget* viewport = view->viewport();
        if(viewport->isVisible())
            return view;
    }
}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (creator->mousePressEvent(event)) return;
    QGraphicsScene::mousePressEvent(event);
}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{ 
    if (creator->mouseMoveEvent(event)) return;
    QGraphicsItem *smallest_item = nullptr;
    int smallest_shape_length = INT_MAX;

    for (auto & item : items()) {
        if (
            item->isUnderMouse() &&
            item->type() != 6 &&
            !qgraphicsitem_cast<QGraphicsEllipseItem*>(item) &&
            !qgraphicsitem_cast<QGraphicsItemGroup*>(item) &&
                (dynamic_cast<GraphicsItem *>(item) || dynamic_cast<QGraphicsLineItem *>(item) )
            )
        { // qgraphicslineitem https://cep.xray.aps.anl.gov/software/qt4-x11-4.8.6-browser/d9/dc1/class_q_graphics_line_item.html#pub-types
            int shape_length = item->shape().length();
            if (shape_length < smallest_shape_length) {
                smallest_shape_length = shape_length;
                smallest_item = item;
            }
        }
    }

    if (smallest_item) {
        smallest_item->setZValue(1.0);
        smallest_item->update();
        //qDebug() << "GraphicsScene::mouseMoveEvent, smallest_item = " << smallest_item << "smallest_area = " << smallest_area;
        if (smallest_item != hovered_item) {

            // attempt to prevent bug by additional dynamic cast check (hoping it will detect that the object is not available anymore for some reason
            if (dynamic_cast<GraphicsItem *>(hovered_item) || dynamic_cast<QGraphicsLineItem *>(hovered_item) ) {
                //qDebug() << hovered_item;
                hovered_item->setZValue(0.1);
            }
            hovered_item = smallest_item;
        }
    }

    QGraphicsScene::mouseMoveEvent(event);
}


void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (creator->mouseReleaseEvent(event)) return;
    QGraphicsScene::mouseReleaseEvent(event);
}

void GraphicsScene::keyPressEvent(QKeyEvent * event) {
    if (creator->keyPressEvent(event)) return;
    QGraphicsScene::keyPressEvent(event);
}

void GraphicsScene::drawItems(QPainter *painter, int numItems, QGraphicsItem *items[], const QStyleOptionGraphicsItem options[], QWidget *widget)
{
    QGraphicsScene::drawItems(painter, numItems, items, options, widget);
}

void GraphicsScene::keyReleaseEvent(QKeyEvent *event){
    int key = event->key();
    if (key == Qt::Key_Delete){
        for (auto & item : selectedItems()) {
            //removeItem(item);
            if (item == hovered_item) hovered_item = nullptr;
            delete item;
        }
    }

    if (key == Qt::Key_Plus || key == Qt::Key_Minus) {
        qreal mult = (key == Qt::Key_Plus ? 1.1 : 0.9);

        for (auto & item : selectedItems()) {
            if (SmartDevice *sd = dynamic_cast<SmartDevice *>(item)) {
                QSize sz = sd->GetPixmapSize();
                sz *= mult;
                sd->SetSize(QPointF(sz.width(), sz.height()));
            }
        }
    }

    if (creator->keyReleaseEvent(event)) return;
    QGraphicsScene::keyReleaseEvent(event);
}


QPointF GraphicsScene::GetScreenCenterScenePos() {
    QGraphicsView * v = GetVisibleView();
    QWidget* v_port = v->viewport();
    return v->mapToScene(v_port->rect().bottomRight()/2);
}




