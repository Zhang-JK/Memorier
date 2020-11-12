#ifndef CARD_H_
#define CARD_H_

#include<string>
//#include "LinkedList.h"

using std::string;


class Card{
	
protected:
//	int proficiency;
//	double ac_rate;
	string title;
	int review_times;
	int ac_time;
	int timestamp;
	int lastime;
	int id;


public:
	int get_time() const;
	Card(int id);
	virtual ~Card();
	int get_id() const;
	int test();
	virtual int print_test() = 0;
	virtual void print() = 0;
	virtual void init() = 0;
	virtual void option() = 0;
	
};


#endif /* CARD_H_ */