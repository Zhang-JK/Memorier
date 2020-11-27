#include<cmath>
#include<cstring>
#include<ctime>
#include "Card.h"

const QString Card::typeName[4]={"Plain", "Text", "Word", "Choices"};


Card::Card():
	review_times(0),
	ac_time(0),
	timestamp(get_time()),
	lastime(timestamp),
    id(0)
{}

Card::~Card() = default;

int Card::get_id() const
{
	return id;
}

Card::cardType Card::get_type() const
{
    return type;
}

QString Card::get_prob() const
{
    return prob;
}

int Card::get_time() const
{
	return static_cast<int>(time(0))/86400;
}

int Card::test()
{

}

void Card::set_title(QString title_)
{
    title=title_;
}

void Card::set_prob(QString prob_)
{
    prob=prob_;
}

int Card::print_test(){}

void Card::print(){}

QString Card::add(int x){return "null";}

QString Card::option(int id, QString str){return "null";}


