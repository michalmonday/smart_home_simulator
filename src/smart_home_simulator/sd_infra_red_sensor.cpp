#include "sd_infra_red_sensor.h"
#include "graphics_scene.h"
#include "sd_radiator.h"



InfraRedSensor::InfraRedSensor()
    : SmartDevice(),
      presence_detected(false),
      state_text(new QGraphicsSimpleTextItem(presence_detected ? "Presence detected" : "-", this))
{    
    SetLabelText("Infra-red sensor");

    InitStateText();
}


InfraRedSensor::~InfraRedSensor() {

}


void InfraRedSensor::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    SmartDevice::paint(painter, option, widget);
}


void InfraRedSensor::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    SmartDevice::hoverEnterEvent(event);
}

void InfraRedSensor::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    SmartDevice::hoverLeaveEvent(event);
}

void InfraRedSensor::keyPressEvent(QKeyEvent *event)
{
    SmartDevice::keyPressEvent(event);
}

void InfraRedSensor::keyReleaseEvent(QKeyEvent *event)
{
    SmartDevice::keyReleaseEvent(event);
}

void InfraRedSensor::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    SmartDevice::mousePressEvent(event);
}

void InfraRedSensor::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    SmartDevice::mouseMoveEvent(event);
}

void InfraRedSensor::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Radiator::UpdateAllRadiators();

//    for (auto &item : collidingItems(Qt::IntersectsItemShape))
//        if (Radiator *rad = dynamic_cast<Radiator *>(item))
//            rad->UpdateRangeIndicator();

    SmartDevice::mouseReleaseEvent(event);
}

QVariant InfraRedSensor::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    /*if (change == ItemPositionChange && scene())
        UpdateRangeIndicator();

    if (change == QGraphicsItem::ItemZValueChange)
        range_indicator->setZValue(value.toDouble() - 0.01);
*/
    return SmartDevice::itemChange(change, value);
}


void InfraRedSensor::InitStateText()
{
    int sz = std::max(pixmap.width(), pixmap.height());

    // prepare font
    int font_sz = sz / SD_FONT_SIZE_DIVIDER;
    QFont font(LABEL_FONT_NAME, font_sz);
    font.setBold(true);
    state_text->setFont(font);

    state_text->setFlag(QGraphicsItem::ItemIsMovable);
    UpdateStateTextPos();
    state_text->setPen(QPen(Qt::black, 1));
    SetPresenceDetected(presence_detected);
}

void InfraRedSensor::UpdateStateTextPos()
{
    int sz = std::max((int)boundingRect().width(), (int)boundingRect().height());
    int font_sz = sz / SD_FONT_SIZE_DIVIDER;
    QPointF pos_ = QPointF(boundingRect().width()/2 - state_text->boundingRect().width() / 2, -(font_sz * 1.6));
    state_text->setPos(pos_);
}

void InfraRedSensor::SetPresenceDetected(bool state)
{
    presence_detected = state;
    QColor clr;
    if (presence_detected) {
        state_text->setText("Presence detected");
        clr = Qt::green;
    } else {
        state_text->setText("-");
        clr = Qt::red;
    }

    state_text->setBrush(clr);
    UpdateStateTextPos();
}







