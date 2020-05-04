# Team Implementation Report
> This section should describe the technical details of your implementation.  The subheadings and italicised text below may be used to guide you.  

# Table of contents
* [Technology used](#technology-used)  
* [Technical diagrams](#technical-diagrams)  
    * [Creator and its subclasses](#creator-and-its-subclasses)  
    * [QGraphicsItem and its subclasses](#qgraphicsitem-and-its-subclasses)  
* [Technical description](#technical-description)  
    * [Notable features that required some thought](#notable-features-that-required-some-thought)  
        * 1. Recognition of the smallest item under the mouse pointer  
        * 2. Collision and room change detection  
        * 3. Player movement  
    * [Coding style](#coding-style) 
* [Algorithms and Data Structures](#algorithms-and-data-structures)  
* [Imported Libraries](#imported-libraries)  
    * [Qt framework](qt-framework)  
    * [Zooming functionality](#zooming-functionality)  
    * [Kelvin to RGB conversion](#kelvin-to-rgb-conversion)  
 

## Technology used
Despite initial [notions to use Python or Java](https://cseejira.essex.ac.uk/browse/CE292T1902-38?focusedWorklogId=26744&page=com.atlassian.jira.plugin.system.issuetabpanels%3Aworklog-tabpanel#worklog-26744) 
we decided to use Qt framework. That's because it has immense number of features that make the development of GUI convenient. One such feature is the "drag and drop" based 
form editor which allows you to create, edit and configure GUI elements without any coding. In our project we used 4 different forms:  

![qt forms image](https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/qt_forms.png?raw=true)  

The interface of Qt Designer form editor (as shown below) consists of GUI elements list that can be added to the form (on the left side), form preview (in the center),
 hierarchy of elements in the current form (top-right), and configuration options of the currently selected GUI element (bottom-right).  

![qt overview image](https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/qt_overview.png?raw=true)  

Additionally, Qt allows to right-click a GUI element, choose "Go to slot", select desired slot (e.g. "click()") and it will automatically generate method/callback for it.  

![qt go to slot image](https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/qt_go_to_slot.png?raw=true)  

The code generated for the button on image above would be:  
```cpp
void MainWindow::on_pushButton_shapes_rect_clicked()
{
    
}
```

Aside from that, Qt has a powerful slot/signal system, however we scarcely used it because we didn't have much experience of using it in the past.  

## Technical Diagrams
> Include a class diagram / circuit diagram, and/or any other relevant technical diagrams.  

### Creator and its subclasses
![creators classes structure](https://raw.githubusercontent.com/michalmonday/files/master/ce292_team_project/images/MVP/Team%20project%20-%20Creators.png)

### QGraphicsItem and its subclasses
![qgraphicsitem derived classes structure](https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/Final%20Team%20project%20-%20QGraphicsItem%20derived%20tree%20.png?raw=true)

By looking at the file names we used, it can be noticed that each file containing smart device class is preceeded by "sd_". This way the smart device class files are grouped together in the Qt Designer and their purpose is clear.  

![file names image](https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/file_names.png?raw=true)  


## Technical Description
> This section should describe the software implementation in prose form.  Focus on how the code was designed and built.  
It should make a clear description that could be used by any future developers to maintain and extend your code, if necessary.  
Describe important functions / classes / class hierarchies.  
In this section, you should also wish to highlight any technical achievements your team is particularly proud of, including relevant code snippets.  

Especially during early stages of the development, we put a lot of effort into avoiding creating hard to read/extend code. 
That was documented on Jira in multiple issues 
([risk issue](https://cseejira.essex.ac.uk/browse/CE292T1902-37?focusedWorklogId=26740&page=com.atlassian.jira.plugin.system.issuetabpanels%3Aworklog-tabpanel#worklog-26740), 
[refactoring/cleanup task](https://cseejira.essex.ac.uk/browse/CE292T1902-14)) and it can be seen by looking at multiple gitlab commits 
([1](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/commit/1d81b1e6eef1c0ccbf8f7a2907be2ffa11504227), 
[2](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/commit/444769d2b2aae4347680192a14fd074017e9a07f), 
[3](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/commit/e61db53843b3284cddf4dfb3d80252dadd9e1486)). 
We understood that spending a few hours simplifying the code at early stage can save days of work at the later stages. 
If the code became polluted/disorganized quickly then implementing the more advanced features would not be possible. 

The [Technical Diagrams section](#technical-diagrams) shows what subclasses we created that were derived from the [QGraphicsItem](https://doc.qt.io/qt-5/qgraphicsitem.html) class. We used this object-oriented approach
to avoid creation of "type" variables (and the mess that usually accompanies such variables) as suggested by Martin Fowler in his "[Refactoring: Improving the Design of Existing Code](https://www.csie.ntu.edu.tw/~r95004/Refactoring_improving_the_design_of_existing_code.pdf)" book (p. 176-183).
"SmartDevice" class implementation allowed us to determine the behaviour which applies to all smart devices. Having a separate class (2 files) for each of the smart devices allowed 
us to create different kinds of features in a relatively clean, readable, organized way. That's partially due to the fact of using the object-oriented approach at all, 
and partially due to the fact that [QGraphicsItem](https://doc.qt.io/qt-5/qgraphicsitem.html) provides a great number of useful virtual methods/callbacks such as:
* void	contextMenuEvent( QGraphicsSceneContextMenuEvent *event)
* void	dragEnterEvent( QGraphicsSceneDragDropEvent *event)
* void	dragLeaveEvent( QGraphicsSceneDragDropEvent *event)
* void	dragMoveEvent( QGraphicsSceneDragDropEvent *event)
* void	dropEvent( QGraphicsSceneDragDropEvent *event)
* void	focusInEvent( QFocusEvent *event)
* void	focusOutEvent( QFocusEvent *event)
* void	hoverEnterEvent( QGraphicsSceneHoverEvent *event)
* void	hoverLeaveEvent( QGraphicsSceneHoverEvent *event)
* void	hoverMoveEvent( QGraphicsSceneHoverEvent *event)
* void	inputMethodEvent( QInputMethodEvent *event)
* QVariant	inputMethodQuery( Qt::InputMethodQuery query) const
* QVariant	itemChange( QGraphicsItem::GraphicsItemChange change, const QVariant &value)
* void	keyPressEvent( QKeyEvent *event)
* void	keyReleaseEvent( QKeyEvent *event)
* void	mouseDoubleClickEvent( QGraphicsSceneMouseEvent *event)
* void	mouseMoveEvent( QGraphicsSceneMouseEvent *event)
* void	mousePressEvent( QGraphicsSceneMouseEvent *event)
* void	mouseReleaseEvent( QGraphicsSceneMouseEvent *event)
* bool	sceneEvent( QEvent *event)
* bool	sceneEventFilter( QGraphicsItem *watched, QEvent *event)
* void	wheelEvent( QGraphicsSceneWheelEvent *event)

By looking on the example of Radiator class below we can see how some of these methods were inherited aside from some additional methods for this particular smart device type.    

![sd_radiator header file image](https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/sd_radiator%20header%20file.png?raw=true)


### Notable features that required some thought
**1. Recognition of the smallest item under the mouse pointer**   
There may be situations when a small item is obstructed by multiple larger items. If the user wanted to select the small element positioned behind the larger ones,
it would be necessary to move the larger ones away first. To avoid that, we implemented a check for the smallest item under the mouse cursor and automatically "push it to front" (by using "[setZValue](https://doc.qt.io/archives/qt-4.8/qgraphicsitem.html#setZValue)" method)  

![smallest item under cursor detection gif](https://raw.githubusercontent.com/michalmonday/files/master/ce292_team_project/images/MVP/smallest_element_under_cursor_detection.gif)  

Code responsible for it:  

```cpp
// part of graphics_scene.cpp file 

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{ 
    if (creator->mouseMoveEvent(event)) return;
    QGraphicsItem *smallest_item = nullptr;
    int smallest_shape_length = INT_MAX;

    for (auto & item : items()) {
        if (
            item->isUnderMouse() &&
            item->type() != 6 &&
            !qgraphicsitem_cast<QGraphicsEllipseItem*>(item) &&
            !qgraphicsitem_cast<QGraphicsItemGroup*>(item) &&
                (dynamic_cast<GraphicsItem *>(item) || dynamic_cast<QGraphicsLineItem *>(item) )
            )
        { 
            int shape_length = item->shape().length();
            if (shape_length < smallest_shape_length) {
                smallest_shape_length = shape_length;
                smallest_item = item;
            }
        }
    }

    if (smallest_item) {
        smallest_item->setZValue(1.0);
        smallest_item->update();
        if (smallest_item != hovered_item) {
            // attempt to prevent bug by additional dynamic cast check (hoping it will detect that the object is not available anymore for some reason
            if (dynamic_cast<GraphicsItem *>(hovered_item) || dynamic_cast<QGraphicsLineItem *>(hovered_item) ) {
                hovered_item->setZValue(0.1);
            }
            hovered_item = smallest_item;
        }
    }

    QGraphicsScene::mouseMoveEvent(event);
}
```

**2. Collision and room change detection**  
Without collision detection the player would be able to move through the walls of the building like a ghost. In order to prevent this we used the "[collidingItems](https://doc.qt.io/archives/qt-4.8/qgraphicsitem.html#collidingItems)" method inherited from QGraphicsItem class. To make it work properly it was necessary to recognize when the player is merely touching/intersecting with some item, and also when he is fully contained by some item (otherwise he would not be able to walk inside the building). Fortunately Qt provides easy way of getting both groups of items by supplying different parameter to the "collidingItems" method (Qt::ContainsItemShape, Qt::IntersectsItemShape). The result is shown on the animation below, the player cannot enter building unless he is touching the doors.  

![collision detection gif](https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/player%20movement%20-%20collision%20detection.gif?raw=true)  

Code responsible for it:  

```cpp
// part of actor.cpp file

/*  Function made to avoid being blocked by labels, smart devices, or smart device indicators.  */
int GetItemsToIgnoreCount(QList<QGraphicsItem*> items) {
    int count = 0;
    for (QGraphicsItem * item: items)
        if (dynamic_cast<QGraphicsTextItem *>(item) ||
            dynamic_cast<SmartDevice *>(item) ||
            dynamic_cast<QGraphicsSimpleTextItem *>(item) ||
            dynamic_cast<QGraphicsEllipseItem *>(item) ||
            dynamic_cast<QGraphicsPixmapItem *>(item) ||
            dynamic_cast<QGraphicsPathItem *>(item))
            count++;

    return count;
}

void Actor::Move() {
        /*  Irrelevant part is not included  */

        QList<QGraphicsItem *> containing_items = collidingItems(Qt::ContainsItemShape);
        QList<QGraphicsItem *> intersecting_items = collidingItems(Qt::IntersectsItemShape);

        // Subtract the items that should not affect the movement of the player (labels, smart devices, markers)
        int inter_sz = intersecting_items.size() - GetItemsToIgnoreCount(intersecting_items); 
        int cont_sz = containing_items.size() - GetItemsToIgnoreCount(containing_items);

        QGraphicsItem * current_containing_room = GetContainingRoomItem(containing_items);

        if (inter_sz && inter_sz != cont_sz && !IsCollidingWithDoors()) {
            is_moving = false;
            setPos(last_non_colliding_x, last_non_colliding_y);
        } else {
            last_non_colliding_x = x;
            last_non_colliding_y = y;
        }

        /* If player wasn't in the building previously and room contains him */
        if (inter_sz && inter_sz == cont_sz && !is_in_building) {
            is_in_building = true;
            containing_room = current_containing_room;
            onBuildingEntered(containing_room);
        }

        /* If player was previously in the building and doesn't collide with any rooms */
        if (is_in_building && !inter_sz) {
            is_in_building = false;

            onBuildingLeft(containing_room);
            containing_room = nullptr;
        }

        /* If player is in the building and the previously detected containing room is different from the currently detected containing room. */
        if (is_in_building && cont_sz > 0) {
            if (current_containing_room != containing_room) {
                //qDebug() << "changed room, old room = " << containing_room << ", new room = " << containing_items[0];
                onRoomLeft(containing_room);
                onRoomEntered(current_containing_room);

                containing_room = current_containing_room;
            }
        }
         
        /*  Irrelevant part is not included  */
}
```

**3. Player movement**  
It is worth to notice that the player is not always at the center of the screen. The player is allowed to move up to certain point of the screen without affecting the "camera", just like it is in many games (e.g. pokemon). Especially in the "UpdateViewport" method it can be seen that the calculation of the new "camera" position was not a trivial task.  

![player movement gif](https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/player%20movement.gif?raw=true)  

Code responsible for the player movement:  
```cpp
// part of actor.cpp file  

void Actor::Move() {
    //qDebug() << "Actor::Move, GetTickCount() = " << GetTickCount();
    bool is_moving = (mov_h || mov_v);
    qreal speed_mult = GetKeyState(VK_SHIFT) & ~1 ? SHIFT_SPEED_INCREASE : 1;

    qreal x = scenePos().x();
    qreal y = scenePos().y();
    if (mov_h)
        x += mov_h * speed * speed_mult;

    if (mov_v)
        y += mov_v * speed * speed_mult;

    if (!is_moving) {
        Stop();
    }
    else {        
        setPos(x, y);

        /*  Irrelevant part is not included  */

        /*  Walking animation  */
        if (GetTickCount() > last_leg_switch + LEG_SWITCH_INTERVAL / speed_mult) {
            last_leg_switch = GetTickCount();
            if (pixmap == &anim_pixmaps.left_up) pixmap = &anim_pixmaps.right_up;
            else pixmap = &anim_pixmaps.left_up;
            setPixmap(*pixmap);
        }

        if (pixmap == &anim_pixmaps.still) {
            pixmap = &anim_pixmaps.left_up;
            setPixmap(*pixmap);
            last_leg_switch = GetTickCount();
        }
        UpdateMarkerPos();
        UpdateViewport();
   }
}


void Actor::UpdateViewport() {
    QGraphicsView * v = scene_->GetVisibleView();
    QWidget* v_port = v->viewport();
    QPointF dude_screen_pos = v->mapFromScene( mapToScene(boundingRect().center()) );
    QPointF screen_center_scene_pos = v->mapToScene(v_port->rect().bottomRight()/2);
    int no_move_size_h = v_port->rect().width() / SCREEN_NO_MOVE_REGION_DIVIDER;
    int no_move_size_v = v_port->rect().height() / SCREEN_NO_MOVE_REGION_DIVIDER;
    QRectF move_zone = v_port->rect().marginsRemoved(QMargins(no_move_size_h,no_move_size_v,no_move_size_h,no_move_size_v));

    QPolygonF dude_screen_rect_p = v->mapFromScene( mapToScene(boundingRect()) );
    qreal l,r,t,b,  // move_zone rect
          d_l, d_r, d_t, d_b,  // dude rect
          h_diff = 0, v_diff = 0;  // how far dude exceeds the screen boundary

    // get dude rect
    d_l = dude_screen_rect_p[0].x();
    d_t = dude_screen_rect_p[0].y();
    d_r = dude_screen_rect_p[1].x();
    d_b = dude_screen_rect_p[2].y();
    move_zone.getCoords(&l,&t,&r,&b);

    // if dude is out of move zone horizontally
    if (d_l < l) h_diff = d_l - l;
    if (d_r > r) h_diff = d_r - r;
    if (d_t < t) v_diff = d_t - t;
    if (d_b > b) v_diff = d_b - b;

    if (h_diff || v_diff)
        v->centerOn(screen_center_scene_pos + QPointF(h_diff, v_diff));
}

void Actor::keyPressEvent(QKeyEvent *event)
{  
    switch(event->key()) {
        case Qt::Key_Left:  mov_h = -1; break;
        case Qt::Key_Right: mov_h = 1;  break;
        case Qt::Key_Up:    mov_v = -1; break;
        case Qt::Key_Down:  mov_v = 1;  break;
        default: QGraphicsPixmapItem::keyPressEvent(event);
    }
}

void Actor::keyReleaseEvent(QKeyEvent *event)
{
    switch(event->key()) {
        case Qt::Key_Left:  mov_h = mov_h == -1 ? 0 : mov_h; break;
        case Qt::Key_Right: mov_h = mov_h == 1  ? 0 : mov_h; break;
        case Qt::Key_Up:    mov_v = mov_v == -1 ? 0 : mov_v; break;
        case Qt::Key_Down:  mov_v = mov_v == 1  ? 0 : mov_v; break;
        default: QGraphicsPixmapItem::keyReleaseEvent(event);
    }
}
```

### Coding style  
When writing the code we put effort to avoid the common coding mistakes and adhere to the good practices suggested by R. Martin in his "[Clean Code](https://www.investigatii.md/uploads/resurse/Clean_Code.pdf) book. We tried to use meaningful, intention-revealing names. In general we used pronouncable names, with exceptions in cases where the meaning of not pronouncable variable names is intuitive (e.g. "clr" variable of QColor type). As mentioned in that book, the well written code should "explain itself" and should not include redundant comments (p. 55), which is a reason why the number of comments included in the code is relatively low. The majority of classes were built with consideration of good practices in terms of access specifiers (public, protected, private), not exposing the implementation unnecessarily, of which benefits are described on pages 93-95. The code is consistently indented and neatly (mostly) distributed in terms of vertical density.  


## Algorithms and Data Structures
> Describe datastructures of at least one component of your implementation.  
Describe at least one algorithm used in your implementation.  
In both cases, describe the space / time complexity of each.  

In terms of data structures we decided to stick as much as possible to the GUI objects/classes provided by Qt (this way the code was more concise and we could always refer to documentation of Qt to understand whenever the origin/purpose of some instruction was unknown). For example, we did not explicitly declare/define any collections objects (e.g. vector, list, map) for the sake of storing previously created graphic items or pixmaps. That would only unnecessarily complicate the code. Instead of doing so, we relied on the built-in (e.g. "[items](https://doc.qt.io/qt-5/qgraphicsscene.html#items)", 
"[selectedItems](https://doc.qt.io/qt-5/qgraphicsscene.html#selectedItems)") 
methods of [QGraphicsScene](https://doc.qt.io/qt-5/qgraphicsscene.html) class wherever it was needed. For example, the code below was used to toggle all of the selected "Light" smart devices.  

```cpp
void ControllerScreen::on_pushButton_toggleSelectedLights_clicked()
{
    for (auto &item : scene_->selectedItems()) {
    
        /* dynamic_cast is checking if the "item" is "Light" object, 
           and assigning pointer to it if true (otherwise it sets light to 0, 
           resulting in "if" condition evaluating to false)  */
        if (Light* light = dynamic_cast<Light*>(item)) {
            light->Toggle();
        }
    }
}
```

In some cases "manually" keeping the reference to previously created objects was unavoidable (or would have more drawbacks than benefits). 
Example of such, can be noticed in the tutorial.cpp file where we stored file names and descriptions of slides in a [QList](https://doc.qt.io/qt-5/qlist.html) containing pairs (2 strings each). 
```cpp
// part of tutorial.cpp file

static QList<QPair<QString, QString>> slides = {
    {"first_slide.gif", "First slide description"},            // first_slide.gif must be located in: resources/tutorial/
    {"second_slide.gif", "Second slide description"}
};
```

The only exception where we used collections object to store previously created graphical items was in the PolygonCreator class where we stored [QGraphicsLineItem](https://doc.qt.io/archives/qt-4.8/qgraphicslineitem.html) pointers in a [QVector](https://doc.qt.io/qt-5/qvector.html) called "preview_lines".  

```cpp
// part of polygon_creator.cpp file 

bool PolygonCreator::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    /*  Irrelevant parts are not included  */

    /*  Update the position of the new line that will be created.  */
    if (polygon.count()) {
        QLineF l = preview_lines.last()->line();
        l.setP1(grid->GetClosestPoint(cursor_pos));
        preview_lines.last()->setLine(l);
    }

    /*  If the polygon is about to be created, show the preview of how it will look like (before actually creating it).  */
    if (polygon.count() > 2 && polygon.indexOf(position_preview_ellipse->scenePos().toPoint()) == 0) {
        if (!polygon_on_last_point_preview->isVisible()) {
        
            /*  Irrelevant parts are not included  */
            
            for (auto & line : preview_lines){
                QPen p = line->pen();
                p.setColor(LINES_ON_LAST_POINT_PREVIEW_COLOR);
                line->setPen(p);
            }
        }
    }
    else if (polygon_on_last_point_preview->isVisible()) {
        polygon_on_last_point_preview->setVisible(false);
        for (auto & line : preview_lines) {
            QPen p = line->pen();
            p.setColor(PREVIEW_LINES_COLOR);
            line->setPen(p);
        }
    }
    return false;
}


bool PolygonCreator::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        QPointF new_point = grid->GetClosestPoint(event->scenePos());
        QGraphicsLineItem *line = new QGraphicsLineItem(QLineF(polygon.count() ? polygon.last() : new_point, new_point));
        QPen line_pen(PREVIEW_LINES_COLOR, PREVIEW_LINES_WIDTH, Qt::DashLine);
        line_pen.setCosmetic(true);
        line->setPen(line_pen);
        preview_lines.push_back(line);
        scene_->addItem(line);

        /*  Irrelevant parts are not included  */
    }

    if (event->button() == Qt::RightButton) {

            /*  Irrelevant parts are not included  */
        
            scene_->removeItem(preview_lines.last());
            preview_lines.removeLast();
            
            /*  Irrelevant parts are not included  */
    }
    return true;
}
```

We used few relatively simple algorithms in the project. Two of them were already presented in the "[Notable features](#notable-features-that-required-some-thought)" section (smallest item under cursor detection, player movement). Example of another one is presented below, it was responsible for conversion of Kelvin to RGB values based on the current simulated time in relation to the time/kelvin values collected from the "[Several biological benefits of the low color temperature light-emitting diodes based normal indoor lighting source](https://www.nature.com/articles/s41598-019-43864-6)" article by Lin, J., Ding, X., Hong, C. et al.   

The "GetColourForDayTime" method first loops over all of the collected values, trying to find:  
1. The latest time of the day (collected from the article) that is earlier than the supplied time.  
2. The earliest time of the day (collected from the article) that is later than the supplied time.  

Then it interpolates supplied time from the range of 2 nearest time points, into the range of Kelvin values corresponding to these 2 nearest time points.  

```cpp
// part of sun_colour.cpp file  

QColor SunColour::GetColourForDayTime(const QTime &time, int brightness)
{
    if (time < MIN_TIME || time > MAX_TIME)
        return KelvinToQColor(1900, brightness);

    QTime time_under, time_over;
    int temp_under, temp_over;
    for (auto &p : m) {
        if (p.first <= time) {
            time_under = p.first;
            temp_under = p.second;
        }

        if (p.first > time) {
            time_over = p.first;
            temp_over = p.second;
            break;
        }
    }

    int interpolated_kelvin = map(
                time.msecsSinceStartOfDay()/1000,
                time_under.msecsSinceStartOfDay()/1000,
                time_over.msecsSinceStartOfDay()/1000,
                temp_under,
                temp_over);
    
    // KelvinToQColor was adapted from: https://github.com/timvw74/Kelvin2RGB/blob/master/Kelvin2RGB.h
    return KelvinToQColor(interpolated_kelvin, brightness); 
}
```


## Imported Libraries 
> List any 3rd party libraries that were used and describe what functionality they provided.  

### Qt framework   

Qt framework itself could be classified as 3rd party library, as described in the "[Technology used](#technology-used)" section, it includes toolkit for development of GUI but it also has a set of comprehensive C++ libraries/classes which we utilized in this project. Aside from the GUI elements like buttons, combo boxes, layouts, time/date editors, we used the Qt classes provided for drawing of custom graphical items, these classes are:  
* [QGraphicsView](https://doc.qt.io/qt-5/qgraphicsview.html) GUI component  
* [QGraphicsScene](https://doc.qt.io/qt-5/qgraphicsscene.html) class from which we derived "GraphicsScene" class (graphics_scene.h/.cpp)  
  That is where we implemented recognition of the smallest item under mouse pointer (mouseMoveEvent), that is also where we implemented deletion of items on "delete" keystroke (keyReleaseEvent) and smart device resizing upon "plus/minus" keystroke (also keyReleaseEvent).  
* [QGraphicsItem](https://doc.qt.io/qt-5/qgraphicsitem.html) class from which we derived "GraphicsItem", "SmartDevice" and numerous sub-classes smart devices. We used variety of methods provided by QGraphicsItem interface to create responsive designer and simulation modes.      

### Zooming functionality  

As mentioned in the comments at the top of Zoom.h and Zoom.cpp files, the code responsible for zooming functionality (zoom.h/.cpp) was copied from the [example](https://stackoverflow.com/a/19114517/4620679) posted by [Pavel Strakhov](https://stackoverflow.com/users/344347/pavel-strakhov).

```cpp
// mainwindow.cpp file

#include "zoom.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
/* ... */
    Zoom* z = new Zoom(ui->graphicsView);
    z->set_modifiers(Qt::ControlModifier);
/* ... */
}
```

```cpp
// zoom.h and zoom.cpp files

/*
Copied from https://stackoverflow.com/a/19114517/4620679
Author: Pavel Strakhov - https://stackoverflow.com/users/344347/pavel-strakhov
*/
```

![zoom_gif](https://raw.githubusercontent.com/michalmonday/files/master/ce292_team_project/images/MVP/zoom.gif)


### Kelvin to RGB conversion  
 The functions responsible for Kelvin to RGB conversion were copied/adapted from [Kelvin2RGB repository](https://github.com/timvw74/Kelvin2RGB) by Tim van Wijk ([timvw74](https://github.com/timvw74))

## Known Issues
> List any known issues (bugs) in your software, and describe workarounds if they exist.  
