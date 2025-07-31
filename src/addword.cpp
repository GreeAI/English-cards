#include "addword.h"
#include "ui_addword.h"

#include <QDebug>
#include <QDir>

addWord::addWord(CardsProcessingLEG &cpLeg, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addWord)
    , cpLEG_(cpLeg)
{
    ui->setupUi(this);
    setFixedSize(350, 600);
    setWindowFlag(Qt::WindowMaximizeButtonHint, false);
    setWindowFlag(Qt::WindowMinimizeButtonHint, false);
}

addWord::~addWord()
{
    delete ui;

}

void addWord::addCard(const std::string& en, const std::string& ru) {
    Card card;
    card.en = en;
    card.ru = ru;
    std::wstring u8RuWord(card.ru.begin(), card.ru.end());
    cpLEG_.saveCardsInDeck(card);
}

void addWord::printLastWords(const QString en, const QString ru) {
    ui->lbl_en->setText(en);
    ui->lbl_ru->setText(ru);
}

void addWord::on_pushButton_clicked()
{
    const QString qEn = ui->en->text();
    const QString qRu = ui->ru->text();

    const std::string en_str = qEn.toUtf8().constData();
    const std::string ru_str = qRu.toUtf8().constData();


    addCard(en_str, ru_str);
    printLastWords(qEn, qRu);

    ui->en->clear();
    ui->ru->clear();

}


void addWord::on_pb_quit_clicked()
{
    close();
}

