#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring>
#include<ctime>
#include "Text.h"
#include<vector>


Text::Text():Card()
{
    type = Card::cardType::Text;
}

Text::~Text() {}


QString Text::add_display(int x) const
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
        if(str=="```")
        {
            prob_all=prob;
            for(int i=0;i<quiz.size();++i)
            {
                for(int j=quiz[i].s;j<=quiz[i].t;++j)
                {
                    prob[j] = ' ';
                }
            }
            return "null";
        }
        int x=0;
        while(str[x]!='-') x++;
        QString t=str;
        Quiz temp;
        temp.s=(t.left(x)).toInt();
        temp.t=(str.remove(0,x+1)).toInt();
        quiz.push_back(temp);
        return "null";
    }
    if(id==3)
    {
        QString ans = hint + ";;";
        for(int i = 0; i < quiz.size(); i++)
            ans += (QString::number(quiz[i].s) + ";" + QString::number(quiz[i].t) + ";");
        return ans;
    }
    if(id==4)
    {
        int i=0;
        while(str[i]!=";" || str[i+1]!=";") i++;
        hint = str.left(i);
        str.remove(0,i+2);
        while(str.size()>0)
        {
            Quiz temp;
            i=0;
            while(str[i]!=";") i++;
            temp.s=(str.left(i)).toInt();
            str.remove(0,i+1);
            i=0;
            while(str[i]!=";") i++;
            temp.t=(str.left(i)).toInt();
            str.remove(0,i+1);
            quiz.push_back(temp);
        }
        return "null";
    }
    if(id==5)
    {
        return hint;
    }
    if(id==6)
    {
        return "hint";
    }
    if(id==7)
    {
        return "Show answer";
    }
    if(id==8)
    {
        return prob_all;
    }
    return "null";
}
