#ifndef CARD_H_
#define CARD_H_

#include<string>
#include<QString>
//#include "Plain.h"
//#include "Text.h"
//#include "Word.h"
//#include "Choices.h"

//#include "LinkedList.h"

using std::string;


class Card{

public:
    enum cardType{Plain=0, Text=1, Word=2, Choices=3};
    static const QString typeName[4];
    QString title;
    QString prob;
	
protected:
//	int proficiency;
//	double ac_rate;
	int review_times;
	int ac_time;
    long timestamp;
    long lastime;
    long next_review;
	int id;
    cardType type;


public:
    Card();
	virtual ~Card();
    void set_id(int i);
    int get_id() const;
	cardType get_type() const;
    QString get_prob() const;
    QString get_title() const;
    long get_nextReview() const;
    void test_update(int);
    virtual QString add_display(int) const;
    virtual QString option(int id =0, QString str = "");
    void set_title(QString);
    void set_prob(QString);
    void set_init_time(long t);
	
};

// option id list:
// 1 - set answer for this card
// 2 - set special data for this card
// 3 - encode to storage
// 4 - decode
// 5 - get answer for this card (pair with 1)
// 6 - Butshow text for review
// 7 - extra button for review
// 8 - extra output for review



#endif /* CARD_H_ */
