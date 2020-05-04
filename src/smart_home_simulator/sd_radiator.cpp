#include "sd_radiator.h"
#include "graphics_scene.h"
#include "sd_thermometer.h"

static int POWER_LEVEL_INDICATOR_ALPHA = 255;


Radiator::Radiator()
    : SmartDevice(),
      connected(false),
      range_indicator(nullptr),
      is_on(false),
      state_text(new QGraphicsSimpleTextItem(is_on ? "ON" : "OFF", this)),
      power_level_indicator_outer(nullptr),
      power_level_indicator(nullptr),
      power_level(0.5f)
{    
    SetLabelText("Radiator");

    InitRangeIndicator();
    InitPowerLevelIndicator();
    InitStateText();


}

Radiator::~Radiator() {
    if (range_indicator) {
        scene_->removeItem(range_indicator);
        delete range_indicator;
    }

    if (power_level_indicator) {
        scene_->removeItem(power_level_indicator);
        delete power_level_indicator;
    }

    if (power_level_indicator_outer) {
        scene_->removeItem(power_level_indicator_outer);
        delete power_level_indicator_outer;
    }
}


void Radiator::InitRangeIndicator()
{
    range_indicator = new RangeIndicator();
    range_indicator->setBrush(QColor(0,0,0,20));
    range_indicator->setPen(QPen(Qt::transparent));

    UpdateRangeIndicator();
    scene_->addItem(range_indicator);
}

void Radiator::InitPowerLevelIndicator()
{
    if (power_level_indicator_outer) return;

    power_level_indicator_outer = new QGraphicsPathItem(this);
    QPen p(Qt::black, 3);

    power_level_indicator_outer->setPen(p);

    power_level_indicator = new QGraphicsPathItem(this);
    power_level_indicator->setPen(QPen(Qt::transparent));
    power_level_indicator->setBrush(QColor(0,255,0, POWER_LEVEL_INDICATOR_ALPHA));

    scene_->addItem(power_level_indicator_outer);
    scene_->addItem(power_level_indicator);
    UpdatePowerLevelIndicator();
}

void Radiator::OnConnected()
{
    //TurnOn();
}

void Radiator::OnDisconnected()
{
    //TurnOff();
}

void Radiator::UpdateRangeIndicator()
{
    int r = pixmap.width() * 2.0;
    range_indicator->setRect(QRect(-r, -r, r*2, r*2));

    QPointF pos = scenePos() + boundingRect().bottomRight()/2.0;
    range_indicator->setPos(pos);
    range_indicator->setVisible(true);
    range_indicator->setZValue(zValue() - 0.01);

    bool found_thermometer_in_range = false;
    for (auto *item : range_indicator->collidingItems(Qt::IntersectsItemShape))
        if (Thermometer *therm = dynamic_cast<Thermometer *>(item))
            found_thermometer_in_range = true;

    QColor clr = found_thermometer_in_range? QColor(30,30,255,20) : QColor(0,0,0,20);

    qDebug() <<found_thermometer_in_range << clr;
    range_indicator->setBrush(clr);

    if (found_thermometer_in_range && !connected)   OnConnected();
    if (!found_thermometer_in_range && connected)   OnDisconnected();

    connected = found_thermometer_in_range;

    UpdateStateTextPos();
    UpdatePowerLevelIndicator();
}

void Radiator::UpdatePowerLevelIndicator()
{
    if (!power_level_indicator_outer) return;

    int sz = pixmap.width() / 5;
    qreal roundess = sz / 5;

    QPainterPath p;
    p.setFillRule(Qt::WindingFill);
    int x = 0, y = sz * 5 - sz * 5 * power_level, w = sz, h = sz * 5 * power_level;
    p.addRoundedRect(QRectF(x, y, w, h), roundess, roundess);
    if (power_level > 0.05 && power_level <= 0.95)
        p.addRect(QRectF(x, y, w, h*0.9));
    power_level_indicator->setPath(p);

    QPainterPath p2;
    p2.addRoundedRect(QRectF(0, 0, sz, sz * 5), roundess, roundess);
    power_level_indicator_outer->setPath(p2);

    QPointF pos = scenePos();
    pos.setX(pos.x() + pixmap.width()*1.2);
    power_level_indicator_outer->setPos(pos);
    power_level_indicator->setPos(pos);

    qreal z_val = range_indicator->zValue() + 0.005;
    power_level_indicator->setZValue(z_val - 0.001);
    power_level_indicator_outer->setZValue(z_val);



    UpdatePowerIndicatorColor();

}

