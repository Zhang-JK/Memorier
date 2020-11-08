#ifndef TEXT_H_
#define TEXT_H_

#include "LinkedList.h"
#include "Card.h"

//helper struct
struct Quiz{
	int s,t;
};


class Text: public Card{
private:
	string text;
	LinkedList<Quiz> quiz;
public:
	Text();
	~Text();
	virtual void print();
	virtual void init(); //To be add: auto generate
	virtual void test();
	virtual void add(); // add more quiz
};

#endif /* TEXT_H_