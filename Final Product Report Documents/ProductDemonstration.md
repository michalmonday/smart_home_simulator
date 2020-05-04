# Product Demonstration Report
This demonstration report builds upon the minimum viable product (MVP) [Demonstration.md](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/blob/master/MVP/Demonstration.md) file which demonstrated the functionality at an early stage. 

# List of contents:  
* [Overview](#overview) 
    * [Design mode overview](#design-mode-overview)  
    * [Simulation mode overview](#simulation-mode-overview)  
* [Fundamental features implemented up to MVP](#fundamental-features-implemented-up-to-mvp)  
    * [Resizable window image](#resizable-window-image)
    * [Grid](#grid)
    * [Shapes creation](#shapes-creation)
    * [Snap to grid while moving shapes](#snap-to-grid-while-moving-shapes)
    * [Select move and delete multiple shapes](#select-move-and-delete-multiple-shapes)
    * [Opaque area detection](#opaque-area-detection)
    * [Detect the smallest shape under cursor](#detect-the-smallest-shape-under-the-cursor)
    * [Status info bar](#status-info-bar)
    * [Zoom](#zoom)
    * [Placing smart devices](#placing-smart-devices)
    * [Actor selection and movement](#actor-selection-and-movement)
* [Smart devices](#smart-devices)  
    * [Doorbell](#doorbell)  
    * [Light](#light)  
    * [Power socket](#power-socket)  
    * [Radiator](#radiator)  
    * [Fan](#fan)  
    * [Thermometer](#thermometer)  
    * [Infra red sensor](#infra-red-sensor)  
    * [Toilet](#toilet)  
    * [Blinds](#blinds)  
    * [Control screen](#control-screen)  
* [Additional features](#additional-features)  
    * [Responsive weather area](#responsive-weather-area)  
    * [Convenient window placement](#convenient-window-placement)  
    * [Song alarms](#song-alarms)  
    * [UUID and location](uuid-and-location)  
* [Summary](#summary)  


# Overview
As described in the project outline document, the program should have "design" and "simulation" modes. Up until the "MVP", we focused mainly on "design" mode. Then we shifted our focus on the simulation mode, including gradual expansion of smart device variety and ways of interacting with these devices. We also managed to get rid of memory management based bugs, resulting in a stable product. 

![overview image](https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/overview.png?raw=true)  

### Design mode overview  
In the design mode the user is able to draw different kinds of shapes (rectangles, ellipses, polygons, lines) to represent rooms, doors and walls. The user can also place various smart devices.  

![shape - smart device selection gif](https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/shapes%20-%20smart%20device%20selection.gif?raw=true)

Especially in the early stages of development we put a lot of effort to make the design mode convenient in use, for example by implementing:  
* recognition of the smallest item under the cursor (to avoid the necessity of moving away large shapes when trying to select small shapes obstructed by multiple larger ones)  
* ability to undo the previous point during polygon creation by right-clicking  
* several features to create a responsive feel of the design mode (opaque area detection, pen size change on hover, colour change on selection, preview of polygon when mouse hovers over the first point)  
* "snap-to-grid" feature (enhancing precision of the user, allowing creation of symetrical designs, preventing them from creating inconsistent-unaesthetic designs)

These features were documented in the [Demonstration.md](https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/blob/master/MVP/Demonstration.md) created for MVP.  

### Simulation mode overview
In the simulation mode, the user can control a player, walk around the created architetural design and interact with devices. Once entering the "simulation" mode, the "Environment" window is created which shows the current time, date, day of a week as well as weather (temperature and type). The simulated time speed can be increased, decreased (or completely frozen) by the user. The simulated weather can be set directly, it can also be set to be automatically randomized as the simulated time passes. These features allow several smart devices to implement simple rulesets based on time of the day and temperature.    

![environment window image](https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/environment_window_simulated.gif?raw=true)

What is affected by simulated time passing:  
* weather (if the "Randomize" checkbox is checked)  
* song alarm feature (which plays a selected mp3 file at a specified time)  
* blinds smart device (optional auto open/close at a specified time)  
* light smart device (optional "mimic sun colour" feature which adjusts colour temperature of the light to match natural colour temperature of the sun during the day)  

What is affected by simulated temperature:  
* radiators (auto turn on when the temperature drops below 10 degrees)  
* fans (auto turn on when temperature rises over 20 degrees)  

Another important feature provided in the simulation mode is the "Control screen" window that can be opened when the player approaches the control screen smart device.  

![control screen window image](https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/control%20screen.png?raw=true)  

\
\
\
\
\
\
\
\
\
# Fundamental features implemented up to MVP

### Resizable window image

The "QGraphicsView" element inside the window scales nicely as the window is resized.  

![resizble_window_gif](https://raw.githubusercontent.com/michalmonday/files/master/ce292_team_project/images/MVP/resizable_window.gif)  


### Grid

The grid can be toggled from the menu. Graphical items snap to grid when they're created or moved, which can be seen on the few gifs below.  

It is possible that the implementation of grid will change in future, in the current state it crates a large number of graphic items, which makes looping over all items inefficient. A few different resources were accessed trying to find an optimal solution:    
[qtcentre - Drawing grids efficiently in QGraphicsScene](https://www.qtcentre.org/threads/5609-Drawing-grids-efficiently-in-QGraphicsScene)   
[stackoverflow - Efficient Grid in Qt](https://stackoverflow.com/questions/12569578/efficient-grid-in-qt)  
[Draw Grid on QGraphicsScene](http://tufangorel.blogspot.com/2011/08/draw-grid-on-qgraphicsscene.html)  

In the end we decided to automatically clear the grid when simulation mode is entered (because that's where the performance issues could occur). The grid reappears when design mode is entered again.    

```cpp
// grid.h file

#define GRID_SIZE 500
#define GRID_GRANULARITY 20
#define GRID_COLOR QColor(230,230,230)
```

```cpp
// grid.cpp file

void Grid::Set(int granularity_, int size, QColor color) {
/*
 ... contents of the Set method
*/
}

void Grid::Clear(){
    is_set = false;
    if (lines_group) delete lines_group;
    lines_group = new QGraphicsItemGroup();
}

```

![grid_gif](https://raw.githubusercontent.com/michalmonday/files/master/ce292_team_project/images/MVP/grid_set_clear.gif)


### Shapes creation

The 3 main shapes can be selected:  
* rectangle  
* ellipse  
* polygon  

Following the MVP we also added ability to draw a line (not shown on the animation below).  

Once the shape is selected from the panel on the left the program enters either:  
* **press_and_drag_creator** mode (for rectangle, ellipse and line)  
* **polygon_creator** mode   

Both of these modes allow the convenient creation of the desired shape.  
When any of these modes is entered, the background changes colour to plain white.  
When any of these modes is exited (by pressing the escape key or RMB), the background changes colour to slightly gray.  

![shapes_cretion_gif](https://raw.githubusercontent.com/michalmonday/files/master/ce292_team_project/images/MVP/shapes_creation.gif)


### Snapping to the grid while moving shapes

When a graphic item is moved it automatically snaps to the grid.  
The code below shows how it's implemented (by overriding "itemChange" method of QGraphicsItem). Modular design allows the code to be relatively simple. The "GetClosestPoint" method is contained by the Grid class, and can be used wherever it's needed in the project.  

```cpp
// graphics_item.cpp file

QVariant GraphicsItem::itemChange(GraphicsItemChange change, const QVariant &value) {
    if (change == ItemPositionChange && scene()) {
        return grid->GetClosestPoint(value.toPointF());
    }
    return QGraphicsItem::itemChange(change, value);
}
```


```cpp
// grid.cpp file

QPointF Grid::GetClosestPoint(QPointF pos) {
    int g = (int)granularity;
    int x = (((int)pos.x() + g / 2) / g) * g;
    int y = (((int)pos.y() + g / 2) / g) * g;

    return QPointF(x, y);
    // https://stackoverflow.com/questions/29557459/round-to-nearest-multiple-of-a-number
}
```

![snap_to_grid_while_moving_shapes_gif](https://raw.githubusercontent.com/michalmonday/files/master/ce292_team_project/images/MVP/snap_to_grid_on_move.gif)


### Select move and delete multiple shapes

Multiple items can be selected and can be moved at the same time or deleted them by pressing the "del" key. It can be noticed that different effects are applied to the shapes when they're selected, or hovered over.  

The ability to select and move items is achieved by setting flags of the QGraphicsItem object.

```cpp
// graphics_item.h file

#define ITEM_FLAGS QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemSendsGeometryChanges
```

```cpp
// graphics_item.cpp file

GraphicsItem::GraphicsItem(int type) {
/* ... */
    setFlags(ITEM_FLAGS);
/* ... */
}
```

Effects on hover/select are accomplished by overriding the "paint" method of QGraphicsItem.  

```cpp
// graphics_item.h file

#define SELECTED_PEN QPen(Qt::black, 1)
#define SELECTED_COLOR QColor(0, 74, 194, 50)
#define HOVER_PEN QPen(Qt::black, 2)
```

```cpp
// graphics_item.cpp file

void GraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
/* ... */
    bool is_selected = option->state & QStyle::State_Selected;
    if (is_selected && creator == base_idle_creator) {
        pen_ = SELECTED_PEN;
        brush_ = SELECTED_COLOR;
    } else {
        pen_ = DEFAULT_ITEM_PEN;
        brush_ = DEFAULT_ITEM_COLOR;
    }

    if (hovered && creator == base_idle_creator) {
        pen_ = HOVER_PEN;
        PaintSelectionDashedBoundingRect(painter); // could be replaced with QRubberBand (but it's alright)
    }

    pen_.setCosmetic(true); // makes it consistent regardless of zoom (otherwise it would be barely visible when zoomed-out)
    painter->setPen(pen_);
    painter->setBrush(brush_);
/* ... */
```

![select_move_and_delete_multiple_shapes_gif](https://raw.githubusercontent.com/michalmonday/files/master/ce292_team_project/images/MVP/select_move_delete_multiple_items.gif)


### Opaque area detection

The program recognizes when the user moves the mouse over the opaque area of a shape (instead of relying on the bounding rectangle of the shape).
It's accomplished by overriding the "shape" method of QGraphicsItem

```cpp
// graphics_item.cpp file

QPainterPath GraphicsItem::shape() const
{
    if (item_type == ITEM_POLYGON) {
        QPainterPath path;
        path.addPolygon(polygon);
        return path;
    }

    if (item_type == ITEM_ELLIPSE) {
        QPainterPath path;
        path.addEllipse(boundingRect());
        return path;
    }
    return QGraphicsItem::shape();
}
```

![opaque_area_detection_gif](https://raw.githubusercontent.com/michalmonday/files/master/ce292_team_project/images/MVP/response_on_opaque_area.gif)


### Detect the smallest shape under the cursor

During program operation and design process, it may happen that there are multiple items on top of each other. In order to make the usage comfortable, the program detects the smallest item under the cursor and automatically adjusts its "Z value" (which gives it priority to be selected when LMB is clicked). The "on hover" effect allows you to see it, as shown on the gif below.  
It's implemented in the "GraphicsScene::mouseMoveEvent" callback where the smallest item under the cursor is assigned higher than the normal "Z Value". That value is getting reset to normal once the new smallest item is found.

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

![detect_smallest_shape_under_cursor_gif](https://raw.githubusercontent.com/michalmonday/files/master/ce292_team_project/images/MVP/smallest_element_under_cursor_detection.gif)


### Status info bar

The status info bar at the bottom of the window informs the user about the current state of the app and the behaviour of keys/buttons.  
It displays the current "creator" state.  

```cpp
// mainwindow.cpp file

/* Auxliary function to avoid using long chain of pointers */
void StatusBarMsg(const char * msg) {
    if (pMainWindow)
        pMainWindow->ui->statusBar->showMessage(msg);
}
```

```cpp
// mainwindow.h file

extern void StatusBarMsg(const char * msg);
```

```cpp
// creator.cpp file

void SetCreator(Creator * c) {
/* ... */
    if      (c == polygon_creator)        { StatusBarMsg("Polygon creator - LMB to create point, RMB to erase last point (or exit mode if it's 1st point)"); }
    else if (c == press_and_drag_creator) { StatusBarMsg("Press and drag creator - LMB to draw the shape, RMB to exit the mode."); }
    else if (c == smart_device_creator)   { StatusBarMsg("Smart device creator - LMB to create, RMB to exit the mode."); }
    else {
        StatusBarMsg("IDLE - no creator selected");
        scene_->setBackgroundBrush(QColor(245, 245, 245));
    }
/* ... */
}
``` 

![status_info_bar_gif](https://raw.githubusercontent.com/michalmonday/files/master/ce292_team_project/images/MVP/status_info_bar.gif)


### Zoom

As mentioned in the comments at the top of Zoom.h and Zoom.cpp files, the code responsible for zooming functionality was copied from the [example](https://stackoverflow.com/a/19114517/4620679) posted by [Pavel Strakhov](https://stackoverflow.com/users/344347/pavel-strakhov).

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


### Placing smart devices

The buttons on the left panel are inconsistent with the list of shapes in the "Shapes" tab. This may change in the final version of the program.  

![placing_smart_devices](https://raw.githubusercontent.com/michalmonday/files/master/ce292_team_project/images/MVP/placing_smart_devices.gif)


### Actor selection and movement

When the user moves the mouse over the actor, a marker with decreased opacity is displayed under the actor, creating a sense of responsiveness (hoverEnter / hoverExit events).
When the actor is clicked, the opacity is set to a higher value and the actor can be moved (focusIn / focustOut events). 

```cpp
// actor.cpp file

void Actor::focusInEvent(QFocusEvent *event)
{
    qDebug() << "Actor::focusInEvent";
    if (marker) {
        marker->setOpacity(1);
        marker->setVisible(true);
    }
    QGraphicsPixmapItem::focusInEvent(event);
}

void Actor::focusOutEvent(QFocusEvent *event)
{
    qDebug() << "Actor::focusOutEvent";
    if (marker) {
        marker->setVisible(false);
    }
    QGraphicsPixmapItem::focusOutEvent(event);
}

/* ... */

void Actor::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    if (marker && !hasFocus()) {
        marker->setOpacity(MARKER_OPACITY_ON_HOVER);
        marker->setVisible(true);
    }
}

void Actor::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    if (marker) {
        if (!hasFocus())
            marker->setVisible(false);
        else marker->setOpacity(1);
    }
}
```

The movement method mimics the methods used in most of the 2D games (e.g. old pokemon games). The actor can move to a certain point in the screen without changing the position of the viewport. The code below shows where it is implemented.

```cpp
// actor.cpp file

void Actor::UpdateViewport() {
/* Lots of nasty lines to get the right coordinates */
    if (d_l < l) h_diff = d_l - l;
    if (d_r > r) h_diff = d_r - r;
    if (d_t < t) v_diff = d_t - t;
    if (d_b > b) v_diff = d_b - b;

    if (h_diff || v_diff)
        v->centerOn(screen_center_scene_pos + QPointF(h_diff, v_diff));
}
```

An animation based on switching pixmap (still, left_leg_up, right_leg_up) is used to create an illusion of the actor walking. Pressing shift makes the actor move 2x faster.  

```cpp
// actor.cpp file

/* Loading pixmaps from files */
Actor::Actor(QGraphicsItem *parent)
/* ... */
    anim_pixmaps.still = QPixmap("resources/images/actor/dude.png").scaledToHeight(GRID_GRANULARITY*5);
    anim_pixmaps.left_up = QPixmap("resources/images/actor/dude_left_leg_up.png").scaledToHeight(GRID_GRANULARITY*5);
    anim_pixmaps.right_up = QPixmap("resources/images/actor/dude_right_leg_up.png").scaledToHeight(GRID_GRANULARITY*5);
    pixmap = &anim_pixmaps.still;
    setPixmap(*pixmap);
/* ... */
}

/* Animation and shift to speed-up mechanism */
void Actor::Move() {
/* ... */
    // Shift to speed-up mechanism
    qreal speed_mult = GetKeyState(VK_SHIFT) & ~1 ? SHIFT_SPEED_INCREASE : 1;
    qreal x = scenePos().x();
    qreal y = scenePos().y();
    if (mov_h)
        x += mov_h * speed * speed_mult;
    if (mov_v)
        y += mov_v * speed * speed_mult;
/* ... */
        // Animation mechanism
        if (GetTickCount() > last_leg_switch + LEG_SWITCH_INTERVAL / speed_mult) {
            last_leg_switch = GetTickCount();
            if (pixmap == &anim_pixmaps.left_up) pixmap = &anim_pixmaps.right_up;
            else pixmap = &anim_pixmaps.left_up;
            setPixmap(*pixmap);
        }
/* ... */
```

/

![player movement gif](https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/player%20movement.gif?raw=true)  

\
\
\
\
\
\
\
\
\
# Smart devices
Each of the sections below presents different types of smart device. Each device is a separate class, that allowed to implement different behaviour/features for them in a structured way. Their corresponding class files are preceeded with "sd_" (e.g. "sd_lights.cpp", "sd_lights.h").  

## Doorbell  
<img src="https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/raw/master/src/smart_home_simulator/resources/images/smart%20devices/doorbell.png" alt="smart device image" width="100" /> <br>  

The doorbell is supposed to be put near the door (marked with yellow colour on the screenshot below). When the player collides with a doorbell, a message about a possible interaction appears. When "e" is pressed the appropriate sound effect is played.  

<img src="https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/doorbell.png?raw=true" alt="smart device image" width="400" />  


## Light  
<img src="https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/raw/master/src/smart_home_simulator/resources/images/smart%20devices/smart-light.png" alt="smart device image" width="100" /><br>  

The light smart device has its own section in the control screen window, where the user can select lights by clicking on them (multiple lights can be selected if "Ctrl" is being held).  

![lights control screen section image](https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/lights%20-%20control%20screen.png?raw=true)  

The animation below shows how lights can be toggled and how their brightness or colour can be set.  

![lights features gif](https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/lights_all_features_except_auto_on_off.gif?raw=true)  

The auto on/off setting turns on the lights located inside a room the player just entered. It also turns off the lights located in the previously occupied room.  

![lights auto on off gif](https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/lights%20-%20auto%20on%20off.gif?raw=true)  

The "Mimic colour temperature of the sun" checkbox monitors the simulated time of the day and automatically sets the colour of all the light smart devices.  

![lights mimic sun colour gif](https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/lights%20-%20mimic%20sun%20colour.gif?raw=true)  

The values of the sun colour temperature were collected from the ["Several biological benefits of the low color temperature light-emitting diodes based normal indoor lighting source." by Lin, J., Ding, X., Hong, C. et al.](https://www.nature.com/articles/s41598-019-43864-6). The collected values were taken from the Figure 1a of the aforementioned article, shown below:  
<img src="https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/colour%20temperature.png?raw=true" alt="image not displayed" width="600" /><br>

It can be seen that the collected values consisted of data at 2 hour interval. Drastic changes every 2 hours could be irritating for the user. So in order to make the gradual/smooth change of the colour throughout the day we decided to linearly interpolate the current time between the 2 closest corresponding kelvin/time values. For example, if the current time was 11:00, then the applied Kelvin value would be 5300, that's because it is half-way between 4000 Kelvin (at 10:00) and 6600 Kelvin (at 12:00). To achieve that we used the ["map" function copied from Arduino libraries](https://www.arduino.cc/reference/en/language/functions/math/map/), which does exactly that.  
```cpp
// part of sun_colour.cpp file

long SunColour::map(long x, long in_min, long in_max, long out_min, long out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

/*
int interpolated_kelvin = map(
                time.msecsSinceStartOfDay()/1000,
                time_under.msecsSinceStartOfDay()/1000,
                time_over.msecsSinceStartOfDay()/1000,
                temp_under,
                temp_over);
*/
```

The code used to convert Kelvin values to RGB was adapted from ["Kelvin2RGB" github repository by timvw74](https://github.com/timvw74/Kelvin2RGB/blob/master/Kelvin2RGB.h).  
 
## Power socket
<img src="https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/raw/master/src/smart_home_simulator/resources/images/smart%20devices/socket.png" alt="smart device image" width="100" /> <br>  

Functionality of power sockets is very simple, they can be turned on and off, either by approaching them with the player, or from the control screen by using the "Toggle selected power sockets" button. Switching them on or off produces a sound effect.

<img src="https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/power%20socket.gif?raw=true" alt="smart device image" width="600" /> <br>  


## Radiator  
<img src="https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/raw/master/src/smart_home_simulator/resources/images/smart%20devices/radiator.png" alt="smart device image" width="100" /> <br> 

Radiators can be toggled on and off (with a sound effect), their power level can be adjusted too. Both of these actions can be accomplished by either physical interaction or from the control screen. Additionally, the control screen contains an "Auto on/off" checkbox, if it's checked then the radiators (only those that have thermometer in range) get automatically turned on when temperature outside gets under 10 degrees.  
![radiators gif](https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/radiators.gif?raw=true)  

To create a responsive feel of the program, the colour of the power level indicators turn gray when the radiator is switched off. The range indicator changes their colour when a thermometer is found in their range.  


## Fan  
<img src="https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/raw/master/src/smart_home_simulator/resources/images/smart%20devices/fan.png" alt="smart device image" width="100" /> <br>  

Fans can be switched on and off (with a sound effect). If the "Auto on/off" checkbox is checked in the "Heating" section of the control screen, then the fans respond to temperature change. If the temperature is 20 degrees or above they get turned on, if the temperature falls under 20 degrees they get turned off.  

![fans gif](https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/fan.gif?raw=true)

## Thermometer  
<img src="https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/raw/master/src/smart_home_simulator/resources/images/smart%20devices/thermometer.png" alt="smart device image" width="100" />  

Thermometer smart device can be placed near radiators. That enables the radiators to get temperature readings from far away. Getting temperature reading from thermometer residing directly on the radiator could possibly provide readings that do not represent the temperature of the whole room (because of being too close), for that reason the "smart radiators" require a remote thermometer to work (at least that is how we implemented it in our program).  


## Infra red sensor
<img src="https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/infra%20red%20sensor.png?raw=true" alt="smart device image" width="100" /> <br> 

Infra red sensors detect the presence of a person inside a room.  

![infra red sensor gif](https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/infra%20red%20sensor.gif?raw=true)  


## Toilet
<img src="https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/raw/master/src/smart_home_simulator/resources/images/smart%20devices/toilet.png" alt="smart device image" width="100" /> <br> 

The toilet smart device allows 2 actions to be performed (1. use, 2. flush), both actions are accompanied by different sound effects. What makes the toilet "smart" is the fact that if the player does not flush it manually; it will be automatically flushed when the player exists the bathroom.  
![toilet gif](https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/toilet.gif?raw=true)  


## Blinds
<img src="https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/raw/master/src/smart_home_simulator/resources/images/smart%20devices/curtains.png" alt="smart device image" width="100" />  

Blinds can be opened and closed (accompanied with sound effects). In the control screen window it is possible to enable automatic opening and/or closing at specified times.  
![blinds gif](https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/blinds.gif?raw=true)  


## Control screen
<img src="https://cseegit.essex.ac.uk/2019_ce292/ce292_team_2/raw/master/src/smart_home_simulator/resources/images/smart%20devices/control%20screen.png" alt="smart device image" width="100" />  

Control screen can be opened by pressing "e". The position of the newly created window is in the top-left of the window and it's size first perfectly the position of the main window (unless the user resizes it before opening the control screen.).  
<img src="https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/control%20screen%20opening.gif?raw=true" alt="control screen opening couldnt be loaded" width=600 />

\
\
\
\
\
\
\
\
\
# Additional features
### Responsive weather area
The main functionality related with the weather area were described in the previous sections, however it is worth to notice that we put effort to improve user experience by:  
* changing the sun-based images to moon-based images (and vice-versa) automatically (even if the "Randomize" option is unchecked) depending on time of the day  
![day night weather image change gif](https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/day_night_weather_images_change.gif?raw=true )
* background colour change to emphasize that the current temperature is regarded as hot (high enough to turn on the fans) or cold (low enough to turn on the radiators)  
![temperature background color change gif](https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/temperature%20background%20color%20change.gif?raw=true)    

### Convenient window placement
The position of the main window is dependent on the width of the "Environment" and "Control screen" windows. When the program starts the width of these windows is checked so the main window is placed perfectly next to these. Also the position of "Environment" window is relying on the height of "Control screen", so that it is displayed directly underneath it. This configuration ensures that the user does not have to move these windows every time they are opened which could be frustrating.  

<img src="https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/overview.png?raw=true" alt="overview image" width=600 />

The following code is responsible for adjusting the position of the windows.
```cpp
// part of the mainwindow.cpp file

    int top_frame_size = 31;
    int start_menu_estimated_height = 50;
    QSize resolution = app->screens()[0]->size();

    int x_offset = std::max(controller_screen->width(), environment_window->width()) + 1;
    setGeometry(
    /*   x    */  x_offset,
    /*   y    */  top_frame_size,
    /* width  */  resolution.width() - x_offset,
    /* height */  resolution.height() - start_menu_estimated_height
               );

    controller_screen->setGeometry(0, top_frame_size, x_offset - 1, controller_screen->height());
    environment_window->setGeometry(0, controller_screen->height() + top_frame_size*2, x_offset - 1, environment_window->height());
```

### Song alarms
One of the additional features is the ability to set alarms that start playing an mp3 file at a specified time of a day.  
![alarms image](https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/alarm.png?raw=true)  

It is worth to notice that there is no need to manually input the names/location of the audio files; song names are recognized automatically (as long as they're placed in the "resources/audio/songs/" directory") and the combo-box item is populated using these.  
That is accomplished in a relatively simple way by using QDir object provided by Qt, as shown in the code below:  
```cpp
// part of audio.cpp file

void Audio::LoadSongs(QString path)
{
    QDir directory(path);
    songs_files = directory.entryList(QStringList() << "*.mp3" << "*.MP3", QDir::Files);
    for (QString f_name : songs_files) {
        songs_playlist->addMedia(QUrl().fromLocalFile(path + f_name));
    }
```

### UUID and location
Each smart device has an ID increasing with every created device. It also contains a separate UUID and location (created mainly in order to comply with the [project outline document](https://moodle.essex.ac.uk/pluginfile.php/787274/mod_resource/content/3/Project%20outline.pdf)). 
Because location and UUID must occupy a relatively large area to be readable, we decided to add them as a "tooltip" for each device. "Tooltip" displays text on a yellow background when the mouse pointer stops over the smart device for a short amount of time.  
<img src="https://github.com/michalmonday/files/blob/master/ce292_team_project/images/final/uuid_and_location.png?raw=true" alt="image" width=300 />

# Summary
All the of the initial functional requirements (6), non-functional requirements (5) and smart-device related minimum requirements (4) specified in the [project outline document](https://moodle.essex.ac.uk/pluginfile.php/787274/mod_resource/content/3/Project%20outline.pdf) have been met.
Furthermore, the program implemented various additional features and smart devices not mentioned as minimum requirements.   