void Radiator::UpdatePowerIndicatorColor() {
    QColor clr;
    if (is_on)
        clr = QColor().fromHsv(255 - 255 * power_level, 255, 200, POWER_LEVEL_INDICATOR_ALPHA);
    else
        clr = QColor(150, 150, 150, POWER_LEVEL_INDICATOR_ALPHA);

    power_level_indicator->setBrush(clr);
}



/*
void Speakers::PaintState(QPainter *painter, QRectF bounding_rect) {

}
*/

void Radiator::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    SmartDevice::paint(painter, option, widget);
}


void Radiator::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    SmartDevice::hoverEnterEvent(event);
}

void Radiator::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    SmartDevice::hoverLeaveEvent(event);
}

void Radiator::keyPressEvent(QKeyEvent *event)
{
    SmartDevice::keyPressEvent(event);
}

void Radiator::keyReleaseEvent(QKeyEvent *event)
{
    SmartDevice::keyReleaseEvent(event);
}

void Radiator::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    SmartDevice::mousePressEvent(event);
}

void Radiator::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    SmartDevice::mouseMoveEvent(event);
}

void Radiator::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    SmartDevice::mouseReleaseEvent(event);
}

QVariant Radiator::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemPositionChange && scene())
        UpdateRangeIndicator();

    if (change == QGraphicsItem::ItemZValueChange)
        range_indicator->setZValue(value.toDouble() - 0.01);

    return SmartDevice::itemChange(change, value);
}

//void Radiator::SetSize(QPointF size)
//{
//    //UpdateRangeIndicator();
//}


void Radiator::InitStateText()
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
    if (is_on) TurnOn();
    else TurnOff();
}

void Radiator::UpdateStateTextPos()
{
    int sz = std::max((int)boundingRect().width(), (int)boundingRect().height());
    int font_sz = sz / SD_FONT_SIZE_DIVIDER;
    QPointF pos_ = QPointF(boundingRect().width()/2 - state_text->boundingRect().width() / 2, -(font_sz * 1.6));
    state_text->setPos(pos_);
}


void Radiator::UpdateAllRadiators()
{
    for (auto &item : scene_->items())
        if (Radiator *rad = dynamic_cast<Radiator *>(item))
            rad->UpdateRangeIndicator();
}

void Radiator::TurnOnAll()
{
    for (auto &item : scene_->items())
        if (Radiator *rad = dynamic_cast<Radiator *>(item))
            if (rad->connected)
                rad->TurnOn();
}

void Radiator::TurnOffAll()
{
    for (auto &item : scene_->items())
        if (Radiator *rad = dynamic_cast<Radiator *>(item))
            rad->TurnOff();
}

void Radiator::TurnOn()
{
    state_text->setBrush(Qt::darkGreen);
    state_text->setText("ON");
    is_on = true;
    UpdateStateTextPos();
    UpdatePowerIndicatorColor();
}

void Radiator::TurnOff()
{
    state_text->setBrush(Qt::red);
    state_text->setText("OFF");
    is_on = false;
    UpdateStateTextPos();
    UpdatePowerIndicatorColor();
}

void Radiator::IncreasePowerLevel()
{
    power_level += 0.1f;
    if (power_level > 1.0f) power_level = 1.0f;
    SetPowerLevel(power_level);
}

void Radiator::DecreasePowerLevel()
{
    power_level -= 0.1f;
    if (power_level < 0.0f) power_level = 0.0f;
    SetPowerLevel(power_level);
}


