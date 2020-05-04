#include "audio.h"
#include "sd_blinds.h"
#include "smart_device_creator.h" // provides: LABEL_FONT_NAME



Blinds::Blinds()
    : SmartDevice(),
    is_open(false),
    state_text(new QGraphicsSimpleTextItem(is_open ? "Open" : "Closed", this))
{
    SetLabelText("Blinds");
    InitStateText();
}

Blinds::~Blinds() {
    // state_text doesn't have to be deleted because Blinds is its' parent item all the time and deletes it itself
    // (unlike glow_item in Light class which is removes its' parent item to become invisible when Light is off)
}

void Blinds::InitStateText()
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
    if (is_open) Open();
    else Close();
}

/* Just to make it centered */
void Blinds::UpdateStateTextPos() {
    int sz = std::max((int)boundingRect().width(), (int)boundingRect().height());
    int font_sz = sz / SD_FONT_SIZE_DIVIDER;
    QPointF pos_ = QPointF(boundingRect().width()/2 - state_text->boundingRect().width() / 2, -(font_sz * 1.4));
    state_text->setPos(pos_);
}


bool Blinds::IsOpen()
{
    return is_open;
}

void Blinds::OpenAll()
{
    for (auto &item : scene_->items())
        if (Blinds *Blinds = dynamic_cast<class Blinds *>(item))
                Blinds->Open();
    audio->PlayEffect("switch.wav");
}

void Blinds::CloseAll()
{
    for (auto &item : scene_->items())
        if (Blinds *Blinds = dynamic_cast<class Blinds *>(item))
            Blinds->Close();
    audio->PlayEffect("switch.wav");
}

void Blinds::Open()
{
    state_text->setBrush(Qt::yellow);
    state_text->setText("Open");
    is_open = true;
    UpdateStateTextPos();
}

void Blinds::Close()
{
    state_text->setBrush(Qt::darkBlue);
    state_text->setText("Closed");
    is_open = false;
    UpdateStateTextPos();
}

void Blinds::Toggle()
{
    if (!is_open) Open();
    else Close();
}

/*void Blinds::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    SmartDevice::paint(painter, option, widget);
}*/

/*
void Blinds::PaintState(QPainter *painter, QRectF bounding_rect) {

}
*/


void Blinds::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    SmartDevice::paint(painter, option, widget);
}

void Blinds::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    SmartDevice::hoverEnterEvent(event);
}

void Blinds::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    SmartDevice::hoverLeaveEvent(event);
}

void Blinds::keyPressEvent(QKeyEvent *event)
{
    SmartDevice::keyPressEvent(event);
}

void Blinds::keyReleaseEvent(QKeyEvent *event)
{
    SmartDevice::keyReleaseEvent(event);
}

void Blinds::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    SmartDevice::mousePressEvent(event);
}

void Blinds::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    SmartDevice::mouseMoveEvent(event);
}

void Blinds::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    SmartDevice::mouseReleaseEvent(event);
}

QVariant Blinds::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    return SmartDevice::itemChange(change, value);
}

void Blinds::SetSize(QPointF size)
{
    SmartDevice::SetSize(size);
    InitStateText();
}


