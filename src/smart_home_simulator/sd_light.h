#ifndef SD_LIGHT_H
#define SD_LIGHT_H

#include "smart_device.h"

struct LightState {
    bool power_on;
    QColor color;

    // the line below (constructor) will make sure that the state is initialized when "LightState state" member of Light class is created
    LightState() : power_on(false), color(QColor(255, 247, 0)) {}
};

class Light : public SmartDevice
{
public:
    Light();
    virtual ~Light() override;

    void TurnOn();
    void TurnOff();
    void Toggle();
    void SetGlowColor(QColor c);
    void SetGlowOpacity(int opacity);
    QColor GetColor();

    //void PaintState(QPainter * painter, QRectF bounding_rect) override;

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

    virtual void SetSize(QPointF size) override;
private:
    LightState state;

    QGraphicsEllipseItem *glow_item;
    QGraphicsOpacityEffect *glow_opacity_effect;
    QRadialGradient *opacity_gradient;

    void InitGlowItem();
};

#endif // SD_LIGHT_H
