#include "translatorui.h"
#include "ui_translatorui.h"

#include "cards.h"
#include "logintranslator.h"

#include <QFile>

#include <QMessageBox>
#include <QRegularExpression>

translatorUI::translatorUI(CardsProcessingLEG &cpLEG, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::translatorUI)
    , cpLEG_(cpLEG)
    , leFirst(ui->le_first)
    , leSecond(ui->le_second)
{
    setupUI();
    startTranslator();
}

translatorUI::~translatorUI()
{
    delete ui;
}

void translatorUI::setupUI()
{
    ui->setupUi(this);
    leSecond->setReadOnly(true);
    setFixedSize(350, 600);
    setWindowFlag(Qt::WindowMaximizeButtonHint, false);
    setWindowFlag(Qt::WindowMinimizeButtonHint, false);
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

// Private slots - buttons

void translatorUI::on_pb_show_translate_clicked()
{
    const QString text = leFirst->text();
    if (!validateInput(text))
        return;

    QString translated = performTranslation(text);
    if (!translated.isEmpty()) {
        leSecond->setText(translated);
    }
}

void translatorUI::on_pb_add_word_clicked()
{
    const QString first = leFirst->text();
    const QString second = leSecond->text();

    if (!validateInput(first) || second == "Translation error") {
        if (second == "Translation error")
            erorConnection();
        return;
    }

    prepareAndAddCard(first, second);
}

void translatorUI::on_pb_change_lang_clicked()
{
    checkLang = !checkLang;
    changeLang();
}

// Private methods

void translatorUI::addCard(const std::string &en, const std::string &ru)
{
    Card card;
    card.en = en;
    card.ru = ru;
    std::wstring u8RuWord(card.ru.begin(), card.ru.end());
    cpLEG_.saveCardsInDeck(card);
}

bool translatorUI::isRussianWord(const QString &word)
{
    static QRegularExpression cyrillicRegex("[а-яА-ЯёЁ]+");
    return cyrillicRegex.match(word).hasMatch();
}

bool translatorUI::isEnglishWord(const QString &word)
{
    static QRegularExpression latinRegex("[a-zA-Z]+");
    return latinRegex.match(word).hasMatch();
}

bool translatorUI::checkErrorLanguage(const QString &word)
{
    if (checkLang && !isRussianWord(word)) {
        QMessageBox::warning(this, "Ошибка", "Введите слово на Русском языке");
        return false;
    }

    if (!checkLang && !isEnglishWord(word)) {
        QMessageBox::warning(this, "Ошибка", "Введите слово на Английском языке");
        return false;
    }

    return true;
}

void translatorUI::changeLang()
{
    if (checkLang == true) {
        trans.setSourceLang(ruLang_);
        trans.setTargetLang(enLang_);
        ui->pb_change_lang->setText("Рус->Англ");
        ui->label->setText("Введите слово на Русском");
    } else {
        trans.setSourceLang(enLang_);
        trans.setTargetLang(ruLang_);
        ui->pb_change_lang->setText("Англ->Рус");
        ui->label->setText("Введите слово на Английском");
    }
}

void translatorUI::erorConnection()
{
    QMessageBox::warning(this, "Ошибка", "Ошибка, проверьте API или Folder ключи");
    trans.clearKeysFile();
    hide();
    translatorUI trans(cpLEG_, this);
    trans.setModal(true);
    trans.exec();
    show();
}

bool translatorUI::validateInput(const QString &word)
{
    if (word.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Поле ввода не может быть пустым");
        return false;
    }
    if (!leSecond->text().isEmpty() && leSecond->text().toLower() == word.toLower()) {
        QMessageBox::warning(this,
                             "Ошибка",
                             "Перевод совпадает с исходным словом. Возможно, слово не существует.");
        return false;
    }
    return checkErrorLanguage(word);
}

QString translatorUI::performTranslation(const QString &word)
{
    QString translated = trans.translate(word);
    if (translated == "Translation error") {
        erorConnection();
        return QString();
    }
    return translated;
}

void translatorUI::prepareAndAddCard(const QString &first, const QString &second)
{
    std::string en_str, ru_str;

    if (checkLang) {
        en_str = second.toUtf8().constData();
        ru_str = first.toUtf8().constData();
    } else {
        en_str = first.toUtf8().constData();
        ru_str = second.toUtf8().constData();
    }

    addCard(en_str, ru_str);
}
