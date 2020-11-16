#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#include<ctime>
#include "Plain.h"

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
	cout << "Question:" << endl << ">";
	cin >> prob;
	cout << "Answer:" << endl << ">";
	cin >> ans;
}

int Text::print_test()
{
	cout << prob << endl;
	scanf("\n");
	cout << ans << endl;
	return -1;
}


void Text::option()
{
	cout << "Choose an option:" << endl;
	cout << "1. print test" << endl;
	cout << ">";
	int x;
	cin >> x; // warning: no valid check here
	switch(x)
	{
		case 1:
			test();
			break;
	}
}
