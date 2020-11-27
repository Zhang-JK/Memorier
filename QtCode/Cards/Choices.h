#ifndef CHOICES_H_
#define CHOICES_H_

//#include "LinkedList.h"
#include<vector>
#include "Card.h"

using std::vector;

//helper struct
struct Cell{
    QString txt;
	bool ac;
};


class Choices: public Card{
private:
    QString hint;
    vector<Cell> choice;

public:
    Choices();
    ~Choices();
    virtual QString add_display(int) const;
    virtual QString option(int id =0 , QString str="");

};

#endif /* CHOICES_H_ */
