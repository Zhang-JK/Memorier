#include<algorithm>
#include "Choices.h"
#include<vector>


Choices::Choices():Card()
{
}

Choices::~Choices() {}


QString Choices::add(int x)
{
    if(x==1) return "The title:";
    if(x==2) return "The problem:";
    if(x==3) return "Some hint:";
    return "null";
}

QString Choices::option(int id , QString str)
{
    if(id==1) //add ans
    {
        Cell temp;
        int n=str.length();
        temp.txt=str;
        temp.txt.remove(n-1,1);
        temp.ac=(str[n-1]=="T");
        choice.push_back(temp);
    }
    return "null";
}
