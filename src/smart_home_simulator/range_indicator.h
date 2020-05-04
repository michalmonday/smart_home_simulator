#ifndef RANGE_INDICATOR_H
#define RANGE_INDICATOR_H

#include "graphics_item.h"

#include <QGraphicsEllipseItem>

class RangeIndicator : public QGraphicsEllipseItem
{
    // QGraphicsItem interface
public:
    RangeIndicator();
    RangeIndicator(GraphicsItem * parent);
    virtual ~RangeIndicator() override {}

protected:
    virtual void dropEvent(QGraphicsSceneDragDropEvent *event) override;
};

#endif // RANGE_INDICATOR_H
