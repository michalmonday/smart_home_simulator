#ifndef GRID_H
#define GRID_H

#include "mainwindow.h"
#include <vector>

#include <QGraphicsLineItem>

#define GRID_SIZE 500
#define GRID_GRANULARITY 20
#define GRID_COLOR QColor(230,230,230)

class Grid
{
public:
    Grid();
    ~Grid();

    void Set(int granularity, int size, QColor color);
    void Clear();

    int GetGranularity();

    QPointF GetClosestPoint(QPointF pos);

    double RoundToGranularity(double val, const char * inclination);
    QPointF RoundToGranularity(QPointF val, const char * inclination);

private:
    QGraphicsItemGroup *lines_group;

    std::vector<QGraphicsLineItem*> hor_lines, vert_lines;
    bool is_set;
    int granularity;
    QColor color;
};

extern Grid *grid;

#endif // GRID_H
