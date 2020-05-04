#include "audio.h"
#include "sd_doorbell.h"

Doorbell::Doorbell()
    : SmartDevice()
{    
    SetLabelText("Doorbell");
}

Doorbell::~Doorbell() {

}

/*
void Doorbell::PaintState(QPainter *painter, QRectF bounding_rect) {

}
*/

void Doorbell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    SmartDevice::paint(painter, option, widget);
}


void Doorbell::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    SmartDevice::hoverEnterEvent(event);
}

void Doorbell::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    SmartDevice::hoverLeaveEvent(event);
}

void Doorbell::keyPressEvent(QKeyEvent *event)
{
    SmartDevice::keyPressEvent(event);
}

void Doorbell::keyReleaseEvent(QKeyEvent *event)
{
    SmartDevice::keyReleaseEvent(event);
}

void Doorbell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    SmartDevice::mousePressEvent(event);
}

void Doorbell::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    SmartDevice::mouseMoveEvent(event);
}

void Doorbell::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    SmartDevice::mouseReleaseEvent(event);
}

QVariant Doorbell::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    return SmartDevice::itemChange(change, value);
}

void Doorbell::Press()
{
    audio->PlayEffect("doorbell.wav");
}
