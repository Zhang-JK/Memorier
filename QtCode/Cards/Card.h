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
    long next_test;
	int id;
    cardType type;


public:
    Card();
	virtual ~Card();
    

    int get_id() const;
    int get_review_time() const;
    int get_ac_time() const;
	cardType get_type() const;
    QString get_prob() const;
    QString get_title() const;
    long get_nextReview() const;
    long get_nextTest() const;

    void test_update(int);
    virtual QString add_display(int) const;              // Display message for AddCard
    virtual QString option(int id =0, QString str = ""); // main overloading function, please refer to id list below

    void set_id(int i);
    void set_title(QString);
    void set_prob(QString);
    void set_init_time(long t);
    void set_next_time(long t);
    void set_review_time(int times);
    void set_ac_time(int times);
};

// option id list:
// 1 - set answer for this card
// 2 - set special data for this card
// 3 - encode to storage
// 4 - decode
// 5 - get answer/hint for this card (pair with 1)
// 6 - Butshow text for review
// 7 - extra button for review
// 8 - extra output for review (get full answer)
// 9 - return side-to-side compare version correct answer when test::submit
// 10 - return noting for side-to-side compare when test::submit



#endif /* CARD_H_ */
