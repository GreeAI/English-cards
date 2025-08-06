#ifndef LOGINTRANSLATOR_H
#define LOGINTRANSLATOR_H

#include <QDialog>

#include "translator.h"

using ApiFolderKeys = std::pair<QString, QString>;

namespace Ui {
class loginTranslator;
}

class loginTranslator : public QDialog
{
    Q_OBJECT

public:
    explicit loginTranslator(QWidget *parent = nullptr);
    ~loginTranslator();

    ApiFolderKeys returnApiAndFolder();

private slots:
    void on_pb_next_clicked();

private:
    Ui::loginTranslator *ui;

    translator trans;
};

#endif // LOGINTRANSLATOR_H
