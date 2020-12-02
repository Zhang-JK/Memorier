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
        if(str=="$$$")
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
        QString ans = hint + "$$" + prob_all + "$$";
        for(int i = 0; i < quiz.size(); i++)
            ans += (QString::number(quiz[i].s) + ";" + QString::number(quiz[i].t) + ";");
        return ans;
    }
    if(id==4)
    {
        int i=0;
        while(str[i]!="$" || str[i+1]!="$") i++;
        hint = str.left(i);
        str.remove(0,i+2);
        i=0;
        while(str[i]!="$" || str[i+1]!="$") i++;
        prob_all = str.left(i);
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
    if(id==9)
    {
        int flag=1;
        QString out="";
        for(int i=0;i<quiz.size();i++)
        {
            int k=0;
            str=str+'\n';
            while(str[k]!='\n') k++;
            QString currentline = str.left(k);
            str.remove(0,k+1);
            if(k==quiz[i].t-quiz[i].s+1)
            {
                for(int j=quiz[i].s,l=0;j<=quiz[i].t;j++,l++)
                    if(prob_all[j]!=str[k]) flag=0;
            }
            else flag=0;
            out=out+currentline+"->";
            for(int j=quiz[i].s;j<=quiz[i].t;j++) out=out+prob_all[j];
            out=out+'\n';
        }
        if(flag) return "1";
        return '0'+out;
    }
    if(id==10)
    {
        QString out="";
        int k=0;
        for(int i=0;i<quiz.size();i++)
        {
            int mid=k;
            while(str[mid]!='-'&&str[mid+1]!='>') mid++;
            int l=mid+2;;
            while(k<mid&&str[l]!='\n')
            {
                if(str[k]!=str[l])
                {
                    out=out+QString::number(k)+'-'+QString::number(k)+';';
                    out=out+QString::number(l)+'-'+QString::number(l)+';';
                }
                k++,l++;
            }
            if(k<mid) out=out+QString::number(k)+'-'+QString::number(mid-1)+';';
            k=l;
            while(str[k]!='\n') k++;
            if(l<k) out=out+QString::number(l)+'-'+QString::number(k-1)+';';
            k++;
        }
        return out;
    }
    return "null";
}
