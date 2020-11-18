#include "mainwindow.h"
#include "signupwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Memerior");

    QPixmap pixmap("./images/bg_resize.jpg"); //设定图片
    QPalette palette;                         //创建一个调色板对象
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);         //设置窗口调色板为palette，窗口和画笔相关联
    setAutoFillBackground(true); //设置窗体自动填充背景

    connect(ui->signButton, SIGNAL(clicked()), this, SLOT(openSignUp()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openSignUp()
{
    SignUpWindow *signUp = new SignUpWindow(this);
    connect(signUp, SIGNAL(sendLoginInfo(QString)), this, SLOT(receiveLoginInfo(QString)));
    signUp->show();
}

void MainWindow::receiveLoginInfo(QString account)
{
}
