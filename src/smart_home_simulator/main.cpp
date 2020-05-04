/* It just starts the app. Btw at the end of the file I added currently not used snippets/code-pieces found online.
These may be useful in future. */

#include "mainwindow.h"
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.app = &a;
    w.show();

    return a.exec();
}






/* CURRENTLY NOT USED SNIPPETS/CODE-PIECES FOUND ONLINE: */


//designer->OnKeyPress(event);

/*
if(event->key() == Qt::Key_Backspace) {
    // remove all selected items
    qDebug() << "selected items" << selectedItems().size();
    while(!selectedItems().isEmpty()) {
        removeItem(selectedItems().front());
    }
} else {
    QGraphicsScene::keyPressEvent(event);
}
*/



/*
qDebug() << "Custom scene clicked. " << event->scenePos();

if(!event->isAccepted()) {
    if(event->button() == Qt::LeftButton) {
        // add a custom item to the scene
        QPointF pt = event->scenePos();

        //CustomItem * item = new CustomItem();

        QGraphicsRectItem * item = new QGraphicsRectItem();

        item->setRect(pt.x()-25, pt.y()-25, 50, 50);
        item->setFlags(QGraphicsItem::ItemIsSelectable|
                      QGraphicsItem::ItemIsMovable);
        addItem(item);
    } else if(event->button() == Qt::RightButton) {
        // check whether there is an item under the cursor
        QGraphicsItem * itemToRemove = NULL;
        foreach(auto item, items(event->scenePos())) {
            if(item->type() == QGraphicsItem::UserType+1) {
                itemToRemove = item;
                break;
            }
        }
        if(itemToRemove) {
            // remove the item from the graphicsScene
            removeItem(itemToRemove);
        }
    }
}
*/




/*
if(event->button() == Qt::LeftButton) {
    if(event->modifiers() == Qt::ShiftModifier) {
        qDebug() << "Custom item left clicked with shift key.";
        // add the item to the selection
        setSelected(true);
    } else if(event->modifiers() == Qt::AltModifier){
        qDebug() << "Custom item left clicked with alt key.";
        // resize the item
        double radius = boundingRect().width() / 2.0;
        _center = QPointF(boundingRect().topLeft().x() + pos().x() + radius, boundingRect().topLeft().y() + pos().y() + radius);
        QPointF pos = event->scenePos();
        qDebug() << boundingRect() << radius << this->pos() << pos << event->pos();
        double dist = sqrt(pow(_center.x()-pos.x(), 2) + pow(_center.y()-pos.y(), 2));
        if(dist / radius > 0.8) {
            qDebug() << dist << radius << dist / radius;
            _isResizing = true;
        } else {
            _isResizing = false;
        }
    } else {
        qDebug() << "Custom item left clicked.";
        QGraphicsItem::mousePressEvent(event);
        event->accept();
    }
} else if(event->button() == Qt::RightButton) {
    qDebug() << "Custom item right clicked.";
    event->ignore();
}
*/


/*
if(event->modifiers() == Qt::AltModifier && _isResizing){
    QPointF pos = event->scenePos();
    double dist = sqrt(pow(_center.x()-pos.x(), 2) + pow(_center.y()-pos.y(), 2));
    qDebug("Shape::mouseMoveEvent should resize shape now");
    reinterpret_cast<QGraphicsRectItem *>(this)->setRect(_center.x()-this->pos().x()-dist, _center.y()-this->pos().y()-dist, dist*2, dist*2);
    SetSize(dist, dist);
} else if(event->modifiers() != Qt::AltModifier) {
    qDebug() << "Custom item moved.";
    QGraphicsItem::mouseMoveEvent(event);
    qDebug()<<"moved"<<pos();
}
*/



/*
if(event->modifiers() == Qt::AltModifier && _isResizing) {
    _isResizing = false;
} else if(event->modifiers() != Qt::ShiftModifier) {
    QGraphicsItem::mouseReleaseEvent(event);
}
*/
