#ifndef SD_POWERSOCKET_H
#define SD_POWERSOCKET_H

#include "smart_device.h"

struct PowerSocketState {
    bool is_on;

    PowerSocketState(): is_on(false) {}
};

class PowerSocket : public SmartDevice
{
public:
    PowerSocket();
    virtual ~PowerSocket() override;

    bool IsOn();
    void TurnOn();
    void TurnOff();
    void Toggle();

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

    virtual void SetSize(QPointF size) override;
private:
    PowerSocketState state;
    QGraphicsSimpleTextItem * state_text;

    void InitStateText(); // ON or OFF text above the image/pixmap
    void UpdateStateTextPos();
};

#endif // SD_POWERSOCKET_H
