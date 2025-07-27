#ifndef ADDWORD_H
#define ADDWORD_H

#include <QDialog>

#include "cards.h"
#include "processingCards.h"

#include <utility>

using PairEnRu = std::pair<std::string, std::string>;

namespace Ui {
class addWord;
}

class addWord : public QDialog
{
    Q_OBJECT

public:
    addWord(CardsProcessingLEG &cpLEG ,QWidget *parent = nullptr);
    ~addWord();

    void addCard(const std::string& en, const std::string& ru);
    PairEnRu parseStringWords();
    void printLastWords(const QString en, const QString ru);

private slots:
    void on_pushButton_clicked();

    void on_pb_quit_clicked();

private:
    Ui::addWord *ui;
    CardsProcessingLEG &cpLEG_;
};

#endif // ADDWORD_H
