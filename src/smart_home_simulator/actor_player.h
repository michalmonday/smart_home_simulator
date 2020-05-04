#ifndef ACTOR_PLAYER_H
#define ACTOR_PLAYER_H

#include "actor.h"
#include "sd_blinds.h"
#include "sd_controlscreen.h"
#include "sd_doorbell.h"
#include "sd_fan.h"
#include "sd_powersocket.h"
#include "sd_radiator.h"
#include "sd_toilet.h"

class Player : public Actor
{
public:
    Player();

    QGraphicsSimpleTextItem *interaction_text;

    void SetInteractionText(QString text);

public slots:
    void OnControllerScreenClose();

protected slots:
    virtual void Move() override;

private:
    bool left_last_control_screen;
    //ControlScreen *near_controlscreen;
    bool IsNearControlScreen();
    Toilet * IsNearToilet();
    Blinds * IsNearBlinds();
    PowerSocket * IsNearPowerSocket();
    Radiator * IsNearRadiator();
    Fan * IsNearFan();
    Doorbell * IsNearDoorbell();

    void UpdateInteractionText();


    // QGraphicsItem interface
protected:
    virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;
    virtual void focusInEvent(QFocusEvent *event) override;
    virtual void focusOutEvent(QFocusEvent *event) override;

    // Actor interface
private:
    virtual void onBuildingLeft(QGraphicsItem *old_room) override;
    virtual void onBuildingEntered(QGraphicsItem *new_room) override;
    virtual void onRoomLeft(QGraphicsItem *old_room) override;
    virtual void onRoomEntered(QGraphicsItem *new_room) override;
};

extern Player* player;

#endif // ACTOR_PLAYER_H
