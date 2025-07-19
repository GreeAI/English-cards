#include "leg.h"
#include "ui_leg.h"
#include "addword.h"
#include "cardsui.h"

LEG::LEG(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LEG)
{
    ui->setupUi(this);
}

LEG::~LEG()
{
    delete ui;
}



void LEG::on_pb_add_word_clicked()
{
    hide();
    addWord window; //Должен передаваться cpLEG_
    window.setModal(true);
    window.exec();
    show();
}



void LEG::on_pb_start_clicked()
{
    hide();
    cardsui window;
    window.setModal(true);
    window.exec();
    show();
}

