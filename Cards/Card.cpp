#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#include<ctime>
#include "Card.h"

using std::cin;
using std::cout;
using std::endl;

Card::Card(int id):
	review_times(0),
	ac_time(0),
	timestamp(get_time()),
	lastime(timestamp),
	id(id) //class wide globle variable?
{}

Card::~Card() = default;

int Card::get_id() const
{
	return id;
}

int Card::get_time() const
{
	return static_cast<int>(time(0))/86400;
}

int Card::test()
{
	print_test();
	cout << "1. remember well\n2.Have some point\n3.Bad guy!" << endl << ">";
	int x;
	cin >> x;
	lastime = get_time();
	return x;
}