#ifndef SMART_DEVICE_H
#define SMART_DEVICE_H

#include <QtCore>
#include <QGraphicsTextItem>
#include <QUuid>

#include "graphics_item.h"

#define SD_CONTROL_SCREEN   1
#define SD_DOORBELL         2
#define SD_LIGHT            3
#define SD_POWERSOCKET      4

#define LABEL_FONT_NAME "Lucida Console"
#define SD_FONT_SIZE_DIVIDER 5 // font size = max(width, height) / 5

class SmartDevice : public GraphicsItem
{
public:
    SmartDevice();
    virtual ~SmartDevice() override;

    QGraphicsTextItem *GetTextLabelItem();
    virtual void SetSize(QPointF size) override;
    void SetPixmap(QPixmap p);

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

    QSize GetPixmapSize() const { return pixmap.size(); }
    void UpdateTooltip();
protected:  
    static int id_count;
    int id;
    QGraphicsTextItem *label_item;
    QPixmap pixmap, pixmap_highres;

    QUuid uuid;

    void SetLabelText(QString s);
};

#endif // SMART_DEVICE_H
