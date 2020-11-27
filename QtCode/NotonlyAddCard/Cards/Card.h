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
	int timestamp;
	int lastime;
	int id;
    cardType type;


public:
    Card();
	virtual ~Card();
	int get_id() const;
	int get_time() const;
	cardType get_type() const;
    QString get_prob() const;
	int test();
    virtual int print_test();
    virtual QString add(int);
    virtual void print();
    virtual QString option(int id =0, QString str = "");
    void set_title(QString);
    void set_prob(QString);
	
};


#endif /* CARD_H_ */
