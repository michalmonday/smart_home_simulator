#include "actor_player.h"
#include "controller_screen.h"
#include "audio.h"


Player *player;

static QColor interaction_text_color = QColor(133, 186, 255);

Player::Player()
    : left_last_control_screen(true),
      //near_controlscreen(nullptr),
      interaction_text(new QGraphicsSimpleTextItem(this))
{

}

void Player::SetInteractionText(QString text)
{
    interaction_text->setText(text);
    UpdateInteractionText();
    interaction_text->show();
}

void Player::UpdateInteractionText()
{
    int font_sz = boundingRect().height() / 5;
    QFont font(LABEL_FONT_NAME, font_sz);
    font.setBold(true);
    interaction_text->setFont(font);
    interaction_text->setFlag(QGraphicsItem::ItemIsMovable);

    QPen p(Qt::black, 1);
    //p.setCosmetic(true);
    interaction_text->setPen(p);
    interaction_text->setBrush(QBrush(interaction_text_color));

    // set pos
    float x = boundingRect().width()/2 - interaction_text->boundingRect().width() / 2;
    float y =  boundingRect().height() * 1.2;
    interaction_text->setPos(x, y);
}


void Player::OnControllerScreenClose()
{
    qDebug() << "Player::OnControllerScreenClose" ;
    setFocus();
}

void Player::Move() {
//    if (IsNearControlScreen()) near_controlscreen->SetVisibleToUser(true);
//    else if (near_controlscreen) {
//        near_controlscreen->SetVisibleToUser(false);
//        near_controlscreen = nullptr;
//    }


    Actor::Move();

    if (!hasFocus()) return;

    bool is_near_control_screen = IsNearControlScreen();
    bool is_near_toilet = IsNearToilet();
    bool is_near_blinds = IsNearBlinds();
    bool is_near_powersocket = IsNearPowerSocket();
    bool is_near_radiator = IsNearRadiator();
    bool is_near_fan = IsNearFan();
    bool is_near_doorbell = IsNearDoorbell();

    //if (!interaction_text->isVisible()) {
        if (is_near_control_screen)
            SetInteractionText("Press 'e' to open\nthe control screen");

        if (is_near_blinds ||
            is_near_powersocket ||
            is_near_fan)
            SetInteractionText("Press 'e' to toggle");

        if (is_near_radiator)
            SetInteractionText("Press 'e' to toggle\nPress '-' to decrease power level\nPress '+' to increase power level");

        if (is_near_toilet)
            SetInteractionText("Press 'e' to use the toilet\nPress 'f' to flush the toilet");

        if (is_near_doorbell)
            SetInteractionText("Press 'e' to ding dong");
    //}


    if (interaction_text->isVisible() && !is_near_control_screen && !is_near_toilet && !is_near_blinds && !is_near_powersocket && !is_near_radiator && !is_near_fan && !is_near_doorbell) {
        interaction_text->hide();
    }
}

bool Player::IsNearControlScreen() {
    for (auto &item : collidingItems())
        if (ControlScreen *sd_controlscreen = dynamic_cast<ControlScreen*>(item))
            return true;

    return false;
}

Toilet * Player::IsNearToilet() {
    for (auto &item : collidingItems())
        if (Toilet *sd_toilet = dynamic_cast<Toilet *>(item))
            return sd_toilet;

    return nullptr;
}

Blinds * Player::IsNearBlinds() {
    for (auto &item : collidingItems())
        if (Blinds *blinds = dynamic_cast<Blinds *>(item))
            return blinds;

    return nullptr;
}

PowerSocket * Player::IsNearPowerSocket() {
    for (auto &item : collidingItems())
        if (PowerSocket *ps = dynamic_cast<PowerSocket *>(item))
            return ps;

    return nullptr;
}

Radiator * Player::IsNearRadiator() {
    for (auto &item : collidingItems())
        if (Radiator *rad = dynamic_cast<Radiator *>(item))
            return rad;

    return nullptr;
}

Fan * Player::IsNearFan() {
    for (auto &item : collidingItems())
        if (Fan *fan = dynamic_cast<Fan *>(item))
            return fan;

    return nullptr;
}

Doorbell * Player::IsNearDoorbell() {
    for (auto &item : collidingItems())
        if (Doorbell *db = dynamic_cast<Doorbell *>(item))
            return db;

    return nullptr;
}


QVariant Player::itemChange(GraphicsItemChange change, const QVariant &value)
{
    return Actor::itemChange(change, value);
}


void Player::keyReleaseEvent(QKeyEvent *event)
{
    int key = event->key();
    if (IsNearControlScreen() && key == Qt::Key_E)
        controller_screen->show();

    if (Toilet *toilet = IsNearToilet()) {
        if (key == Qt::Key_E)
            toilet->Use();

        if (key == Qt::Key_F)
            toilet->Flush();
    }

    if (key == Qt::Key_E) {
        bool any_switched = false;
        if (Blinds *blinds = IsNearBlinds())        { blinds->Toggle(); any_switched = true; }
        if (PowerSocket *ps = IsNearPowerSocket())  { ps->Toggle();     any_switched = true; }
        if (Radiator *rad = IsNearRadiator())       { rad->Toggle();    any_switched = true; }
        if (Fan *fan = IsNearFan())                 { fan->Toggle();    any_switched = true; }
        if (Doorbell *db = IsNearDoorbell())        { db->Press(); }

        if (any_switched)
            audio->PlayEffect("switch.wav");
    }

    if (key == Qt::Key_Minus)
        if (Radiator *rad = IsNearRadiator())
            rad->DecreasePowerLevel();

    if (key == Qt::Key_Plus)
        if (Radiator *rad = IsNearRadiator())
            rad->IncreasePowerLevel();

    Actor::keyReleaseEvent(event);
}


void Player::focusInEvent(QFocusEvent *event)
{
    interaction_text->show();
    Actor::focusInEvent(event);
}

void Player::focusOutEvent(QFocusEvent *event)
{
    interaction_text->hide();
    Actor::focusOutEvent(event);
}


void Player::onBuildingLeft(QGraphicsItem *old_room)
{
    Actor::onBuildingLeft(old_room);
}

void Player::onBuildingEntered(QGraphicsItem *new_room)
{

    Actor::onBuildingEntered(new_room);
}

void Player::onRoomLeft(QGraphicsItem *old_room)
{
    for (auto &item : old_room->collidingItems())
        if (Toilet *sd_toilet = dynamic_cast<Toilet *>(item))
            if (sd_toilet->poo->isVisible())
                sd_toilet->Flush();

    Actor::onRoomLeft(old_room);
}

void Player::onRoomEntered(QGraphicsItem *new_room)
{

    Actor::onRoomEntered(new_room);
}
