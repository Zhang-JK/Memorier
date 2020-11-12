#ifndef WORD_H_
#define WORD_H_

#include "LinkedList.h"
#include "Card.h"


class Word: public Card{
private:
	string word;
	LinkedList<string> trans;
	void add();
public:
	Word();
	~Word();
	string get_word() const;
	virtual int print_test();
	virtual void print();
	virtual void init();
	virtual void option();
};

#endif /* WORD_H_ */