#include "sd_light.h"

#define STATE_ON    1
#define STATE_OFF   2

#include "graphics_item.h"
#include "graphics_scene.h"



void Light::InitGlowItem() {
    if (opacity_gradient) delete opacity_gradient;
    if (glow_opacity_effect) delete glow_opacity_effect;
    if (glow_item) delete glow_item;

    // alpha mask (makes it smooth)
    int state_sz = std::max((int)boundingRect().width(), (int)boundingRect().height());
    opacity_gradient = new QRadialGradient(QPointF(state_sz, state_sz), state_sz);
    opacity_gradient->setColorAt(0.6, Qt::transparent);
    //opacity_gradient->setColorAt(0.75, QColor(0,0,0,150)); // it's set in "SetGlowOpacity()"
    opacity_gradient->setColorAt(1.0, Qt::transparent);
    glow_opacity_effect = new QGraphicsOpacityEffect;

    SetGlowOpacity(150);

    glow_item = new QGraphicsEllipseItem(0,0,state_sz*2, state_sz*2);
    qDebug() << "Light::Light(), boundingRect() = " << boundingRect();
    SetGlowColor(state.color);
    glow_item->setPen(QPen(Qt::transparent));
    glow_item->setGraphicsEffect(glow_opacity_effect);
    glow_item->setZValue(0.01);
    glow_item->setPos(state_sz / -2, state_sz / -2);

    if (state.power_on)
        TurnOn();
}

Light::Light()
    : SmartDevice(), // call parent constructor
      glow_item(nullptr),
      glow_opacity_effect(nullptr),
      opacity_gradient(nullptr)

{
    qDebug() << "Light::Light()";
    SetLabelText("Light");
    InitGlowItem();
}

Light::~Light() {
    delete opacity_gradient;
    delete glow_opacity_effect;
    delete glow_item;
}

void Light::TurnOn() {
    state.power_on = true;
    glow_item->setParentItem(this);
}

void Light::TurnOff() {
    state.power_on = false;
    glow_item->setParentItem(nullptr);
}

void Light::Toggle()
{
    if (!state.power_on) TurnOn();
    else TurnOff();

    qDebug() << "Light::Toggle(), state.power_on = " << state.power_on << ", this = " << this;
}

void Light::SetGlowColor(QColor clr)
{
    state.color = clr;
    int state_sz = std::max((int)boundingRect().width(), (int)boundingRect().height());
    QRadialGradient gradient(QPointF(state_sz,state_sz), state_sz);
    gradient.setColorAt(0.6, clr);
    clr.setHsl( (clr.hslHue() + 12) % 256, // increase hue a bit to make nice effect
                clr.hslSaturation(),
                clr.lightness()
                );
    gradient.setColorAt(1, clr);
    glow_item->setBrush(gradient);
    // qDebug() << "Light::SetColor, clr = " << clr ;
}

void Light::SetGlowOpacity(int opacity) {
    opacity_gradient->setColorAt(0.75, QColor(0,0,0, opacity % 256));
    glow_opacity_effect->setOpacityMask(*opacity_gradient);
}

QColor Light::GetColor()
{
    return state.color;
}


void Light::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    SmartDevice::paint(painter, option, widget);
}


void Light::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    //TurnOn();
    SmartDevice::hoverEnterEvent(event);
}

void Light::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    //TurnOff();
    SmartDevice::hoverLeaveEvent(event);
}

void Light::keyPressEvent(QKeyEvent *event)
{
    SmartDevice::keyPressEvent(event);
}

void Light::keyReleaseEvent(QKeyEvent *event)
{
    SmartDevice::keyReleaseEvent(event);
}

void Light::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    SmartDevice::mousePressEvent(event);
}

void Light::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    SmartDevice::mouseMoveEvent(event);
}

void Light::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    SmartDevice::mouseReleaseEvent(event);
}

QVariant Light::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    return SmartDevice::itemChange(change, value);
}

void Light::SetSize(QPointF size)
{
    SmartDevice::SetSize(size);
    InitGlowItem();
}
