#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#include<ctime>
#include "Text.h"
#include<vector>


Text::Text():Card()
{

}

Text::~Text() {}


QString Text::add(int x)
{
    if(x==1) return "The title:";
    if(x==2) return "The text:";
    if(x==3) return "Some hint:";
    return "null";
}

QString Text::option(int id, QString str)
{
    if(id==1)
    {
        hint=str;
        return "null";
    }
    if(id==2)
    {
        int x=0;
        while(str[x]!='-') x++;
        QString t=str;
        Quiz temp;
        temp.s=(t.left(x)).toInt();
        temp.t=(str.remove(0,x+1)).toInt();
        quiz.push_back(temp);
        return "null";
    }
    return "null";
}
