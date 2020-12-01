#ifndef WORD_H_
#define WORD_H_

#include <vector>

#include "Card.h"
#include "APIRequest.h"

using std::vector;

class Word : public Card
{
private:
    QString trans;

public:
    Word();
    ~Word();
    virtual QString add_display(int) const;
    virtual QString option(int id = 0, QString str = "");
};

#endif /* WORD_H_ */
