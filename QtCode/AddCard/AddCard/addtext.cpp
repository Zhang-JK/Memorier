#include "addtext.h"
#include "ui_addtext.h"

addText::addText(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addText)
{
    ui->setupUi(this);
}

addText::~addText()
{
    delete ui;
}
