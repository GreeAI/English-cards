#ifndef TRANSLATORUI_H
#define TRANSLATORUI_H

#include <QDialog>
#include <QLineEdit>

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

private slots:
    void on_pb_show_translate_clicked();

    void on_pb_add_word_clicked();

    void on_pb_change_lang_clicked();

private:
    Ui::translatorUI *ui;

    translator trans;
    loginTranslator loginTranslator_;

    CardsProcessingLEG &cpLEG_;

    QLineEdit *&leFirst;  // LineEdit - ввод англ слова
    QLineEdit *&leSecond; // LineEdit - вывод ру слова

    bool checkLang = false; // False En->Ru, True Ru->En
    const QString ruLang_ = "ru";
    const QString enLang_ = "en";

    void setupUI();
    void startTranslator();

    void addCard(const std::string &en, const std::string &ru);

    bool isRussianWord(const QString &word);
    bool isEnglishWord(const QString &word);

    void erorConnection();
    bool checkErrorLanguage(const QString &word);

    void changeLang();
    bool validateInput(const QString &word);

    QString performTranslation(const QString &word);
    void prepareAndAddCard(const QString &first, const QString &second);
};

#endif // TRANSLATORUI_H
