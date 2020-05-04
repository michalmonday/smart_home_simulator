#include "sd_toilet.h"
#include "audio.h"

Toilet::Toilet()
    : SmartDevice(),
      poo(new QGraphicsPixmapItem(QPixmap("resources/images/smart devices/poo.png").scaledToHeight(64), this))
{    
    SetLabelText("Toilet");

    poo->hide();
    poo->setPos(- 64 - 10*2, 34);
    poo->setFlag(GraphicsItemFlag::ItemIsMovable);


}

Toilet::~Toilet() {

}

void Toilet::Use()
{
    audio->PlayEffect("toilet_use_csgo.mp3");
    poo->show();
}

void Toilet::Flush()
{
    audio->PlayEffect("toilet_flush.wav");
    qDebug() << "Toilet::Flush()";
    poo->hide();
}

void Toilet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    SmartDevice::paint(painter, option, widget);
}


void Toilet::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    SmartDevice::hoverEnterEvent(event);
}

void Toilet::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    SmartDevice::hoverLeaveEvent(event);
}

void Toilet::keyPressEvent(QKeyEvent *event)
{
    SmartDevice::keyPressEvent(event);
}

void Toilet::keyReleaseEvent(QKeyEvent *event)
{
    SmartDevice::keyReleaseEvent(event);
}

void Toilet::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    SmartDevice::mousePressEvent(event);
}

void Toilet::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    SmartDevice::mouseMoveEvent(event);
}

void Toilet::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    SmartDevice::mouseReleaseEvent(event);
}

QVariant Toilet::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    return SmartDevice::itemChange(change, value);
}
