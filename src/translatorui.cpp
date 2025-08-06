#include "translatorui.h"
#include "ui_translatorui.h"

#include "cards.h"
#include "logintranslator.h"

#include <QFile>

translatorUI::translatorUI(CardsProcessingLEG &cpLEG, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::translatorUI)
    , cpLEG_(cpLEG)
{
    ui->setupUi(this);
    ui->le_ru->setReadOnly(true);
    startTranslator();
}

translatorUI::~translatorUI()
{
    delete ui;
}

void translatorUI::addCard(const std::string &en, const std::string &ru)
{
    Card card;
    card.en = en;
    card.ru = ru;
    std::wstring u8RuWord(card.ru.begin(), card.ru.end());
    cpLEG_.saveCardsInDeck(card);
}

void translatorUI::startTranslator()
{
    if (!trans.checkSecretFile()) {
        loginTranslator window(this);
        window.setModal(true);
        window.exec();
    } else {
        trans.loadAPIAndFolderKeys();
    }
}

void translatorUI::on_pb_show_translate_clicked()
{
    if (ui->le_en->size().isEmpty())
        return;

    const QString qEn = ui->le_en->text();

    QString QafterRu = trans.translate(qEn);
    ui->le_ru->setText(QafterRu);
}

void translatorUI::on_pb_add_word_clicked()
{
    const QString qEn = ui->le_en->text();
    const QString qRu = ui->le_ru->text();

    const std::string en_str = qEn.toUtf8().constData();
    const std::string ru_str = qRu.toUtf8().constData();

    addCard(en_str, ru_str);
}
