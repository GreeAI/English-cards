#include "addword.h"
#include "ui_addword.h"

#include <QDebug>
#include <QDir>

addWord::addWord(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addWord)
{
    ui->setupUi(this);
}

addWord::~addWord()
{
    delete ui;
}

void addWord::addCard(const std::string& en, const std::string& ru) {
    qDebug() << "Current dir:" << QDir::currentPath();
    qDebug() << "App dir:" << QCoreApplication::applicationDirPath();
    Card card;
    card.en = en;
    card.ru = ru;
    std::wstring u8RuWord(card.ru.begin(), card.ru.end());
    cpLEG_.saveCardsInDeck(card);
}

void addWord::on_pushButton_clicked()
{
    QString en = ui->en->text();
    QString ru = ui->ru->text();

    const std::string en_str = en.toUtf8().constData();
    const std::string ru_str = ru.toUtf8().constData();

    addCard(en_str, ru_str);
}

