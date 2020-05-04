#ifndef SD_CONTROLSCREEN_H
#define SD_CONTROLSCREEN_H

#include "smart_device.h"



//struct ControlScreenState {
//    //bool visible_to_user;

//    // the line below (constructor) will make sure that the state is initialized when "LightState state" member of Light class is created
//    //ControlScreenState() : visible_to_user(false) {}
//};


class ControlScreen : public SmartDevice
{
public:
    ControlScreen();
    virtual ~ControlScreen() override;

    void SetVisibleToUser(bool is_visible);
    bool IsVisibleToUser();

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
    //ControlScreenState state;
   // QGraphicsSimpleTextItem * click_me_text;

   // void InitClickToOpenText();
};

#endif // SD_CONTROLSCREEN_H
