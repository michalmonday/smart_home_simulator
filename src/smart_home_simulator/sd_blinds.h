#ifndef SD_BLINDS_H
#define SD_BLINDS_H

#include "smart_device.h"


class Blinds : public SmartDevice
{
public:
    Blinds();
    virtual ~Blinds() override;

    bool IsOpen();
    void Open();
    void Close();
    void Toggle();

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

    //static void UpdateAllFans(); // could be implemented if range indicators are used
    static void OpenAll();
    static void CloseAll();
private:
    bool is_open;
    QGraphicsSimpleTextItem * state_text;

    void InitStateText(); // ON or OFF text above the image/pixmap
    void UpdateStateTextPos();
};

#endif // SD_FAN_H
