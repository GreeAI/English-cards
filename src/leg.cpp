#include "leg.h"
#include "addword.h"
#include "cardsui.h"
#include "translatorui.h"
#include "ui_leg.h"

#include <QPixmap>
#include <QMessageBox>

#include <QDir>

LEG::LEG(std::string name, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LEG)
    , cpLEG_(name)
{
    ui->setupUi(this);

    setFixedSize(350, 600);
    setWindowFlag(Qt::WindowMaximizeButtonHint, false);
    setWindowFlag(Qt::WindowMinimizeButtonHint, false);

    ui->lbl_how_deck->setText(QString::fromStdString(name));
    ui->lbl_how_deck->setAlignment(Qt::AlignCenter);

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

void LEG::on_le_choiceDeck_textChanged(const QString &arg1)
{
    std::string nameDeck = arg1.toStdString();

    cpLEG_ = CardsProcessingLEG(nameDeck);
    ui->lbl_how_deck->setText(arg1);
}

void LEG::on_pushButton_clicked()
{
    hide();
    translatorUI trans(cpLEG_, this);
    trans.setModal(true);
    trans.exec();
    show();
}
