#include "leg.h"
#include "ui_leg.h"
#include "addword.h"
#include "cardsui.h"

#include <QPixmap>
#include <QMessageBox>

LEG::LEG(std::string name, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LEG)
    , cpLEG_(name)
{
    ui->setupUi(this);

    setFixedSize(350, 600);
    setWindowFlag(Qt::WindowMaximizeButtonHint, false);
    setWindowFlag(Qt::WindowMinimizeButtonHint, false);

    setBackgroundWidget();
    ui->lbl_how_deck->setText(QString::fromStdString(name));

}

LEG::~LEG()
{
    delete ui;

}



void LEG::on_pb_add_word_clicked()
{
    hide();
    addWord window(cpLEG_, this);
    window.setModal(true);
    window.exec();
    show();
}



void LEG::on_pb_start_clicked()
{
    hide();
    cardsui window(cpLEG_, this);
    window.setModal(true);
    window.exec();
    show();
}

void LEG::setBackgroundWidget() {
    QPixmap backgroundImage(":/resources/images/BlueMain.png");
    QPalette palette;
    palette.setBrush(QPalette::Window, QBrush(backgroundImage));
    ui->centralwidget->setAutoFillBackground(true);
    ui->centralwidget->setPalette(palette);
}


void LEG::on_le_choiceDeck_textChanged(const QString &arg1)
{
    std::string nameDeck = arg1.toStdString();
    cpLEG_ = CardsProcessingLEG(nameDeck);
    ui->lbl_how_deck->setText(arg1);
}

