#ifndef CHOICES_H_
#define CHOICES_H_

//#include "LinkedList.h"
#include<vector>
#include "Card.h"

using std::vector;

//helper struct
struct Cell{
	string txt;
	bool ac;
};


class Choices: public Card{
private:
	string question;
	vector<Cell> choice;
	void add_choice();
	void edit_choice();
	void elongate();

public:
	Choices(int id);
	~Choices();
	virtual void print();
	virtual void init();
	virtual void option();
	virtual int print_test();
};

#endif /* CHOICES_H_ */