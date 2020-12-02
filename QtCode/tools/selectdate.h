#ifndef SELECTDATE_H
#define SELECTDATE_H

#include <QDialog>
#include <QCheckBox>

namespace Ui {
class selectDate;
}

class selectDate : public QDialog
{
    Q_OBJECT

public:
    explicit selectDate(QWidget *parent = nullptr);
    ~selectDate();
    static QString get_selection()
        {return selection;}
    static QString get_selection_SQL(long);

protected:  
     void closeEvent(QCloseEvent *event); 

private:
    const int transform_days[7]={1,2,3,7,14,30,-1};
    Ui::selectDate *ui;
    QCheckBox* check[4];
    static QString selection;
    bool forceQuitFlag = true;

signals:
    void forceQuit();

private slots:
    void on_Butfinish_clicked();
    void on_CheckAll_clicked();
    void check_selection_all();
};

#endif // SELECTDATE_H
