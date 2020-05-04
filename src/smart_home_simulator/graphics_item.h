#ifndef GRAPHICS_ITEM_H
#define GRAPHICS_ITEM_H

#include <QtGui>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsEffect>
#include <QStyleOptionGraphicsItem>

//#include "smart_device.h"

#define ITEM_RECT       1
#define ITEM_ELLIPSE    2
#define ITEM_POLYGON    3
#define ITEM_SMART_DEVICE      4
#define ITEM_LINE       5

#define ITEM_FLAGS QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemSendsGeometryChanges


#define SELECTED_COLOR QColor(0, 74, 194, 50)
#define HOVER_PEN QPen(Qt::black, 2)

#define DEFAULT_ITEM_SIZE 200
#define DEFAULT_ITEM_PEN QPen(Qt::black, 1)
#define DEFAULT_ITEM_COLOR QColor(95, 255, 71, 20)
#define DOORS_ITEM_COLOR QColor(247, 228, 52, 30)


class GraphicsItem : public QGraphicsItem {
public:
    GraphicsItem(int type);
    virtual ~GraphicsItem() override;

    virtual QRectF boundingRect() const override;
    virtual QPainterPath shape() const override;
    virtual QPainterPath opaqueArea() const override;

    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void keyPressEvent(QKeyEvent * event) override;
    virtual void keyReleaseEvent(QKeyEvent *event) override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    // itemChange allows to implement snap to grid when moving items
    virtual QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;

    /* // Can be used to recognize something (e.g. list item) was dropped over the item:
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event) override; */

    void SetItemType(int id);
    int GetItemType();

    virtual void SetSize(QPointF size);

    void SetPolygon(QPolygon p);

    static void SetPixmapColor(QPixmap &p, QColor clr);

    bool ToggleDoors();
    bool IsDoors();

    void SetColor(QColor c);
protected:
    bool hovered;
    int item_type;
    int size_x, size_y;

    QPolygon polygon;

    bool is_doors;
    QColor color;

    void PaintSelectionDashedBoundingRect(QPainter * painter);
};

#endif
