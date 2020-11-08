#ifndef WORD_H_
#define WORD_H_

#include "LinkedList.h"
#include "Card.h"


class Word: public Card{
private:
	string word;
	LinkedList<string> trans;
public:
	Word();
	~Word();
	string get_word() const;
	virtual void print();
	virtual void init(); //trans API here
	virtual void test();
	virtual void add(); // add trans list
};

#endif /* WORD_H_ */