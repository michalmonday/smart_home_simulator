#ifndef SD_INFRA_RED_SENSOR
#define SD_INFRA_RED_SENSOR

#include "smart_device.h"

class InfraRedSensor : public SmartDevice
{
public:
    InfraRedSensor();
    virtual ~InfraRedSensor() override;

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

    void InitStateText();
    void UpdateStateTextPos();
    void SetPresenceDetected(bool state);
private:
    bool presence_detected;
    QGraphicsSimpleTextItem * state_text;
};

#endif //
