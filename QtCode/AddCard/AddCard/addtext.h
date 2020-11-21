#ifndef ADDTEXT_H
#define ADDTEXT_H

#include <QMainWindow>

namespace Ui {
class addText;
}

class addText : public QMainWindow
{
    Q_OBJECT

public:
    explicit addText(QWidget *parent = nullptr);
    ~addText();

private:
    Ui::addText *ui;
};

#endif // ADDTEXT_H
