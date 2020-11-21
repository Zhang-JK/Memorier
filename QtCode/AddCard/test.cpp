#include "test.h"
#include "ui_test.h"
#include "AddCard/addcard.h"

test::test(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::test)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()), this, SLOT(addCard_push()));
}

void test::addCard_push()
{
    AddCard *addcard = new AddCard(this);
    connect(addcard, SIGNAL(addcard_sendInfo(Card*)), this ,SLOT(addCard_data(Card*)));
    addcard->show();
}

void test::addCard_data(Card* temp)
{
    int x=1;
    x=2;
}

test::~test()
{
    delete ui;
}

