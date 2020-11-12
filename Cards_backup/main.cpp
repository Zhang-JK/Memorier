#include<cstdio>
#include "Text.h"
#include "choices.h"
#include<iostream>
using namespace std;
int main()
{
	Card* a = new Text {1};
	cout<< a->get_proficiency()<<endl;
	Card* b = new Choices{2};
	while(1) b->option();
}