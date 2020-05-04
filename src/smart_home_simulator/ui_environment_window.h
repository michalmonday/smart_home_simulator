/********************************************************************************
** Form generated from reading UI file 'environment_window.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENVIRONMENT_WINDOW_H
#define UI_ENVIRONMENT_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_EnvironmentWindow
{
public:
    QGroupBox *groupBox_speed;
    QSlider *horizontalSlider;
    QDateTimeEdit *dateTimeEdit;
    QLabel *label;
    QLabel *label_day_of_week;
    QLabel *label_2;
    QCheckBox *checkBox_freeze_time;
    QGroupBox *groupBox_temperature;
    QLabel *label_weather_icon_holder;
    QCheckBox *checkBox_randomize_automatically;
    QComboBox *comboBox_weather_type;
    QSpinBox *spinBox_temperature;

    void setupUi(QDialog *EnvironmentWindow)
    {
        if (EnvironmentWindow->objectName().isEmpty())
            EnvironmentWindow->setObjectName(QStringLiteral("EnvironmentWindow"));
        EnvironmentWindow->resize(508, 190);
        QIcon icon;
        icon.addFile(QStringLiteral("resources/images/smart devices/wind_sign.png"), QSize(), QIcon::Normal, QIcon::Off);
        EnvironmentWindow->setWindowIcon(icon);
        groupBox_speed = new QGroupBox(EnvironmentWindow);
        groupBox_speed->setObjectName(QStringLiteral("groupBox_speed"));
        groupBox_speed->setGeometry(QRect(10, 10, 221, 171));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        groupBox_speed->setFont(font);
        horizontalSlider = new QSlider(groupBox_speed);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(20, 40, 181, 22));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setSingleStep(10);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedAppearance(false);
        horizontalSlider->setInvertedControls(false);
        horizontalSlider->setTickPosition(QSlider::NoTicks);
        horizontalSlider->setTickInterval(10);
        dateTimeEdit = new QDateTimeEdit(groupBox_speed);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(20, 80, 181, 41));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setWeight(50);
        dateTimeEdit->setFont(font1);
        dateTimeEdit->setAlignment(Qt::AlignCenter);
        label = new QLabel(groupBox_speed);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 181, 21));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        label->setFont(font2);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_day_of_week = new QLabel(groupBox_speed);
        label_day_of_week->setObjectName(QStringLiteral("label_day_of_week"));
        label_day_of_week->setGeometry(QRect(120, 130, 91, 31));
        QFont font3;
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        label_day_of_week->setFont(font3);
        label_day_of_week->setTextFormat(Qt::AutoText);
        label_day_of_week->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_2 = new QLabel(groupBox_speed);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 130, 101, 31));
        QFont font4;
        font4.setPointSize(9);
        font4.setBold(false);
        font4.setWeight(50);
        label_2->setFont(font4);
        checkBox_freeze_time = new QCheckBox(groupBox_speed);
        checkBox_freeze_time->setObjectName(QStringLiteral("checkBox_freeze_time"));
        checkBox_freeze_time->setGeometry(QRect(120, 20, 91, 17));
        checkBox_freeze_time->setFont(font4);
        groupBox_temperature = new QGroupBox(EnvironmentWindow);
        groupBox_temperature->setObjectName(QStringLiteral("groupBox_temperature"));
        groupBox_temperature->setGeometry(QRect(250, 10, 251, 171));
        groupBox_temperature->setFont(font);
        label_weather_icon_holder = new QLabel(groupBox_temperature);
        label_weather_icon_holder->setObjectName(QStringLiteral("label_weather_icon_holder"));
        label_weather_icon_holder->setGeometry(QRect(20, 80, 71, 71));
        QFont font5;
        font5.setBold(false);
        font5.setWeight(50);
        label_weather_icon_holder->setFont(font5);
        label_weather_icon_holder->setPixmap(QPixmap(QString::fromUtf8("resources/images/weather/sun.png")));
        label_weather_icon_holder->setScaledContents(true);
        checkBox_randomize_automatically = new QCheckBox(groupBox_temperature);
        checkBox_randomize_automatically->setObjectName(QStringLiteral("checkBox_randomize_automatically"));
        checkBox_randomize_automatically->setGeometry(QRect(120, 40, 201, 17));
        checkBox_randomize_automatically->setFont(font5);
        comboBox_weather_type = new QComboBox(groupBox_temperature);
        comboBox_weather_type->setObjectName(QStringLiteral("comboBox_weather_type"));
        comboBox_weather_type->setGeometry(QRect(20, 40, 69, 22));
        comboBox_weather_type->setFont(font5);
        spinBox_temperature = new QSpinBox(groupBox_temperature);
        spinBox_temperature->setObjectName(QStringLiteral("spinBox_temperature"));
        spinBox_temperature->setGeometry(QRect(110, 80, 121, 71));
        QFont font6;
        font6.setPointSize(26);
        font6.setBold(false);
        font6.setWeight(50);
        spinBox_temperature->setFont(font6);
        spinBox_temperature->setLayoutDirection(Qt::RightToLeft);
        spinBox_temperature->setFrame(false);
        spinBox_temperature->setAlignment(Qt::AlignCenter);
        spinBox_temperature->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        spinBox_temperature->setAccelerated(true);
        spinBox_temperature->setProperty("showGroupSeparator", QVariant(false));
        spinBox_temperature->setValue(15);

        retranslateUi(EnvironmentWindow);

        QMetaObject::connectSlotsByName(EnvironmentWindow);
    } // setupUi

    void retranslateUi(QDialog *EnvironmentWindow)
    {
        EnvironmentWindow->setWindowTitle(QApplication::translate("EnvironmentWindow", "Environment", Q_NULLPTR));
        groupBox_speed->setTitle(QApplication::translate("EnvironmentWindow", "Time", Q_NULLPTR));
        label->setText(QApplication::translate("EnvironmentWindow", "Speed", Q_NULLPTR));
        label_day_of_week->setText(QApplication::translate("EnvironmentWindow", "TextLabel", Q_NULLPTR));
        label_2->setText(QApplication::translate("EnvironmentWindow", "Day of the week:", Q_NULLPTR));
        checkBox_freeze_time->setText(QApplication::translate("EnvironmentWindow", "Freeze time", Q_NULLPTR));
        groupBox_temperature->setTitle(QApplication::translate("EnvironmentWindow", "Weather", Q_NULLPTR));
        label_weather_icon_holder->setText(QString());
        checkBox_randomize_automatically->setText(QApplication::translate("EnvironmentWindow", " Randomize", Q_NULLPTR));
        spinBox_temperature->setSuffix(QApplication::translate("EnvironmentWindow", "\302\260C", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class EnvironmentWindow: public Ui_EnvironmentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENVIRONMENT_WINDOW_H
