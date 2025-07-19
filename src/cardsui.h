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
    explicit cardsui(QWidget *parent = nullptr);
    ~cardsui();

    void start();
    void showCurrentCard();

private slots:
    void on_pb_next_clicked();

    void on_pb_stop_clicked();

    void on_pb_translate_clicked();

private:
    Ui::cardsui *ui;
    CardsProcessingLEG cpLEG_;
    std::vector<Card> cards_;
    size_t currentCardIndex_ = 0;
};

#endif // CARDSUI_H
