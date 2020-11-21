#ifndef Plain_H_
#define Plain_H_

#include "Card.h"


class Plain: public Card{
private:
    QString ans;

public:
	Plain();
	~Plain();
    virtual void print();
    virtual void option(int id, QString str);
	virtual int print_test();
};

#endif /* Plain_H_ */
