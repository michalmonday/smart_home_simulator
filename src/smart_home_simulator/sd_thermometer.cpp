#include "sd_thermometer.h"
#include "graphics_scene.h"
#include "sd_radiator.h"



Thermometer::Thermometer()
    : SmartDevice()
{    
    SetLabelText("Thermometer");

}


Thermometer::~Thermometer() {

}


void Thermometer::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    SmartDevice::paint(painter, option, widget);
}


void Thermometer::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    SmartDevice::hoverEnterEvent(event);
}

void Thermometer::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    SmartDevice::hoverLeaveEvent(event);
}

void Thermometer::keyPressEvent(QKeyEvent *event)
{
    SmartDevice::keyPressEvent(event);
}

void Thermometer::keyReleaseEvent(QKeyEvent *event)
{
    SmartDevice::keyReleaseEvent(event);
}

void Thermometer::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    SmartDevice::mousePressEvent(event);
}

void Thermometer::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    SmartDevice::mouseMoveEvent(event);
}

void Thermometer::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Radiator::UpdateAllRadiators();

//    for (auto &item : collidingItems(Qt::IntersectsItemShape))
//        if (Radiator *rad = dynamic_cast<Radiator *>(item))
//            rad->UpdateRangeIndicator();

    SmartDevice::mouseReleaseEvent(event);
}

QVariant Thermometer::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    /*if (change == ItemPositionChange && scene())
        UpdateRangeIndicator();

    if (change == QGraphicsItem::ItemZValueChange)
        range_indicator->setZValue(value.toDouble() - 0.01);
*/
    return SmartDevice::itemChange(change, value);
}







