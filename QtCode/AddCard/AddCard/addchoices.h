#ifndef ADDCHOICES_H
#define ADDCHOICES_H

#include <QMainWindow>

namespace Ui {
class addChoices;
}

class addChoices : public QMainWindow
{
    Q_OBJECT

public:
    explicit addChoices(QWidget *parent = nullptr);
    ~addChoices();

private:
    Ui::addChoices *ui;
};

#endif // ADDCHOICES_H
