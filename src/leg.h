#ifndef LEG_H
#define LEG_H

#include <QMainWindow>
#include <QWidget>
#include "processingCards.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class LEG;
}
QT_END_NAMESPACE

class LEG : public QMainWindow
{
    Q_OBJECT

public:
    LEG(std::string name = "deck", QWidget *parent = nullptr);
    ~LEG();

private slots:
    void on_pb_add_word_clicked();

    void on_pb_start_clicked();

    void on_le_choiceDeck_textChanged(const QString &arg1);

private:
    Ui::LEG *ui;
    std::string nameDeck_;
    CardsProcessingLEG cpLEG_;

    void setBackgroundWidget();
};
#endif // LEG_H
