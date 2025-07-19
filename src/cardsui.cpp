#include "cardsui.h"
#include "ui_cardsui.h"

#include <QMessageBox>
#include "cstdint"

cardsui::cardsui(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::cardsui)
{
    ui->setupUi(this);
    start();
}

cardsui::~cardsui()
{
    delete ui;
}

void cardsui::start() {
    cards_ = cpLEG_.startRepeat();
    if(cards_.empty()) {
        ui->lbl_error->setText("Нет карточек для повторения");
    }
    else {
        showCurrentCard();
    }
}

void cardsui::showCurrentCard() {
    if (currentCardIndex_ < cards_.size()) {
        const Card& current = cards_[currentCardIndex_];
        ui->lbl_eng->setText(QString::fromStdString(current.en));
        int newSR = ui->le_sr->text().toInt();
        if(newSR <= 5 || newSR >= 1) {
            cards_[currentCardIndex_].sr = static_cast<uint8_t>(newSR);
        }
        else {
            cards_[currentCardIndex_].sr = 1;
        }
    } else {
        QMessageBox::information(this, "Информация", "Карточки закончились");
        cpLEG_.updateDeckAfterRepeat(cards_);
    }
}

void cardsui::on_pb_next_clicked()
{
    currentCardIndex_++;
    showCurrentCard();
    ui->lbl_ru->setText("Перевод");
}


void cardsui::on_pb_stop_clicked()
{
    cpLEG_.updateDeckAfterRepeat(cards_);
    close();
}


void cardsui::on_pb_translate_clicked()
{
    if(cards_.empty()){
        QMessageBox::information(this, "Информация", "Нет карточек на сегодня");
        return;
    }
    const Card& current = cards_[currentCardIndex_];
    ui->lbl_ru->setText(QString::fromStdString(current.ru));
}

