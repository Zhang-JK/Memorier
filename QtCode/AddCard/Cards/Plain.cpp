#include<iostream>
#include<cmath>
#include<cstring>
#include "Plain.h"


Plain::Plain():Card()
{}

Plain::~Plain() {}

void Plain::print()
{
	//waiting GUI
}

int Plain::print_test()
{

}


void Plain::option(int id, QString str)
{
    if(id==0) //add ans
    {
        ans=str;
    }
}
