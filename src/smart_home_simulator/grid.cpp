#include "grid.h"
#include "graphics_scene.h"

Grid *grid = new Grid();



Grid::Grid() {
    granularity = GRID_GRANULARITY;
    lines_group = new QGraphicsItemGroup();;
}

Grid::~Grid(){
    delete lines_group;
}

void Grid::Set(int granularity_, int size, QColor color) {
    size *= granularity_;
    granularity = granularity_;

    if (is_set)
        Clear();

    // adjust size so there's line cross exactly at the 0,0 coordinates
    size += (granularity_ - size % granularity_);

    for (int pos = 0; pos <= size; pos +=granularity){               
        QGraphicsLineItem * v_line = new QGraphicsLineItem(pos, 0, pos, size, lines_group); //scene_->addLine(pos, 0, pos, size, QPen(color));

        v_line->setZValue(-100.0);
        //vert_lines.push_back( v_line );

        QGraphicsLineItem * h_line = new QGraphicsLineItem(0, pos, size, pos, lines_group); //scene_->addLine(0, pos, size, pos, QPen(color));
        h_line->setZValue(-100.0);
        //hor_lines.push_back( h_line );

        v_line->setPen(QPen(color));
        h_line->setPen(QPen(color));
        lines_group->addToGroup(v_line);
        lines_group->addToGroup(h_line);
        lines_group->setZValue(-100.0);
        }

    scene_->addItem(lines_group);

    is_set = true;
}

void Grid::Clear(){
    is_set = false;
    //MainWindow *w = MainWindow::getMainWinPtr();

    /*
    for (QGraphicsLineItem* line : vert_lines)
        scene_->removeItem(line);

    for (QGraphicsLineItem* line : hor_lines)
        scene_->removeItem(line);
    */

    if (lines_group) delete lines_group;
    lines_group = new QGraphicsItemGroup();
}


int Grid::GetGranularity() {
    return granularity;
}

QPointF Grid::GetClosestPoint(QPointF pos) {
    int g = (int)granularity;
    int x = (((int)pos.x() + g / 2) / g) * g;
    int y = (((int)pos.y() + g / 2) / g) * g;

    return QPointF(x, y);
    // https://stackoverflow.com/questions/29557459/round-to-nearest-multiple-of-a-number
}


double Grid::RoundToGranularity(double val, const char * inclination) {
    int granularity = grid->GetGranularity();
    double remainder = (double)((int)val % granularity);
    if ((strcmp(inclination, "ceil") == 0 || fabs(remainder) > (granularity / 2.0)) && strcmp(inclination, "floor") != 0) {
        return (double)(int)(val + granularity - remainder);
    }
    return (double)(int)(val - remainder);

}

QPointF Grid::RoundToGranularity(QPointF val, const char * inclination) {
    double x = RoundToGranularity(val.x(), inclination);
    double y = RoundToGranularity(val.y(), inclination);
    return QPointF(x, y);
}

