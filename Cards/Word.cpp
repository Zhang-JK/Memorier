#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#include<ctime>
#include "Word.h"
#include<vector>

using std::cin;
using std::cout;
using std::endl;

Word::Word(int id):Card(id)
{
	init();
}

Word::~Word() {}

void Word::print()
{
	//waiting GUI
}

void Word::init()
{
	cout << "Title:" << endl << ">";
	cin >> title;
	cout << "Word:" << endl << ">";
	cin >> word;
	cout << "Number of trans?" << endl << "0 for auto generate" << endl << "-1 for leave blank" << endl << ">";
	int len;
	cin >> len;
	if(len==-1) return;
	if(len==0)
	{
		//TODO API
	}
	if(len > 0)
	{
		string temp;
		for(int i=0;i<len;i++)
		{
			cout << "trans " << i+1 << endl << ">";
			cin >> temp;
			trans.push_back(temp);
		}
	}
}

int Word::print_test()
{
	cout << word << endl;
	cout << "Enter to see answer" << endl;
	scanf("\n");
	int len=trans.size();
	for(int i=0;i<len;i++) cout << trans[i] << endl;
	return -1;
}

void Word::add()
{
	cout << "Add trans "<< trans.size()+1 << endl << ">" << endl;
	string temp;
	cin >> temp;
	trans.push_back(temp);
}

void Word::option()
{
	cout << "Choose an option:" << endl;
	cout << "1. add a trans" << endl;
	cout << "2. print test" << endl;
	cout << ">";
	int x;
	cin >> x; // warning: no valid check here
	switch(x)
	{
		case 1:
			add();
			break;
		case 2:
			print_test();
			break;
	}
}
