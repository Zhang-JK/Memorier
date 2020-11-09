#include<cstdio>
#include "Text.h"
#include<iostream>
using namespace std;
int main()
{
	Card* a = new Text {1};
	cout<< a->get_proficiency()<<endl;
	while(1) a->option();
}