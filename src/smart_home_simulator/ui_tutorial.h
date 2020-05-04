/********************************************************************************
** Form generated from reading UI file 'tutorial.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TUTORIAL_H
#define UI_TUTORIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Tutorial
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_gifholder;
    QLabel *label_textholder;
    QCheckBox *checkBox_dont_show_again;
    QPushButton *pushButton_next;
    QPushButton *pushButton_close;

    void setupUi(QDialog *Tutorial)
    {
        if (Tutorial->objectName().isEmpty())
            Tutorial->setObjectName(QStringLiteral("Tutorial"));
        Tutorial->resize(761, 502);
        gridLayout = new QGridLayout(Tutorial);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_gifholder = new QLabel(Tutorial);
        label_gifholder->setObjectName(QStringLiteral("label_gifholder"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(label_gifholder->sizePolicy().hasHeightForWidth());
        label_gifholder->setSizePolicy(sizePolicy);
        label_gifholder->setScaledContents(true);
        label_gifholder->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_gifholder);

        label_textholder = new QLabel(Tutorial);
        label_textholder->setObjectName(QStringLiteral("label_textholder"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_textholder->sizePolicy().hasHeightForWidth());
        label_textholder->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(11);
        label_textholder->setFont(font);
        label_textholder->setAlignment(Qt::AlignCenter);
        label_textholder->setWordWrap(true);
        label_textholder->setMargin(27);

        verticalLayout->addWidget(label_textholder);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 3);

        checkBox_dont_show_again = new QCheckBox(Tutorial);
        checkBox_dont_show_again->setObjectName(QStringLiteral("checkBox_dont_show_again"));

        gridLayout->addWidget(checkBox_dont_show_again, 1, 0, 1, 1);

        pushButton_next = new QPushButton(Tutorial);
        pushButton_next->setObjectName(QStringLiteral("pushButton_next"));

        gridLayout->addWidget(pushButton_next, 1, 1, 1, 1);

        pushButton_close = new QPushButton(Tutorial);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));

        gridLayout->addWidget(pushButton_close, 1, 2, 1, 1);


        retranslateUi(Tutorial);

        QMetaObject::connectSlotsByName(Tutorial);
    } // setupUi

    void retranslateUi(QDialog *Tutorial)
    {
        Tutorial->setWindowTitle(QApplication::translate("Tutorial", "Tutorial", Q_NULLPTR));
        label_gifholder->setText(QApplication::translate("Tutorial", "Gif holder (this text shouldn't be displayed)", Q_NULLPTR));
        label_textholder->setText(QApplication::translate("Tutorial", "Text holder (this text shouldn't be displayed)", Q_NULLPTR));
        checkBox_dont_show_again->setText(QApplication::translate("Tutorial", "Don't show this window again", Q_NULLPTR));
        pushButton_next->setText(QApplication::translate("Tutorial", "Next", Q_NULLPTR));
        pushButton_close->setText(QApplication::translate("Tutorial", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Tutorial: public Ui_Tutorial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TUTORIAL_H
