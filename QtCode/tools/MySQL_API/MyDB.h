#ifndef _MYDB_H
#define _MYDB_H
#include <iostream>
#include <string>
using namespace std;
#include "mysql.h"
#include "Record.h"
#include "../LinkedList/LinkedList.h"

class MyDB
{
    public:
    MyDB();
    ~MyDB();
    bool initDB(string host,string user,string pwd,string db_name); //连接mysql
    bool exeSQL(string sql);
    LinkedList<Record> * query(string sql);
    Record * queryFirst(string sql);
    Record * queryById(string table, int id);
    LinkedList<Record> * query(string table, Record& record);
    bool insert(Record& record);
    bool deleteById(int id);
    bool updata(Record& record);

    private:
    MYSQL *mysql;          //连接mysql句柄指针
    MYSQL_RES *result;    //指向查询结果的指针
    MYSQL_ROW row;       //按行返回的查询信息
};


#endif