#include "sd_fan.h"
#include "smart_device_creator.h" // provides: LABEL_FONT_NAME



Fan::Fan()
    : SmartDevice(),
    is_on(false),
    state_text(new QGraphicsSimpleTextItem(is_on ? "ON" : "OFF", this))
{
    SetLabelText("Fan");
    InitStateText();
}

Fan::~Fan() {
    // state_text doesn't have to be deleted because Fan is its' parent item all the time and deletes it itself
    // (unlike glow_item in Light class which is removes its' parent item to become invisible when Light is off)
}

void Fan::InitStateText()
{
    int sz = std::max((int)boundingRect().width(), (int)boundingRect().height());

    // prepare font
    int font_sz = sz / SD_FONT_SIZE_DIVIDER;
    QFont font(LABEL_FONT_NAME, font_sz);
    font.setBold(true);
    state_text->setFont(font);

    state_text->setFlag(QGraphicsItem::ItemIsMovable);
    UpdateStateTextPos();
    state_text->setPen(QPen(Qt::black, 1));
    if (is_on) TurnOn();
    else TurnOff();
}

/* Just to make it centered */
void Fan::UpdateStateTextPos() {
    int sz = std::max((int)boundingRect().width(), (int)boundingRect().height());
    int font_sz = sz / SD_FONT_SIZE_DIVIDER;
    QPointF pos_ = QPointF(boundingRect().width()/2 - state_text->boundingRect().width() / 2, -(font_sz * 1.4));
    state_text->setPos(pos_);
}


bool Fan::IsOn()
{
    return is_on;
}

void Fan::TurnOnAll()
{
    for (auto &item : scene_->items())
        if (Fan *fan = dynamic_cast<Fan *>(item))
                fan->TurnOn();
}

void Fan::TurnOffAll()
{
    for (auto &item : scene_->items())
        if (Fan *fan = dynamic_cast<Fan *>(item))
            fan->TurnOff();
}

void Fan::TurnOn()
{
    state_text->setBrush(Qt::darkGreen);
    state_text->setText("ON");
    is_on = true;
    UpdateStateTextPos();
}

void Fan::TurnOff()
{
    state_text->setBrush(Qt::red);
    state_text->setText("OFF");
    is_on = false;
    UpdateStateTextPos();
}

void Fan::Toggle()
{
    if (!is_on) TurnOn();
    else TurnOff();
}

/*void Fan::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    SmartDevice::paint(painter, option, widget);
}*/

/*
void Fan::PaintState(QPainter *painter, QRectF bounding_rect) {

}
*/


void Fan::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    SmartDevice::paint(painter, option, widget);
}

void Fan::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    SmartDevice::hoverEnterEvent(event);
}

void Fan::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    SmartDevice::hoverLeaveEvent(event);
}

void Fan::keyPressEvent(QKeyEvent *event)
{
    SmartDevice::keyPressEvent(event);
}

void Fan::keyReleaseEvent(QKeyEvent *event)
{
    SmartDevice::keyReleaseEvent(event);
}

void Fan::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    SmartDevice::mousePressEvent(event);
}

void Fan::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    SmartDevice::mouseMoveEvent(event);
}

void Fan::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    SmartDevice::mouseReleaseEvent(event);
}

QVariant Fan::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    return SmartDevice::itemChange(change, value);
}

void Fan::SetSize(QPointF size)
{
    SmartDevice::SetSize(size);
    InitStateText();
}


