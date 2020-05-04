#include "sd_controlscreen.h"
#include "actor_player.h"

#include "controller_screen.h"

#define CLICK_ME_BRUSH QColor(255, 242, 0)

ControlScreen::ControlScreen()
    : SmartDevice()
{

    SetLabelText("Control screen");
//    click_me_text = new QGraphicsSimpleTextItem("CLICK TO OPEN", this);
//    click_me_text->setVisible(false);
//    InitClickToOpenText();
}

ControlScreen::~ControlScreen() {

}

//void ControlScreen::InitClickToOpenText()
//{
//    int font_sz = boundingRect().width() / SD_FONT_SIZE_DIVIDER;
//    QFont font(LABEL_FONT_NAME, font_sz);
//    font.setBold(true);
//    click_me_text->setFont(font);
//    click_me_text->setFlag(QGraphicsItem::ItemIsMovable);
//    click_me_text->setPen(QPen(Qt::black, 2));
//    click_me_text->setBrush(CLICK_ME_BRUSH);

//    // set pos
//    float x = boundingRect().width()/2 - click_me_text->boundingRect().width() / 2;
//    float y =  -click_me_text->boundingRect().height() * 0.5;
//    click_me_text->setPos(QPointF(x, y));
//}

/*void ControlScreen::SetVisibleToUser(bool is_visible) {
    state.visible_to_user = is_visible;
    click_me_text->setVisible(is_visible);

//    if (is_visible)
//        player->interaction_text->setText("Press ''");
}

bool ControlScreen::IsVisibleToUser() {
    return state.visible_to_user;
}*/

/*
void ControlScreen::PaintState(QPainter *painter, QRectF bounding_rect) {

}
*/


void ControlScreen::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    if (state.visible_to_user) {
//        //GraphicsItem::SetPixmapColor(pixmap, Qt::darkGreen);
//        painter->drawPixmap(0,0, pixmap);
//        update();
//    }
//    else {
//        SmartDevice::paint(painter, option, widget);
//        return;
//    }

    SmartDevice::paint(painter, option, widget);
}

void ControlScreen::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
//    if (state.visible_to_user) {
//        click_me_text->setBrush(Qt::darkGreen);
//    }
    SmartDevice::hoverEnterEvent(event);
}

void ControlScreen::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
//    click_me_text->setBrush(CLICK_ME_BRUSH);
    SmartDevice::hoverLeaveEvent(event);
}

void ControlScreen::keyPressEvent(QKeyEvent *event)
{
    SmartDevice::keyPressEvent(event);
}

void ControlScreen::keyReleaseEvent(QKeyEvent *event)
{
    SmartDevice::keyReleaseEvent(event);
}

void ControlScreen::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
//    if (state.visible_to_user)
//        return;
    SmartDevice::mousePressEvent(event);
}

void ControlScreen::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    SmartDevice::mouseMoveEvent(event);
}

void ControlScreen::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
//    if (state.visible_to_user) {
//        controller_screen->show();
//        if (player)
//            player->Stop();
//        return;
//    }
    SmartDevice::mouseReleaseEvent(event);
}

QVariant ControlScreen::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    return SmartDevice::itemChange(change, value);
}

void ControlScreen::SetSize(QPointF size)
{
    SmartDevice::SetSize(size);
    //InitClickToOpenText();
}
