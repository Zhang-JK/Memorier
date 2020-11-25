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
	void elongate();

public:
    Text();
    ~Text();

    virtual QString add(int);
    virtual QString option(int id =0 , QString str="");
};

#endif /* TEXT_H_ */
