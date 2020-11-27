#ifndef WORD_H_
#define WORD_H_

#include <vector>

#include "Card.h"
#include "APIRequest.h"

using std::vector;

class Word : public Card
{
private:
    QString word;
    vector<string> trans;

public:
    Word();
    ~Word();
    virtual int print_test();
    virtual QString add(int);
    virtual void print();
    virtual QString option(int id = 0, QString str = "");
};

#endif /* WORD_H_ */
