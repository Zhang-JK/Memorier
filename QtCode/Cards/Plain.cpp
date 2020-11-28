#include<iostream>
#include<cmath>
#include<cstring>
#include "Plain.h"


Plain::Plain():Card()
{
    type = Card::cardType::Plain;
}

Plain::~Plain() {}

QString Plain::add_display(int x) const
{
    if(x==1) return "The title:";
    if(x==2) return "The problem:";
    if(x==3) return "The answer:";
    return "null";
}

void Plain::print()
{
	//waiting GUI
}

int Plain::print_test()
{

}


QString Plain::option(int id , QString str)
{
    if(id==1) //add ans
    {
        ans=str;
        return "null";
    }
    if(id==3)
    {
        return ans;
    }
    if(id==4)
    {
        ans=str;
        return "null";
    }
    return "null";
}
