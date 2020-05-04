#include "smart_device_creator.h"
#include "grid.h"

#include "sd_controlscreen.h"
#include "sd_doorbell.h"
#include "sd_infra_red_sensor.h"
#include "sd_light.h"
#include "sd_powersocket.h"
#include "sd_radiator.h"
#include "sd_speakers.h"
#include "sd_thermometer.h"
#include "sd_toilet.h"
#include "sd_fan.h"
#include "sd_blinds.h"

#include <QPixmap>

SmartDeviceCreator *smart_device_creator;

SmartDeviceCreator::SmartDeviceCreator() {
}

SmartDeviceCreator::~SmartDeviceCreator(){

}

bool SmartDeviceCreator::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    return false;
}

bool SmartDeviceCreator::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    return false;
}

#define PIXMAP_SIZE 128
bool SmartDeviceCreator::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    bool clicked_on_smart_device = false;
    for (auto &item : scene_->items(event->scenePos())) {
        if (dynamic_cast<SmartDevice *>(item)) {
            clicked_on_smart_device = true;
            break;
        }
    }

    if (event->button() == Qt::LeftButton && !clicked_on_smart_device){

        SmartDevice *item = CreateDevice();
        //GraphicsItem *item  = new GraphicsItem(ITEM_IMAGE);

        QGraphicsTextItem *label_item = item->GetTextLabelItem();

        item->SetPixmap(pixmap); // pixmap.scaledToHeight(PIXMAP_SIZE)

        int sz = (int)grid->RoundToGranularity(PIXMAP_SIZE, "none");
        item->SetSize(QPointF(sz, sz));
        item->setPos(grid->GetClosestPoint(event->scenePos() - item->boundingRect().bottomRight()/2));

        scene_->addItem(item);
        item->UpdateTooltip(); // includes uuid and location (must be done after adding item to scene)

        if (Radiator *rad = dynamic_cast<Radiator *>(item))
            rad->UpdateRangeIndicator();

        if (Thermometer *therm = dynamic_cast<Thermometer *>(item))
            Radiator::UpdateAllRadiators();

        if (InfraRedSensor *irs = dynamic_cast<InfraRedSensor *>(item))
            irs->InitStateText();
        return true;
    }

    if (event->button() == Qt::RightButton) {
        SetCreator(base_idle_creator);
    }
    return false;
}

bool SmartDeviceCreator::keyPressEvent(QKeyEvent * event) {
    return false;
}

bool SmartDeviceCreator::keyReleaseEvent(QKeyEvent * event) {
    int key = event->key();

    if (key == Qt::Key_Escape || key == Qt::Key_Delete) {
        SetCreator(base_idle_creator);
    }
    return false;
}

void SmartDeviceCreator::SetPixmap(QPixmap p) {
    pixmap = p;
}

void SmartDeviceCreator::SetDeviceType(QAbstractButton* button) {
    device_button = button;
    int sz = (int)grid->RoundToGranularity(1024.0, "none");
    SetPixmap(button->icon().pixmap(sz, sz));
}

SmartDevice * SmartDeviceCreator::CreateDevice() {
    if (device_button == pMainWindow->ui->pushButton_light_bulb)        return new Light();
    if (device_button == pMainWindow->ui->pushButton_doorbell)          return new Doorbell();
    if (device_button == pMainWindow->ui->pushButton_power_socket)      return new PowerSocket();
    if (device_button == pMainWindow->ui->pushButton_control_screen)    return new ControlScreen();
    if (device_button == pMainWindow->ui->pushButton_speakers)          return new Speakers();
    if (device_button == pMainWindow->ui->pushButton_radiator)          return new Radiator();
    if (device_button == pMainWindow->ui->pushButton_thermometer)       return new Thermometer();
    if (device_button == pMainWindow->ui->pushButton_infra_red_sensor)  return new InfraRedSensor();
    if (device_button == pMainWindow->ui->pushButton_toilet)            return new Toilet();
    if (device_button == pMainWindow->ui->pushButton_fan)               return new Fan();
    if (device_button == pMainWindow->ui->pushButton_blinds)            return new Blinds();
    qDebug() << "ERROR: SmartDeviceCreator::CreateDevice, wrong device_button (" << device_button << ")";
}







