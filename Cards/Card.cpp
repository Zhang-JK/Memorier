#include<algorithm>
#include<iostream>
#include<cmath>
#include "Card.h"

Card::Card(int id):
	review_times(0),
	ac_time(0),
	timestamp(time(0)),
	id(id) //class wide globle variable?
	{}

int Card::get_proficiency()
{
	static? const int FIX=5;
	int t=get_time()-timestamp;
	if(review_times<MIN_REV)
	{
		return static_cast<int>(exp(-(t*1.0/FIX))*MAX_PRO);
	}
	else
	{
		return ac_time*1.0/review_times*0.5*MAX_PRO;
	}
}

int Card::get_id() const
{
	return id;
}

int Card::get_time()
{
	return static_cast<int>(time(0))/86400;
}