/********************************************************************************
** Form generated from reading UI file 'addword.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDWORD_H
#define UI_ADDWORD_H

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

class Ui_addWord
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *en;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *ru;
    QPushButton *pushButton;

    void setupUi(QDialog *addWord)
    {
        if (addWord->objectName().isEmpty())
            addWord->setObjectName("addWord");
        addWord->resize(428, 629);
        widget = new QWidget(addWord);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(90, 270, 244, 98));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(widget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        en = new QLineEdit(widget);
        en->setObjectName("en");

        horizontalLayout->addWidget(en);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        ru = new QLineEdit(widget);
        ru->setObjectName("ru");

        horizontalLayout_2->addWidget(ru);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName("pushButton");

        verticalLayout_2->addWidget(pushButton);


        retranslateUi(addWord);

        QMetaObject::connectSlotsByName(addWord);
    } // setupUi

    void retranslateUi(QDialog *addWord)
    {
        addWord->setWindowTitle(QCoreApplication::translate("addWord", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("addWord", "English word", nullptr));
        label_2->setText(QCoreApplication::translate("addWord", "Russian word", nullptr));
        pushButton->setText(QCoreApplication::translate("addWord", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\320\273\320\276\320\262\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addWord: public Ui_addWord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDWORD_H
