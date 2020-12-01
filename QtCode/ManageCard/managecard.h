#ifndef MANAGECARD_H
#define MANAGECARD_H

#include <QMainWindow>
#include <QLabel>
#include <QDateTime>

namespace Ui {
class ManageCard;
}

class ManageCard : public QMainWindow
{
    Q_OBJECT

public:
    explicit ManageCard(QWidget *parent = nullptr);
    ~ManageCard();

private slots:
    void setCostumRows();
    void deleteRow();
    void editRow();
    void selectOnTable();

private:
    Ui::ManageCard *ui;
    int selectedId = -1;
    QString selectedTitle = "";
    QLabel *labCellIndex; 
    void setRows(int type, QString title);
};

#endif // MANAGECARD_H
