#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void libStart();

private slots:
    void receiveLoginInfo(QString account, int accountId);
    void directLogin();
    void openLogin();
    void openSignUp();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
