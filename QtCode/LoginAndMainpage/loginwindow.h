#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

signals:
    void sendLoginInfo(QString, int);

private slots:
    void inputValidator();

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
