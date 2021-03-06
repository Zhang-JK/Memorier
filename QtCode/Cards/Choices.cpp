#include<algorithm>
#include "Choices.h"
#include<vector>


Choices::Choices():Card()
{
    type = Card::cardType::Choices;
}

Choices::~Choices() {}


QString Choices::add_display(int x) const
{
    if(x==1) return "The title:";
    if(x==2) return "The problem:";
    if(x==3) return "Some hint:";
    return "null";
}

QString Choices::option(int id , QString str)
{
    if(id==1)
    {
        hint = str;
        return "null";
    }
    if(id==2) //add ans
    {
        Cell temp;
        int n=str.length();
        temp.txt=str;
        temp.txt.remove(n-1,1);
        temp.ac=(str[n-1]=="T");
        prob = prob + '\n' + '\n' + (choice.size()+'A') + ". " + temp.txt ;
        choice.push_back(temp);
        return "null";
    }
    if(id==3) {
        QString ans = hint + ";;";
        for(int i = 0; i < choice.size(); i++)
            ans += (choice[i].txt + (choice[i].ac ? ";;1;;" : ";;0;;"));    // choice1;;0;;choice2;;0;;choice3;;0;;choice4;;1;;
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
            i=0;
            while(str[i]!=";" || str[i+1]!=";") i++;
            Cell temp;
            temp.txt=str.left(i);
            temp.ac=(str[i+2]=="1"?1:0);
            choice.push_back(temp);
            str.remove(0,i+5);
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
        QString ans="";
        for(int i=0;i<choice.size();++i)
        {
            if(choice[i].ac) ans=ans+(i+'A');
        }
        return ans;
    }
    if(id==9)
    {
        QString ans=option(8);
        if(str==ans) return "1";
        int flag=0;
        for(int i=0;i<str.length();i++)
            if(str[i]<'A'||str[i].toLatin1()-'A'>=choice.size())
                flag=1;
        if(flag) str="";
        return "0Correct answer: "+ans + '\n'+"Your answer: "+str+'\n';
    }
    if(id==10)
    {
        QString out="";
        int mid=0;
        while(str[mid]!='\n') mid++;
        int i=mid+14;
        int* flag = new int [choice.size()] {0};
        while(str[i]!='\n')
        {
            int id=str[i].toLatin1()-'A';
            flag[id]=1;
            if(choice[id].ac==false)
                out=out+QString::number(i)+'-'+QString::number(i)+';';
            i++;
        }
        i=16;
        while(str[i]!='\n')
        {
            int id=str[i].toLatin1()-'A';
            if(flag[id]==0)
                out=out+QString::number(i)+'-'+QString::number(i)+';';
            i++;
        }
        delete [] flag;
        return out;
    }
    return "null";
}
