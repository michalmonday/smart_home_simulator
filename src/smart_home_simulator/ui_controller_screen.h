/********************************************************************************
** Form generated from reading UI file 'controller_screen.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLLER_SCREEN_H
#define UI_CONTROLLER_SCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTimeEdit>

QT_BEGIN_NAMESPACE

class Ui_ControllerScreen
{
public:
    QPushButton *pushButton_toggleSelectedPowerSockets;
    QGroupBox *groupBox_lights_control;
    QCheckBox *checkBox_AutoLights;
    QPushButton *pushButton_toggleSelectedLights;
    QPushButton *pushButton_setSelectedLightsColor;
    QFrame *frame;
    QLabel *label;
    QSlider *horizontalSlider_selectedLightsOpacity;
    QLabel *label_2;
    QCheckBox *checkBox_mimic_sun_color_temperature;
    QLabel *label_3;
    QGroupBox *groupBox_song_alarm;
    QPushButton *pushButton_add_new_song_alarm;
    QTimeEdit *timeEdit;
    QComboBox *comboBox_songs;
    QTableWidget *tableWidget_song_alarms;
    QGroupBox *groupBox_heating;
    QCheckBox *checkBox_heating_auto_on_off;
    QLabel *label_heating_auto_on_off;
    QPushButton *pushButton_toggle_selected_radiators;
    QFrame *frame_2;
    QLabel *label_selected_radiators_power_level;
    QSlider *horizontalSlider_selected_radiators_power_level;
    QGroupBox *groupBox;
    QTimeEdit *timeEdit_blinds_auto_close;
    QCheckBox *checkBox_blinds_auto_open;
    QTimeEdit *timeEdit_blinds_auto_open;
    QCheckBox *checkBox_blinds_auto_close;

    void setupUi(QDialog *ControllerScreen)
    {
        if (ControllerScreen->objectName().isEmpty())
            ControllerScreen->setObjectName(QStringLiteral("ControllerScreen"));
        ControllerScreen->resize(506, 499);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ControllerScreen->sizePolicy().hasHeightForWidth());
        ControllerScreen->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral("resources/images/smart devices/control screen.png"), QSize(), QIcon::Normal, QIcon::Off);
        ControllerScreen->setWindowIcon(icon);
        ControllerScreen->setSizeGripEnabled(true);
        pushButton_toggleSelectedPowerSockets = new QPushButton(ControllerScreen);
        pushButton_toggleSelectedPowerSockets->setObjectName(QStringLiteral("pushButton_toggleSelectedPowerSockets"));
        pushButton_toggleSelectedPowerSockets->setGeometry(QRect(10, 470, 241, 23));
        groupBox_lights_control = new QGroupBox(ControllerScreen);
        groupBox_lights_control->setObjectName(QStringLiteral("groupBox_lights_control"));
        groupBox_lights_control->setGeometry(QRect(10, 10, 241, 341));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        groupBox_lights_control->setFont(font);
        checkBox_AutoLights = new QCheckBox(groupBox_lights_control);
        checkBox_AutoLights->setObjectName(QStringLiteral("checkBox_AutoLights"));
        checkBox_AutoLights->setGeometry(QRect(10, 160, 131, 31));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setWeight(50);
        checkBox_AutoLights->setFont(font1);
        pushButton_toggleSelectedLights = new QPushButton(groupBox_lights_control);
        pushButton_toggleSelectedLights->setObjectName(QStringLiteral("pushButton_toggleSelectedLights"));
        pushButton_toggleSelectedLights->setGeometry(QRect(10, 20, 221, 23));
        pushButton_toggleSelectedLights->setFont(font1);
        pushButton_setSelectedLightsColor = new QPushButton(groupBox_lights_control);
        pushButton_setSelectedLightsColor->setObjectName(QStringLiteral("pushButton_setSelectedLightsColor"));
        pushButton_setSelectedLightsColor->setGeometry(QRect(10, 50, 221, 23));
        pushButton_setSelectedLightsColor->setFont(font1);
        frame = new QFrame(groupBox_lights_control);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 80, 221, 71));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(3);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 221, 41));
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        horizontalSlider_selectedLightsOpacity = new QSlider(frame);
        horizontalSlider_selectedLightsOpacity->setObjectName(QStringLiteral("horizontalSlider_selectedLightsOpacity"));
        horizontalSlider_selectedLightsOpacity->setGeometry(QRect(10, 40, 201, 22));
        horizontalSlider_selectedLightsOpacity->setMinimum(1);
        horizontalSlider_selectedLightsOpacity->setMaximum(255);
        horizontalSlider_selectedLightsOpacity->setValue(128);
        horizontalSlider_selectedLightsOpacity->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(groupBox_lights_control);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 190, 171, 51));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_2->setWordWrap(true);
        checkBox_mimic_sun_color_temperature = new QCheckBox(groupBox_lights_control);
        checkBox_mimic_sun_color_temperature->setObjectName(QStringLiteral("checkBox_mimic_sun_color_temperature"));
        checkBox_mimic_sun_color_temperature->setGeometry(QRect(10, 240, 221, 21));
        checkBox_mimic_sun_color_temperature->setFont(font1);
        label_3 = new QLabel(groupBox_lights_control);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 270, 161, 71));
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_3->setWordWrap(true);
        groupBox_song_alarm = new QGroupBox(ControllerScreen);
        groupBox_song_alarm->setObjectName(QStringLiteral("groupBox_song_alarm"));
        groupBox_song_alarm->setGeometry(QRect(260, 250, 241, 211));
        groupBox_song_alarm->setFont(font);
        pushButton_add_new_song_alarm = new QPushButton(groupBox_song_alarm);
        pushButton_add_new_song_alarm->setObjectName(QStringLiteral("pushButton_add_new_song_alarm"));
        pushButton_add_new_song_alarm->setEnabled(true);
        pushButton_add_new_song_alarm->setGeometry(QRect(90, 50, 141, 23));
        pushButton_add_new_song_alarm->setFont(font1);
        timeEdit = new QTimeEdit(groupBox_song_alarm);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setGeometry(QRect(10, 50, 71, 22));
        timeEdit->setFont(font1);
        timeEdit->setAlignment(Qt::AlignCenter);
        timeEdit->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(8, 0, 0)));
        comboBox_songs = new QComboBox(groupBox_song_alarm);
        comboBox_songs->setObjectName(QStringLiteral("comboBox_songs"));
        comboBox_songs->setGeometry(QRect(10, 20, 221, 22));
        comboBox_songs->setFont(font1);
        tableWidget_song_alarms = new QTableWidget(groupBox_song_alarm);
        if (tableWidget_song_alarms->columnCount() < 2)
            tableWidget_song_alarms->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_song_alarms->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_song_alarms->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget_song_alarms->setObjectName(QStringLiteral("tableWidget_song_alarms"));
        tableWidget_song_alarms->setGeometry(QRect(10, 80, 221, 121));
        tableWidget_song_alarms->setFont(font1);
        tableWidget_song_alarms->setRowCount(0);
        tableWidget_song_alarms->setColumnCount(2);
        tableWidget_song_alarms->horizontalHeader()->setDefaultSectionSize(109);
        tableWidget_song_alarms->verticalHeader()->setVisible(false);
        groupBox_heating = new QGroupBox(ControllerScreen);
        groupBox_heating->setObjectName(QStringLiteral("groupBox_heating"));
        groupBox_heating->setGeometry(QRect(260, 10, 241, 231));
        groupBox_heating->setFont(font);
        checkBox_heating_auto_on_off = new QCheckBox(groupBox_heating);
        checkBox_heating_auto_on_off->setObjectName(QStringLiteral("checkBox_heating_auto_on_off"));
        checkBox_heating_auto_on_off->setGeometry(QRect(10, 130, 91, 17));
        checkBox_heating_auto_on_off->setFont(font1);
        label_heating_auto_on_off = new QLabel(groupBox_heating);
        label_heating_auto_on_off->setObjectName(QStringLiteral("label_heating_auto_on_off"));
        label_heating_auto_on_off->setGeometry(QRect(30, 150, 191, 81));
        label_heating_auto_on_off->setFont(font1);
        label_heating_auto_on_off->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label_heating_auto_on_off->setWordWrap(true);
        pushButton_toggle_selected_radiators = new QPushButton(groupBox_heating);
        pushButton_toggle_selected_radiators->setObjectName(QStringLiteral("pushButton_toggle_selected_radiators"));
        pushButton_toggle_selected_radiators->setGeometry(QRect(10, 20, 221, 23));
        pushButton_toggle_selected_radiators->setFont(font1);
        frame_2 = new QFrame(groupBox_heating);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(9, 49, 221, 71));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Plain);
        label_selected_radiators_power_level = new QLabel(frame_2);
        label_selected_radiators_power_level->setObjectName(QStringLiteral("label_selected_radiators_power_level"));
        label_selected_radiators_power_level->setGeometry(QRect(0, 0, 221, 31));
        label_selected_radiators_power_level->setFont(font1);
        label_selected_radiators_power_level->setAlignment(Qt::AlignCenter);
        horizontalSlider_selected_radiators_power_level = new QSlider(frame_2);
        horizontalSlider_selected_radiators_power_level->setObjectName(QStringLiteral("horizontalSlider_selected_radiators_power_level"));
        horizontalSlider_selected_radiators_power_level->setGeometry(QRect(9, 40, 201, 22));
        horizontalSlider_selected_radiators_power_level->setMinimum(1);
        horizontalSlider_selected_radiators_power_level->setMaximum(100);
        horizontalSlider_selected_radiators_power_level->setValue(50);
        horizontalSlider_selected_radiators_power_level->setOrientation(Qt::Horizontal);
        horizontalSlider_selected_radiators_power_level->setTickPosition(QSlider::NoTicks);
        groupBox = new QGroupBox(ControllerScreen);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 360, 241, 101));
        groupBox->setFont(font);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        timeEdit_blinds_auto_close = new QTimeEdit(groupBox);
        timeEdit_blinds_auto_close->setObjectName(QStringLiteral("timeEdit_blinds_auto_close"));
        timeEdit_blinds_auto_close->setGeometry(QRect(20, 30, 101, 22));
        timeEdit_blinds_auto_close->setFont(font1);
        timeEdit_blinds_auto_close->setAlignment(Qt::AlignCenter);
        timeEdit_blinds_auto_close->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(21, 0, 0)));
        checkBox_blinds_auto_open = new QCheckBox(groupBox);
        checkBox_blinds_auto_open->setObjectName(QStringLiteral("checkBox_blinds_auto_open"));
        checkBox_blinds_auto_open->setGeometry(QRect(140, 60, 91, 17));
        checkBox_blinds_auto_open->setFont(font1);
        timeEdit_blinds_auto_open = new QTimeEdit(groupBox);
        timeEdit_blinds_auto_open->setObjectName(QStringLiteral("timeEdit_blinds_auto_open"));
        timeEdit_blinds_auto_open->setGeometry(QRect(20, 60, 101, 22));
        timeEdit_blinds_auto_open->setFont(font1);
        timeEdit_blinds_auto_open->setAlignment(Qt::AlignCenter);
        timeEdit_blinds_auto_open->setDateTime(QDateTime(QDate(2000, 1, 1), QTime(8, 0, 0)));
        checkBox_blinds_auto_close = new QCheckBox(groupBox);
        checkBox_blinds_auto_close->setObjectName(QStringLiteral("checkBox_blinds_auto_close"));
        checkBox_blinds_auto_close->setGeometry(QRect(140, 30, 91, 17));
        checkBox_blinds_auto_close->setFont(font1);

        retranslateUi(ControllerScreen);

        QMetaObject::connectSlotsByName(ControllerScreen);
    } // setupUi

    void retranslateUi(QDialog *ControllerScreen)
    {
        ControllerScreen->setWindowTitle(QApplication::translate("ControllerScreen", "Smart home controller screen", Q_NULLPTR));
        pushButton_toggleSelectedPowerSockets->setText(QApplication::translate("ControllerScreen", "Toggle selected power sockets", Q_NULLPTR));
        groupBox_lights_control->setTitle(QApplication::translate("ControllerScreen", "Lights control", Q_NULLPTR));
        checkBox_AutoLights->setText(QApplication::translate("ControllerScreen", "Auto on/off", Q_NULLPTR));
        pushButton_toggleSelectedLights->setText(QApplication::translate("ControllerScreen", "Toggle selected lights", Q_NULLPTR));
        pushButton_setSelectedLightsColor->setText(QApplication::translate("ControllerScreen", "Set selected lights color", Q_NULLPTR));
        label->setText(QApplication::translate("ControllerScreen", "Set selected lights brightness", Q_NULLPTR));
        label_2->setText(QApplication::translate("ControllerScreen", "Automatically switch on/off the lights when entering/leaving the room.", Q_NULLPTR));
        checkBox_mimic_sun_color_temperature->setText(QApplication::translate("ControllerScreen", "Mimic colour temperature of the sun", Q_NULLPTR));
        label_3->setText(QApplication::translate("ControllerScreen", "Automatically set the colour temperature of lights to mimic the colour of the sun throughout the day.", Q_NULLPTR));
        groupBox_song_alarm->setTitle(QApplication::translate("ControllerScreen", "Song alarms", Q_NULLPTR));
        pushButton_add_new_song_alarm->setText(QApplication::translate("ControllerScreen", "Add new", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_song_alarms->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ControllerScreen", "Song", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_song_alarms->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ControllerScreen", "Time", Q_NULLPTR));
        groupBox_heating->setTitle(QApplication::translate("ControllerScreen", "Heating", Q_NULLPTR));
        checkBox_heating_auto_on_off->setText(QApplication::translate("ControllerScreen", "Auto on/off", Q_NULLPTR));
        label_heating_auto_on_off->setText(QApplication::translate("ControllerScreen", "Automatically turn on heating when it's cold outside (under 10\302\260C). Automatically turn on the fans when it's hot outside (over 20\302\260C).", Q_NULLPTR));
        pushButton_toggle_selected_radiators->setText(QApplication::translate("ControllerScreen", "Toggle selected radiators", Q_NULLPTR));
        label_selected_radiators_power_level->setText(QApplication::translate("ControllerScreen", "Set selected radiators power level", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ControllerScreen", "Blinds", Q_NULLPTR));
        checkBox_blinds_auto_open->setText(QApplication::translate("ControllerScreen", "Auto open", Q_NULLPTR));
        checkBox_blinds_auto_close->setText(QApplication::translate("ControllerScreen", "Auto close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ControllerScreen: public Ui_ControllerScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLLER_SCREEN_H
