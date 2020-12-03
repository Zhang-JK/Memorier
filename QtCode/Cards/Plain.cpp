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
    if(id==5)
    {
        return ans;
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
        return ans;
    }
    if(id==9)
    {
        if(str==ans) return "1";
        else return "0STD  answer:"+ans+'\n'+"Your answer:"+str+'\n';
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
