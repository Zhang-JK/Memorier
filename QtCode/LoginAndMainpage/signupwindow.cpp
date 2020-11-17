#include "signupwindow.h"
#include "ui_signupwindow.h"

SignUpWindow::SignUpWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::SignUpWindow)
{
    ui->setupUi(this);
    setWindowTitle("SignUp");
    setFixedSize(600, 350);
}

SignUpWindow::~SignUpWindow()
{
    delete ui;
}
