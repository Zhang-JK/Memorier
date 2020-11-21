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
	vector<Quiz> quiz;
	void add();
	void elongate();

public:
    Text();
	~Text();
	virtual void print();
	virtual void option();
	virtual int print_test();
};

#endif /* TEXT_H_ */
