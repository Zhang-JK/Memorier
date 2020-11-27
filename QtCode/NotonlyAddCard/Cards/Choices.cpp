#include<algorithm>
#include "Choices.h"
#include<vector>


Choices::Choices():Card()
{
    type = Card::cardType::Choices;
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
    if(id==1)
    {
        hint = str;
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
        QString ans = "";
        for(int i = 0; i < choice.size(); i++)
            ans += (choice[i].txt + (choice[i].ac ? ";;1;;" : ";;0;;"));    // choice1;;0;;choice2;;0;;choice3;;0;;choice4;;1;;
        return ans;
    }
    return "null";
}
