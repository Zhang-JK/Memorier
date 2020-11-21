#include "addchoices.h"
#include "ui_addchoices.h"

addChoices::addChoices(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::addChoices)
{
    ui->setupUi(this);
}

addChoices::~addChoices()
{
    delete ui;
}
