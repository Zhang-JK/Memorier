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
    enum cardType{Plain, Text, Word, Choices};
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


public:
	int get_time() const;
    Card();
	virtual ~Card();
	int get_id() const;
	int test();
    virtual int print_test();
    virtual void print();
    virtual void option();
    virtual void option(int id, QString str);
    void set_title(QString);
    void set_prob(QString);
	
};


#endif /* CARD_H_ */
