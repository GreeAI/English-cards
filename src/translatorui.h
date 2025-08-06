#ifndef TRANSLATORUI_H
#define TRANSLATORUI_H

#include <QDialog>
#include "logintranslator.h"
#include "processingCards.h"
#include "translator.h"

namespace Ui {
class translatorUI;
}

class translatorUI : public QDialog
{
    Q_OBJECT

public:
    explicit translatorUI(CardsProcessingLEG &cpLEG, QWidget *parent = nullptr);
    ~translatorUI();

    void addCard(const std::string &en, const std::string &ru);

    void startTranslator();

private slots:
    void on_pb_show_translate_clicked();

    void on_pb_add_word_clicked();

private:
    Ui::translatorUI *ui;

    translator trans;
    loginTranslator loginTranslator_;

    CardsProcessingLEG &cpLEG_;
};

#endif // TRANSLATORUI_H
