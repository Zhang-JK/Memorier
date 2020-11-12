#ifndef CARD_H_
#define CARD_H_

#include<string>
//#include "LinkedList.h"

using std::string;


class Card{
private:
	static const int FIX {5};
	static const int BFIX {200};
	static const int MIN_REV {5};
	
protected:
//	int proficiency;
//	double ac_rate;
	string title;
	int review_times;
	int ac_time;
	int timestamp;
	int lastime;
	int id;

const int MAX_PROFICIENCY=1000000;

public:
	int get_time() const;
	Card(int id);
	virtual ~Card();
	int get_proficiency() const;
	int get_id() const;
	void test();
	virtual int print_test() = 0;
	virtual void print() = 0;
	virtual void init() = 0;
	virtual void option() = 0;
	
};


#endif /* CARD_H_ */