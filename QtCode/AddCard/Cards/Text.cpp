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
    return "null";
}
