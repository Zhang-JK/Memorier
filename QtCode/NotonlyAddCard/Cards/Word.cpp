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

QString Word::add(int x)
{
    if(x==1) return "The title:";
    if(x==2) return "New word:";
    if(x==3) return "Translation:";
    return "null";
}

void Word::print()
{
	//waiting GUI
}


int Word::print_test()
{

}



QString Word::option(int id, QString str)
{
    if(id==1) word = str;
    if(id==2)
    {
        return translateAPI(str);
    }
    if(id==3)
    {
        QString ans = "";
        for(int i = 0; i < trans.size(); i++)
            ans += (QString::fromStdString(trans[i]) + ";" + QString::fromStdString(trans[i]) + ";");
        return ans;
    }
    return "null";
}
