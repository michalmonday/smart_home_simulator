#ifndef SD_RADIATOR_H
#define SD_RADIATOR_H

#include "range_indicator.h"
#include "smart_device.h"


class Radiator : public SmartDevice
{
public:
    Radiator();
    virtual ~Radiator() override;

    //void PaintState(QPainter * painter, QRectF bounding_rect) override;
    //void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    // QGraphicsItem interface
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    virtual void keyPressEvent(QKeyEvent *event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

    //virtual void SetSize(QPointF size) override;

    void InitStateText(); // ON or OFF text above the image/pixmap
    void UpdateRangeIndicator();
    void UpdatePowerLevelIndicator();

    static void UpdateAllRadiators();
    static void TurnOnAll();
    static void TurnOffAll();

    void TurnOn();
    void TurnOff();
    void Toggle() { if (is_on) { TurnOff(); } else { TurnOn(); } }

    void SetPowerLevel(float val) { power_level = val; UpdatePowerLevelIndicator(); }
    float GetPowerLevel() { return power_level; }

    void IncreasePowerLevel();
    void DecreasePowerLevel();
private:
    bool connected;
    RangeIndicator *range_indicator;
    bool is_on;

    QGraphicsSimpleTextItem * state_text;

    QGraphicsPathItem *power_level_indicator_outer, *power_level_indicator;

    float power_level;


    void UpdateStateTextPos();

    void InitRangeIndicator();
    void InitPowerLevelIndicator();
    void UpdatePowerIndicatorColor();

    void OnConnected();
    void OnDisconnected();
    bool IsConnected() { return connected; }
};

#endif //
