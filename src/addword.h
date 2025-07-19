#ifndef ADDWORD_H
#define ADDWORD_H

#include <QDialog>
#include "cards.h"
#include "processingCards.h"

namespace Ui {
class addWord;
}

class addWord : public QDialog
{
    Q_OBJECT

public:
    explicit addWord(QWidget *parent = nullptr);
    ~addWord();

    void addCard(const std::string& en, const std::string& ru);

private slots:
    void on_pushButton_clicked();

private:
    Ui::addWord *ui;
    CardsProcessingLEG cpLEG_;
};

#endif // ADDWORD_H
