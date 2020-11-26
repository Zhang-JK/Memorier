#ifndef ADDCHOICES_H
#define ADDCHOICES_H

#include <QMainWindow>
#include <QTextEdit>
#include <QCheckBox>
#include "../Cards/Cards.h"

namespace Ui {
class addChoices;
}

class addChoices : public QMainWindow
{
    Q_OBJECT

public:
    explicit addChoices(QWidget *parent = nullptr);
    ~addChoices();
    void init();

signals:
    void second_finish();

private:
    Ui::addChoices *ui;
    QCheckBox* Inac[6];
    QTextEdit* Intxt[6];
    int num;

private slots:
    void on_Butadd_clicked();
    void on_Butfinish_clicked();
};

#endif // ADDCHOICES_H
