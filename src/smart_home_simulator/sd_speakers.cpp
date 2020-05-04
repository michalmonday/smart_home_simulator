#include "sd_speakers.h"


Speakers::Speakers()
    : SmartDevice()
{    
    SetLabelText("Speakers");

}

Speakers::~Speakers() {

}

void Speakers::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    SmartDevice::paint(painter, option, widget);
}


void Speakers::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    SmartDevice::hoverEnterEvent(event);
}

void Speakers::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    SmartDevice::hoverLeaveEvent(event);
}

void Speakers::keyPressEvent(QKeyEvent *event)
{
    SmartDevice::keyPressEvent(event);
}

void Speakers::keyReleaseEvent(QKeyEvent *event)
{
    SmartDevice::keyReleaseEvent(event);
}

void Speakers::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    SmartDevice::mousePressEvent(event);
}

void Speakers::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    SmartDevice::mouseMoveEvent(event);
}

void Speakers::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    SmartDevice::mouseReleaseEvent(event);
}

QVariant Speakers::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    return SmartDevice::itemChange(change, value);
}
