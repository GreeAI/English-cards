#include "logintranslator.h"
#include "ui_logintranslator.h"

#include <QMessageBox>

#include <QDebug>

loginTranslator::loginTranslator(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loginTranslator)
{
    ui->setupUi(this);
    setFixedSize(400, 300);
    setWindowFlag(Qt::WindowMaximizeButtonHint, false);
    setWindowFlag(Qt::WindowMinimizeButtonHint, false);
}

loginTranslator::~loginTranslator()
{
    delete ui;
}

ApiFolderKeys loginTranslator::returnApiAndFolder()
{
    QLineEdit *QLeApi = ui->le_api;
    QLineEdit *QLeFolder = ui->le_folder;
    if (QLeApi->text().size() < 35 || QLeFolder->text().size() < 15)
        return {"1", "1"};
    ApiFolderKeys result_pair = std::make_pair(QLeApi->text(), QLeFolder->text());
    return result_pair;
}

void loginTranslator::on_pb_next_clicked()
{
    ApiFolderKeys keys = returnApiAndFolder();

    if (keys.first == "1") {
        QMessageBox::information(this, "Ошибка", "Неправильный размер ключей");
        return;
    }
    trans.saveAPIAndFolderKeys(keys.first, keys.second);

    close();
}
