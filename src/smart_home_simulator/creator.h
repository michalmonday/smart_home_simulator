#ifndef CREATOR_H
#define CREATOR_H

#include "graphics_scene.h"

class Creator
{
public:
    Creator();
    virtual ~Creator();

    /* Why these are bools instead of void?
       return false; // QGraphicsScene's original callback precesses the event normally
       return true;  // blocks QGraphicsScene original behaviour (blocks the event from reaching it)  */
    virtual bool mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual bool mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual bool mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    virtual bool keyPressEvent(QKeyEvent * event);
    virtual bool keyReleaseEvent(QKeyEvent * event);
};

extern Creator *creator;
extern Creator *base_idle_creator;

extern void SetCreator(Creator *c);

#endif // CREATOR_H
