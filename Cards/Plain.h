#ifndef Plain_H_
#define Plain_H_

#include "Card.h"


class Plain: public Card{
private:
	string prob;
	string ans;

public:
	Plain(int id);
	~Plain();
	virtual void print();
	virtual void init();
	virtual void option();
	virtual int print_test();
};

#endif /* Plain_H_ */