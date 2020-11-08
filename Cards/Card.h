#ifndef CARD_H_
#define CARD_H_

#include<cstring>
#include "LinkedList.h"


class Card{
private:
//	int proficiency;
//	double ac_rate;
	string title;
	int review_times;
	int ac_time;
	int timestamp;
	int id;

public:
	const int MAX_PRO=1000000;
	const int MIN_REV=5;
	Card();
	virtual ~Card();
	int get_proficiency() const;
	int get_id() const;
	virtual void print() = 0;
	virtual void test() = 0;
	virtual void init() = 0;
	virtual void add();
	int get_time();
};


#endif /* CARD_H_ */