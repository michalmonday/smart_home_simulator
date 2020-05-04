/********************************************************************************
** Form generated from reading UI file 'test_widget_form.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_WIDGET_FORM_H
#define UI_TEST_WIDGET_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_test_widget_form
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *test_widget_form)
    {
        if (test_widget_form->objectName().isEmpty())
            test_widget_form->setObjectName(QStringLiteral("test_widget_form"));
        test_widget_form->resize(400, 300);
        verticalLayoutWidget = new QWidget(test_widget_form);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(30, 20, 160, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);


        retranslateUi(test_widget_form);

        QMetaObject::connectSlotsByName(test_widget_form);
    } // setupUi

    void retranslateUi(QWidget *test_widget_form)
    {
        test_widget_form->setWindowTitle(QApplication::translate("test_widget_form", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("test_widget_form", "PushButton", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("test_widget_form", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class test_widget_form: public Ui_test_widget_form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_WIDGET_FORM_H
