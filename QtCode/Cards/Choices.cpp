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
        choice.push_back(temp);
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
    return "null";
}
