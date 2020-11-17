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

private:
    Ui::SignUpWindow *ui;
};

#endif // SIGNUPWINDOW_H
