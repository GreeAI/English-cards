#include "cardsui.h"
#include "ui_cardsui.h"
#include "eSpeakNG.h"

#include <QMessageBox>
#include "cstdint"

cardsui::cardsui(CardsProcessingLEG &cpLEG, QWidget *parent)
    : QDialog(parent)
    , cpLEG_(cpLEG)
    , ui(new Ui::cardsui)
{
    ui->setupUi(this);

    setFixedSize(350, 600);
    setWindowFlag(Qt::WindowMaximizeButtonHint, false);
    setWindowFlag(Qt::WindowMinimizeButtonHint, false);

    start();
}

cardsui::~cardsui()
{
    delete ui;
    cpLEG_.updateDeckAfterRepeat(cards_);
}

void cardsui::start() {
    cards_ = cpLEG_.startRepeat();
    if(cards_.empty()) {
        QMessageBox::information(this, "Информация", "Нет карточек для повторения");
        this->close();
        return;
    }
    else {
        showCurrentCard();
        currentCardIndex_++;
    }
}

void cardsui::showCurrentCard() {
    if (currentCardIndex_ < cards_.size()) {
        const Card& current = cards_[currentCardIndex_];
        ui->lbl_eng->setText(QString::fromStdString(current.en));
    } else {
        QMessageBox::information(this, "Информация", "Карточки закончились");
        this->close();
        return;
    }

    showCards_++;
}

void cardsui::showTranslate() {
    if(cards_.empty() || showCards_ >= cards_.size()){
        QMessageBox::information(this, "Информация", "Нет карточек на сегодня");
        return;
    }

    const Card& current = cards_[showCards_];
    ui->lbl_ru->setText(QString::fromStdString(current.ru));
}

void cardsui::changeSR(const uint8_t newSR) {
    if(cards_.empty() || showCards_ >= cards_.size()) {
        QMessageBox::information(this, "Информация", "Сегодня нет карточек для повторения");
        this->close();
        ui->lbl_eng->setText("Нет слов для повторения");
        return;
    }
    cards_[showCards_].sr = newSR;

    showCurrentCard();
    currentCardIndex_++;
    ui->lbl_ru->setText("Перевод");
}

void cardsui::speakEngWord()
{
    if(cards_.empty() || showCards_ >= cards_.size()) {
        QMessageBox::information(this, "Информация", "Нет слов для озвучивания!");
        return;
    }
    std::string englishWord = cards_[showCards_].en;
    speakText(englishWord);

}

void cardsui::on_pb_stop_clicked()
{
    close();
}

void cardsui::on_pb_translate_clicked()
{
    showTranslate();
}

void cardsui::on_pb_sr_1_clicked()
{
    changeSR(1);
}

void cardsui::on_pb_sr_2_clicked()
{
    changeSR(2);
}

void cardsui::on_pb_sr_3_clicked()
{
    changeSR(3);
}

void cardsui::on_pb_sr_4_clicked()
{
   changeSR(4);
}

void cardsui::on_pb_sr_5_clicked()
{
    changeSR(5);
}


void cardsui::on_pushButton_clicked()
{
    speakEngWord();
}

