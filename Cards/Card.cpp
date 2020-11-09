#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#include<ctime>
#include "Card.h"

Card::Card(int id):
	review_times(0),
	ac_time(0),
	timestamp(get_time()),
	lastime(timestamp),
	id(id) //class wide globle variable?
{}

Card::~Card() = default;

const int Card::FIX;
const int Card::BFIX;
const int Card::MIN_REV;

int Card::get_proficiency() const
{
	if(review_times<MIN_REV)
	{
		int t=get_time()-timestamp;
		return static_cast<int>(0.5*exp(-(t*1.0/FIX))*MAX_PROFICIENCY);
	}
	else
	{
		int t=get_time()-lastime;
		return ac_time*1.0/review_times*exp(-(t*1.0/BFIX))*MAX_PROFICIENCY;
	}
}

int Card::get_id() const
{
	return id;
}

int Card::get_time() const
{
	return static_cast<int>(time(0))/86400;
}

void Card::test()
{
	int x=print_test();
	review_times++;
	ac_time+=x;
	lastime=get_time();
}