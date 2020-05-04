#include "smart_device.h"
#include "graphics_scene.h"
#include "sd_controlscreen.h"
#include "sd_radiator.h"
#include "sd_infra_red_sensor.h"

int SmartDevice::id_count = 0;

SmartDevice::SmartDevice()
    : GraphicsItem(ITEM_SMART_DEVICE)
{
    id = id_count++;
    //item = new GraphicsItem(ITEM_IMAGE);
    label_item = new QGraphicsTextItem();
    label_item->setFlag(QGraphicsItem::ItemIsMovable);

    qDebug() << "SmartDevice::SmartDevice()";

    setZValue(100.0);

    /*if (QGraphicsPixmapItem* pix_item = reinterpret_cast<QGraphicsPixmapItem *>(this))
        pix_item->setTransformationMode(Qt::SmoothTransformation);
    else
        qDebug()<< "if (QGraphicsPixmapItem* pix_item = reinterpret_cast<QGraphicsPixmapItem *>(this)) FAILED";*/

    uuid = QUuid::createUuid();
    UpdateTooltip(); // includes uuid and location
}

SmartDevice::~SmartDevice() {

}

QGraphicsTextItem *SmartDevice::GetTextLabelItem() {
    return label_item;
}

/*void SmartDevice::PaintState(QPainter *painter, QRectF bounding_rect) {

}*/

void SmartDevice::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    bool is_selected = option->state & QStyle::State_Selected;

    // DIRTY sd_controlscreen check...
    if (is_selected) GraphicsItem::SetPixmapColor(pixmap, SELECTED_COLOR);
    else GraphicsItem::SetPixmapColor(pixmap, Qt::black);

    painter->drawPixmap(0,0, pixmap);
    GraphicsItem::paint(painter, option, widget);
}

void SmartDevice::SetSize(QPointF sz) {
    pixmap = pixmap_highres.scaled(QSize(sz.x(), sz.y()));

    label_item->setFont(QFont(LABEL_FONT_NAME, sz.y()/5));
    QRectF r = boundingRect();
    QPointF label_pos = QPointF(r.right()/2 - label_item->boundingRect().right() / 2, r.bottom() + sz.y()/30);
    label_item->setPos(label_pos);
    label_item->setParentItem(this);


    if (Radiator * rad = dynamic_cast<Radiator *>(this)) {
        rad->InitStateText();
        rad->UpdateRangeIndicator();
    }

    if (InfraRedSensor *irs = dynamic_cast<InfraRedSensor *>(this))
        irs->InitStateText();

    scene_->update();
}

void SmartDevice::SetPixmap(QPixmap p) {
    pixmap_highres = p;
    pixmap = p;
}



void SmartDevice::SetLabelText(QString s) {
    qDebug() << "SmartDevice::SetLabelText, s = " << s << ", id = " << id;

    label_item->setPlainText(QString("%1 : %L2").arg(s).arg(id));
}



void SmartDevice::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    GraphicsItem::hoverEnterEvent(event);
}

void SmartDevice::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    GraphicsItem::hoverLeaveEvent(event);
}

void SmartDevice::keyPressEvent(QKeyEvent *event)
{
    GraphicsItem::keyPressEvent(event);
}

void SmartDevice::keyReleaseEvent(QKeyEvent *event)
{
    GraphicsItem::keyReleaseEvent(event);
}

void SmartDevice::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    GraphicsItem::mousePressEvent(event);
}

void SmartDevice::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    GraphicsItem::mouseMoveEvent(event);
}

void SmartDevice::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    UpdateTooltip();
    GraphicsItem::mouseReleaseEvent(event);
}

QVariant SmartDevice::itemChange(GraphicsItemChange change, const QVariant &value)
{
    //if (change == ItemPositionChange) {
        //this->setToolTip("UUID = " + uuid.toString() + "\nLocation: " + QString().sprintf("x=%.0f y=%.0f", scenePos().x(), scenePos().y()));
    //}
    return GraphicsItem::itemChange(change, value);
}

void SmartDevice::UpdateTooltip()
{
    this->setToolTip("UUID = " + uuid.toString() + "\nLocation: " + QString().sprintf("x=%.0f y=%.0f", scenePos().x(), scenePos().y()));
}
