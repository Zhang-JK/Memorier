#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class SignUpWindow;
}
QT_END_NAMESPACE

class SignUpWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit SignUpWindow(QWidget *parent = nullptr);
    ~SignUpWindow();

signals:
    void sendLoginInfo(QString, int);

private slots:
    void inputValidator();

private:
    Ui::SignUpWindow *ui;
    bool updateUserData(QString, QString);
};

#endif // SIGNUPWINDOW_H
