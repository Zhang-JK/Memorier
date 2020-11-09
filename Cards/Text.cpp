#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#include<ctime>
#include "Text.h"
#include<vector>

using std::cin;
using std::cout;
using std::endl;

Text::Text(int id):Card(id)
{
	init();
}

Text::~Text() {}

void Text::print()
{
	//waiting GUI
}

void Text::init()
{
	cout << "Title:" << endl << ">";
	cin >> title;
	cout << "Text:" << endl << ">";
	cin >> text;
}

bool Text::print_test()
{
	int len = quiz.size();
//	LinkedList<Quiz>::iterator now = quiz.begin();
	sort(quiz.begin(),quiz.end());
	int j=0;
	for(int i=0;i<len;++i)
	{
		for(;j<quiz[i].s;++j) cout << text[j];
		for(;j<=quiz[i].t;++j) cout << '_'; 
	}
	int l=text.length();
	for(;j<=l;++j) cout << text[j];
	cout << endl;

	cout << "Fill in the blanks, print 'enter' after each blank" << endl;
//	now = quiz.begin();
	bool flag=1;
	for(int i=0;i<len;++i)
	{
		string st;
		cout << ">";
		cin >> st;
		l = st.length();
		bool bz=1;
		if(l==quiz[i].t-quiz[i].s+1)
		{
			for(int j=0;j<l;++j)
				bz &= (st[j]==text[quiz[i].s+j]);
		}
		else bz=0;
		if(bz) cout << "correct!" << endl;
		else cout << "wrong!" << endl;
		flag&=bz;
	}

	cout << "no more blank, 'Text' test end." << endl;

	return flag;
}

void Text::add()
{
	Quiz temp;
	cout << "Add a test, input start point and end point" << endl << ">" << endl;
	cin >> temp.s >> temp.t;   // warning: no valid check here
//	quiz.add(temp);
	quiz.push_back(temp);
}

void Text::elongate()
{
	cout << "Elogate the text. input changes:" << endl << ">";
	string temp;
	cin >> temp;
	text=text+temp;
}

void Text::option()
{
	cout << "Choose an option:" << endl;
	cout << "1. add a quiz" << endl;
	cout << "2. print test" << endl;
	cout << "3. elongate text" << endl;
	int x;
	cin >> x; // warning: no valid check here
	switch(x)
	{
		case 1:
			add();
			break;
		case 2:
			test();
			break;
		case 3:
			elongate();
			break;
	}
}
