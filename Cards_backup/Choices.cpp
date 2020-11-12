#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#include<ctime>
#include "Choices.h"
#include<vector>

using std::cin;
using std::cout;
using std::endl;

Choices::Choices(int id):Card(id)
{
	init();
}

Choices::~Choices() {}

void Choices::print()
{
	//waiting GUI
}

void Choices::init()
{
	cout << "Title:" << endl << ">";
	cin >> title;
	cout << "Question:" << endl << ">";
	cin >> question;
	cout << "Number of choices: " << endl << ">";
	int num;
	cin >> num;
	for(int i=0;i<num;i++)
	{
		add_choice();
	}
}

void Choices::add_choice()
{
	Cell temp;
	cout << "Choice " << choice.size()+1 << endl << ">";
	cin >> temp.txt;
	cout <<"Is this correct(1) or wrong(0)?" << endl << ">";
	int x;
	cin >> x;
	temp.ac = x>0;
	choice.push_back(temp);
}

void Choices::edit_choice()
{
	cout << "Edit choice no. ?" << endl << ">";
	int i;
	cin >> i;
	i--;
	cout << "Choice " << i+1 << endl << ">";
	cin >> choice[i].txt;
	cout <<"Is this correct(1) or wrong(0)?" << endl << ">";
	int x;
	cin >> x;
	choice[i].ac = x>0;
}

void Choices::elongate()
{
	cout << "Elogate the qustions. input changes:" << endl << ">";
	string temp;
	cin >> temp;
	question=question+temp;
}

bool Choices::print_test()
{
	bool flag=1;
	cout << question << endl;
	int num=choice.size(),ac_num=0;
	for(int i=0;i<num;i++)
	{
		cout << i+1 << ".  " << choice[i].txt << endl;
		ac_num+=choice[i].ac;
	}
	cout << ac_num << " correct answers in total" << endl;
	for(int i=0;i<ac_num;i++)
	{
		cout << "Correct answer " << i+1 << "  >";
		int x;
		cin >> x;
		flag&=(choice[x-1].ac); //no uniqueless checking
	}
	if(flag) cout << "correct!" << endl;
	else cout << "wrong" << endl;
	return flag;
}

void Choices::option()
{
	cout << "Choose an option:" << endl;
	cout << "1. add a choice" << endl;
	cout << "2. edit a choice" << endl;
	cout << "3. elongate question" << endl;
	cout << "4. print test" << endl;
	cout << ">";
	int x;
	cin >> x; // warning: no valid check here
	switch(x)
	{
		case 1:
			add_choice();
			break;
		case 2:
			edit_choice();
			break;
		case 3:
			elongate();
			break;
		case 4:
			print_test();
			break;
	}
}
