#ifndef CHOICES_H_
#define CHOICES_H_

#include "LinkedList.h"
#include "Card.h"

//helper struct
struct single{
	string txt;
	bool corect;
};


class Choices: public Card{
private:
	string question;
	Linked_List<single> choice;
	bool multi;

public:
	Choices();
	~Choices();
	virtual void print();
	virtual void init();
	virtual void test();
	virtual void add(); //add more choice
};

#endif /* CHOICES_H_ */