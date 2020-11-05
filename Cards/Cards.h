#ifndef CARDS_H_
#define CARDS_H_

#include<cstring>

//helper structs
struct Quiz{
	int st,en;
};


//Card classes

class Card{
protected:
//	int proficiency;
	string title;
	double ac_rate;
	int review_times;
	int timestamp;
	int id;
public:
	Card();
	~Card();
	int get_proficiency();
	virtual void print();
	virtual void test();
	virtual void init();
};

class Word: public Card{
private:
	string word;
	int num_trans;
	string* trans;
public:
	Word();
	~Word();
	void get_word();
	virtual void print();
	virtual void init(); //trans API here
	virtual void test();
};

class Text: public Card{
private:
	string text;
	int num_quiz;
	Quiz* quizs;
public:
	Text();
	~Text();
	virtual void print();
	virtual void init(); //To be add: auto generate
	virtual void test();
};

class Choices: public Card{
private:
	string question;
	int num_choices;
	string* choices;
	int num_ac;
	int* ac;
public:
	Choices();
	~Choices();
	virtual void print();
	virtual void init();
	virtual void test();
};

#endif /* CARDS_H_ */