/********************************************************************************
** Form generated from reading UI file 'cardsui.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDSUI_H
#define UI_CARDSUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cardsui
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *lbl_eng;
    QLabel *lbl_ru;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *le_sr;
    QLabel *lbl_error;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pb_translate;
    QPushButton *pb_next;
    QPushButton *pb_stop;

    void setupUi(QDialog *cardsui)
    {
        if (cardsui->objectName().isEmpty())
            cardsui->setObjectName("cardsui");
        cardsui->resize(407, 624);
        layoutWidget = new QWidget(cardsui);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(50, 48, 291, 191));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lbl_eng = new QLabel(layoutWidget);
        lbl_eng->setObjectName("lbl_eng");

        verticalLayout->addWidget(lbl_eng);

        lbl_ru = new QLabel(layoutWidget);
        lbl_ru->setObjectName("lbl_ru");

        verticalLayout->addWidget(lbl_ru);

        layoutWidget_3 = new QWidget(cardsui);
        layoutWidget_3->setObjectName("layoutWidget_3");
        layoutWidget_3->setGeometry(QRect(80, 358, 221, 28));
        horizontalLayout = new QHBoxLayout(layoutWidget_3);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget_3);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        le_sr = new QLineEdit(layoutWidget_3);
        le_sr->setObjectName("le_sr");

        horizontalLayout->addWidget(le_sr);

        lbl_error = new QLabel(cardsui);
        lbl_error->setObjectName("lbl_error");
        lbl_error->setGeometry(QRect(50, 280, 291, 51));
        widget = new QWidget(cardsui);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(81, 452, 221, 92));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pb_translate = new QPushButton(widget);
        pb_translate->setObjectName("pb_translate");

        verticalLayout_2->addWidget(pb_translate);

        pb_next = new QPushButton(widget);
        pb_next->setObjectName("pb_next");

        verticalLayout_2->addWidget(pb_next);

        pb_stop = new QPushButton(widget);
        pb_stop->setObjectName("pb_stop");

        verticalLayout_2->addWidget(pb_stop);


        retranslateUi(cardsui);

        QMetaObject::connectSlotsByName(cardsui);
    } // setupUi

    void retranslateUi(QDialog *cardsui)
    {
        cardsui->setWindowTitle(QCoreApplication::translate("cardsui", "Dialog", nullptr));
        lbl_eng->setText(QCoreApplication::translate("cardsui", " \320\220\320\275\320\263\320\273\320\270\320\271\321\201\320\272\320\276\320\265 \321\201\320\273\320\276\320\262\320\276", nullptr));
        lbl_ru->setText(QCoreApplication::translate("cardsui", "\320\237\320\265\321\200\320\265\320\262\320\276\320\264", nullptr));
        label->setText(QCoreApplication::translate("cardsui", "SR \320\276\321\206\320\265\320\275\320\272\320\260", nullptr));
        lbl_error->setText(QCoreApplication::translate("cardsui", "<html><head/><body><p><br/></p></body></html>", nullptr));
        pb_translate->setText(QCoreApplication::translate("cardsui", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \320\277\320\265\321\200\320\265\320\262\320\276\320\264", nullptr));
        pb_next->setText(QCoreApplication::translate("cardsui", "\320\241\320\273\320\265\320\264\321\203\321\216\321\211\320\270\320\265", nullptr));
        pb_stop->setText(QCoreApplication::translate("cardsui", "\320\241\321\202\320\276\320\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cardsui: public Ui_cardsui {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDSUI_H
