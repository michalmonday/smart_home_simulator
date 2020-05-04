#ifndef SMART_DEVICE_CREATOR_H
#define SMART_DEVICE_CREATOR_H

#include "graphics_item.h"
#include "creator.h"
#include "smart_device.h"

#include <QtCore>
#include <QAbstractButton>





class SmartDeviceCreator : public Creator
{
public:
    SmartDeviceCreator();
    ~SmartDeviceCreator() override;

    bool mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    bool mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    bool mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    bool keyPressEvent(QKeyEvent * event) override;
    bool keyReleaseEvent(QKeyEvent * event) override;

    void SetPixmap(QPixmap p);
    void SetDeviceType(QAbstractButton *button);
private:
    QAbstractButton* device_button;
    QPixmap pixmap;

    SmartDevice * CreateDevice();
};

extern SmartDeviceCreator *smart_device_creator;

#endif // SMART_DEVICE_CREATOR_H
