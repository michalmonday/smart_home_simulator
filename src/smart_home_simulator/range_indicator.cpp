#include "range_indicator.h"
#include <QDebug>

RangeIndicator::RangeIndicator() : RangeIndicator(nullptr) {}

RangeIndicator::RangeIndicator(GraphicsItem * parent) : QGraphicsEllipseItem(parent)
{
    setFlag(ItemSendsGeometryChanges);
}

void RangeIndicator::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    qDebug() << "RangeIndicator::dropEvent";
}
