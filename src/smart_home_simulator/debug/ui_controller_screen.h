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
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_ControllerScreen
{
public:
    QPushButton *pushButton_toggleSelectedLights;
    QPushButton *pushButton_setSelectedLightsColor;
    QFrame *frame;
    QLabel *label;
    QSlider *horizontalSlider_selectedLightsOpacity;
    QPushButton *pushButton_toggleSelectedPowerSockets;
    QCalendarWidget *calendarWidget;

    void setupUi(QDialog *ControllerScreen)
    {
        if (ControllerScreen->objectName().isEmpty())
            ControllerScreen->setObjectName(QStringLiteral("ControllerScreen"));
        ControllerScreen->resize(616, 396);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ControllerScreen->sizePolicy().hasHeightForWidth());
        ControllerScreen->setSizePolicy(sizePolicy);
        ControllerScreen->setSizeGripEnabled(true);
        pushButton_toggleSelectedLights = new QPushButton(ControllerScreen);
        pushButton_toggleSelectedLights->setObjectName(QStringLiteral("pushButton_toggleSelectedLights"));
        pushButton_toggleSelectedLights->setGeometry(QRect(10, 50, 141, 23));
        pushButton_setSelectedLightsColor = new QPushButton(ControllerScreen);
        pushButton_setSelectedLightsColor->setObjectName(QStringLiteral("pushButton_setSelectedLightsColor"));
        pushButton_setSelectedLightsColor->setGeometry(QRect(10, 20, 141, 23));
        frame = new QFrame(ControllerScreen);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(10, 80, 141, 81));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Plain);
        frame->setLineWidth(3);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 141, 41));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);
        horizontalSlider_selectedLightsOpacity = new QSlider(frame);
        horizontalSlider_selectedLightsOpacity->setObjectName(QStringLiteral("horizontalSlider_selectedLightsOpacity"));
        horizontalSlider_selectedLightsOpacity->setGeometry(QRect(10, 50, 121, 22));
        horizontalSlider_selectedLightsOpacity->setMinimum(1);
        horizontalSlider_selectedLightsOpacity->setMaximum(255);
        horizontalSlider_selectedLightsOpacity->setValue(255);
        horizontalSlider_selectedLightsOpacity->setOrientation(Qt::Horizontal);
        pushButton_toggleSelectedPowerSockets = new QPushButton(ControllerScreen);
        pushButton_toggleSelectedPowerSockets->setObjectName(QStringLiteral("pushButton_toggleSelectedPowerSockets"));
        pushButton_toggleSelectedPowerSockets->setGeometry(QRect(160, 20, 171, 23));
        calendarWidget = new QCalendarWidget(ControllerScreen);
        calendarWidget->setObjectName(QStringLiteral("calendarWidget"));
        calendarWidget->setGeometry(QRect(290, 200, 312, 183));

        retranslateUi(ControllerScreen);

        QMetaObject::connectSlotsByName(ControllerScreen);
    } // setupUi

    void retranslateUi(QDialog *ControllerScreen)
    {
        ControllerScreen->setWindowTitle(QApplication::translate("ControllerScreen", "Smart home controller screen", Q_NULLPTR));
        pushButton_toggleSelectedLights->setText(QApplication::translate("ControllerScreen", "Toggle selected lights", Q_NULLPTR));
        pushButton_setSelectedLightsColor->setText(QApplication::translate("ControllerScreen", "Set selected lights color", Q_NULLPTR));
        label->setText(QApplication::translate("ControllerScreen", "Set selected lights opacity", Q_NULLPTR));
        pushButton_toggleSelectedPowerSockets->setText(QApplication::translate("ControllerScreen", "Toggle selected power sockets", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ControllerScreen: public Ui_ControllerScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLLER_SCREEN_H
