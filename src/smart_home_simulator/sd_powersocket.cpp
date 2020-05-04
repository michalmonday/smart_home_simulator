#include "sd_powersocket.h"
#include "smart_device_creator.h" // provides: LABEL_FONT_NAME



PowerSocket::PowerSocket()
    : SmartDevice(),
    state_text(new QGraphicsSimpleTextItem(state.is_on ? "ON" : "OFF", this))
{
    SetLabelText("Power socket");
    InitStateText();
}

PowerSocket::~PowerSocket() {
    // state_text doesn't have to be deleted because PowerSocket is its' parent item all the time and deletes it itself
    // (unlike glow_item in Light class which is removes its' parent item to become invisible when Light is off)
}

void PowerSocket::InitStateText()
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
    if (state.is_on) TurnOn();
    else TurnOff();
}

/* Just to make it centered */
void PowerSocket::UpdateStateTextPos() {
    int sz = std::max((int)boundingRect().width(), (int)boundingRect().height());
    int font_sz = sz / SD_FONT_SIZE_DIVIDER;
    QPointF pos_ = QPointF(boundingRect().width()/2 - state_text->boundingRect().width() / 2, -(font_sz * 1.4));
    state_text->setPos(pos_);
}


bool PowerSocket::IsOn()
{
    return state.is_on;
}

void PowerSocket::TurnOn()
{
    state_text->setBrush(Qt::darkGreen);
    state_text->setText("ON");
    state.is_on = true;
    UpdateStateTextPos();
}

void PowerSocket::TurnOff()
{
    state_text->setBrush(Qt::red);
    state_text->setText("OFF");
    state.is_on = false;
    UpdateStateTextPos();
}

void PowerSocket::Toggle()
{
    if (!state.is_on) TurnOn();
    else TurnOff();
}

/*void PowerSocket::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    SmartDevice::paint(painter, option, widget);
}*/

/*
void PowerSocket::PaintState(QPainter *painter, QRectF bounding_rect) {

}
*/


void PowerSocket::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    SmartDevice::paint(painter, option, widget);
}

void PowerSocket::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    SmartDevice::hoverEnterEvent(event);
}

void PowerSocket::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    SmartDevice::hoverLeaveEvent(event);
}

void PowerSocket::keyPressEvent(QKeyEvent *event)
{
    SmartDevice::keyPressEvent(event);
}

void PowerSocket::keyReleaseEvent(QKeyEvent *event)
{
    SmartDevice::keyReleaseEvent(event);
}

void PowerSocket::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    SmartDevice::mousePressEvent(event);
}

void PowerSocket::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    SmartDevice::mouseMoveEvent(event);
}

void PowerSocket::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    SmartDevice::mouseReleaseEvent(event);
}

QVariant PowerSocket::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    return SmartDevice::itemChange(change, value);
}

void PowerSocket::SetSize(QPointF size)
{
    SmartDevice::SetSize(size);
    InitStateText();
}


