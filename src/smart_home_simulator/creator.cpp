#include "creator.h"
#include "polygon_creator.h"
#include "press_and_drag_creator.h"
#include "smart_device_creator.h"
#include "mainwindow.h"

// Currently used creator (e.g. polygon_creator / press_and_drag_creator / smart_device_creator)
Creator *creator;

/* base_idle_creator is supposed to be set as currently used creator when user escapes using any particular one
(e.g. when pressing escape after adding rectangle)
Behaviour of base_idle_creator is defined in this file
*/
Creator *base_idle_creator = nullptr;


void SetCreator(Creator * c) {
    /* Instead of this function we could use for example:
       creator = polygon_creator;

       But this function allows to clean up what's necessary in the last creator
    */

    // check based on the last creator (for cleanup)
    if (creator && creator == polygon_creator)
        polygon_creator->HidePositionPreviewEllipse();

    if (creator && base_idle_creator && c == base_idle_creator) {
        smart_device_buttons->setExclusive(false);
        for (QAbstractButton *btn : smart_device_buttons->buttons())
            if (btn->isChecked())
                btn->setChecked(false);
        smart_device_buttons->setExclusive(true);

        shapes_buttons->setExclusive(false);
        for (QAbstractButton *btn : shapes_buttons->buttons())
            if (btn->isChecked())
                btn->setChecked(false);
        shapes_buttons->setExclusive(true);

    }

    creator = c;

    scene_->setBackgroundBrush(Qt::white);
    // checks based on the new creator (to display messages on status bar)
    if      (c == polygon_creator)        { StatusBarMsg("Polygon creator - LMB to create point, RMB to erase last point (or exit mode if it's 1st point)"); }
    else if (c == press_and_drag_creator) { StatusBarMsg("Press and drag creator - LMB to draw the shape, RMB to exit the mode."); }
    else if (c == smart_device_creator)   { StatusBarMsg("Smart device creator - LMB to create, RMB to exit the mode."); }
    else {
        StatusBarMsg("IDLE - no creator selected");
        scene_->setBackgroundBrush(QColor(245, 245, 245));
    }


    //scene->setFocus();
    pMainWindow->ui->graphicsView->setFocus();
}



Creator::Creator() {

}

Creator::~Creator() {

}

bool Creator::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    return false;
}

bool Creator::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    return false;
}

bool Creator::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    return false;
}

bool Creator::keyPressEvent(QKeyEvent * event) {
    return false;
}

bool Creator::keyReleaseEvent(QKeyEvent * event) {
    return false;
}
