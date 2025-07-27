#ifndef CARDSUI_H
#define CARDSUI_H

#include <QDialog>
#include "cards.h"
#include "processingCards.h"

namespace Ui {
class cardsui;
}

class cardsui : public QDialog
{
    Q_OBJECT

public:
    cardsui(CardsProcessingLEG &cpLEG,QWidget *parent = nullptr);
    ~cardsui();

    void start();
    void showCurrentCard();
    void showTranslate();

    void changeSR(const uint8_t newSR);

    void speakEngWord();

private slots:
    void on_pb_stop_clicked();

    void on_pb_translate_clicked();

    void on_pb_sr_1_clicked();

    void on_pb_sr_2_clicked();

    void on_pb_sr_3_clicked();

    void on_pb_sr_4_clicked();

    void on_pb_sr_5_clicked();

    void on_pushButton_clicked();

private:
    Ui::cardsui *ui;
    CardsProcessingLEG &cpLEG_;
    std::vector<Card> cards_;
    size_t currentCardIndex_ = 0;
    size_t showCards_ = -1;
};

#endif // CARDSUI_H
