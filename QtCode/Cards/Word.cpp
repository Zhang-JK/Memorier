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

Word::Word():Card()
{
    type = Card::cardType::Word;
}

Word::~Word() {}

QString Word::add_display(int x) const
{
    if(x==1) return "The title:";
    if(x==2) return "New word:";
    if(x==3) return "Translation:";
    return "null";
}

QString Word::option(int id, QString str)
{
    if(id==1)
    {
        trans = str;
        return "null";
    }
    if(id==2)
    {
        return translateAPI(str,"zh","en");
    }
    if(id==3)
    {
        return trans;
    }
    if(id==4)
    {
        trans=str;
        return "null";
    }
    if(id==5)
    {
        return trans;
    }
    if(id==6)
    {
        return "answer";
    }
    if(id==7)
    {
        return "null";
    }
    if(id==8)
    {
        return trans;
    }
    if(id==9)
    {
        if(str==trans) return "1";
        else return "0STD  answer:"+trans+'\n'+"Your answer:"+str+'\n';
    }
    if(id==10)
    {
        QString out="";
        int mid=0;
        while(str[mid]!='\n') mid++;
        int i=12,j=mid+13;
        while(str[i]!='\n'&&str[j]!='\n')
        {
            if(str[i]!=str[j])
            {
                out=out+QString::number(i)+'-'+QString::number(i)+';';
                out=out+QString::number(j)+'-'+QString::number(j)+';';
            }
            i++,j++;
        }
        for(;str[i]!='\n';i++)
            out=out+QString::number(i)+'-'+QString::number(i)+';';
        for(;str[j]!='\n';i++)
            out=out+QString::number(j)+'-'+QString::number(j)+';';
        return out;
    }
    return "null";
}
