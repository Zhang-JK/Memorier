#ifndef TEXT_H_
#define TEXT_H_

#include "Card.h"
#include<vector>

using std::vector;

//helper struct
struct Quiz{
	int s,t;
	bool operator<(Quiz b){return this->s<b.s;}
};


class Text: public Card{
private:
	string text;
//	LinkedList<Quiz> quiz;
	vector<Quiz> quiz;
	void add(); // add more quiz
	void elongate();
	virtual bool print_test();

public:
	Text(int id);
	~Text();
	virtual void print();
	virtual void init();
	virtual void option();
};

#endif /* TEXT_H_ */