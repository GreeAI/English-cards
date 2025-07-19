/********************************************************************************
** Form generated from reading UI file 'leg.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEG_H
#define UI_LEG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LEG
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QLabel *start;
    QSpacerItem *verticalSpacer;
    QPushButton *pb_start;
    QPushButton *pb_add_word;
    QSpacerItem *verticalSpacer_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LEG)
    {
        if (LEG->objectName().isEmpty())
            LEG->setObjectName("LEG");
        LEG->resize(312, 606);
        centralwidget = new QWidget(LEG);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 301, 561));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        start = new QLabel(widget);
        start->setObjectName("start");

        verticalLayout->addWidget(start);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pb_start = new QPushButton(widget);
        pb_start->setObjectName("pb_start");

        verticalLayout->addWidget(pb_start);

        pb_add_word = new QPushButton(widget);
        pb_add_word->setObjectName("pb_add_word");

        verticalLayout->addWidget(pb_add_word);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        LEG->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LEG);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 312, 23));
        LEG->setMenuBar(menubar);
        statusbar = new QStatusBar(LEG);
        statusbar->setObjectName("statusbar");
        LEG->setStatusBar(statusbar);

        retranslateUi(LEG);

        QMetaObject::connectSlotsByName(LEG);
    } // setupUi

    void retranslateUi(QMainWindow *LEG)
    {
        LEG->setWindowTitle(QCoreApplication::translate("LEG", "LEG", nullptr));
        start->setText(QCoreApplication::translate("LEG", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt;\">Hello</span></p></body></html>", nullptr));
        pb_start->setText(QCoreApplication::translate("LEG", "\320\241\321\202\320\260\321\200\321\202", nullptr));
        pb_add_word->setText(QCoreApplication::translate("LEG", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\320\273\320\276\320\262\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LEG: public Ui_LEG {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEG_H
