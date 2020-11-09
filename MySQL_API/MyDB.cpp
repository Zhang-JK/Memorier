#include <iostream>
#include <string>
#include <sstream>
#include "MyDB.h"

using namespace std;

MyDB::MyDB()
{
    mysql=mysql_init(NULL);   //初始化数据库连接变量
    if(mysql==NULL)
    {
        cout<<"Error:"<<mysql_error(mysql)<<endl;
        exit(1);
    }
}

MyDB::~MyDB()
{
    if(mysql!=NULL)  //关闭数据连接
    {
        mysql_close(mysql);
        mysql_library_end();
    }
}


bool MyDB::initDB(string host,string user,string passwd,string db_name)
{
    // 函数mysql_real_connect建立一个数据库连接  
    // 成功返回MYSQL*连接句柄，失败返回NULL  
    mysql = mysql_real_connect(mysql, host.c_str(), user.c_str(), passwd.c_str(), db_name.c_str(), 0, NULL, 0);  
    if(mysql == NULL)  
    {  
        cout << "Error: " << mysql_error(mysql);  
        exit(1);  
    }  
    return true;  
}

bool MyDB::exeSQL(string sql)
{
    //mysql_query()执行成功返回0,执行失败返回非0值。
    if (mysql_query(mysql,sql.c_str()))
    {
        cout<<"Query Error: "<<mysql_error(mysql);
        return false;
    }
    else // 查询成功
    {
        result = mysql_store_result(mysql);  //获取结果集
        if (result)  // 返回了结果集
        {
            int num_fields = mysql_num_fields(result);   //获取结果集中总共的字段数，即列数
            int num_rows = mysql_num_rows(result);       //获取结果集中总共的行数
            for(int i=0;i<num_rows;i++) //输出每一行
            {
                //获取下一行数据
                row = mysql_fetch_row(result);
                if(row<0) break;

                for(int j=0;j<num_fields;j++)  //输出每一字段
                {
                    cout<<row[j]<<"\t\t";
                }
                cout<<endl;
            }
        }
        else  // result==NULL
        {
            if(mysql_field_count(mysql) == 0)   //代表执行的是update,insert,delete类的非查询语句
            {
                // (it was not a SELECT)
                int num_rows = mysql_affected_rows(mysql);  //返回update,insert,delete影响的行数
            }
            else // error
            {
                cout<<"Get result error: "<<mysql_error(mysql);
                return false;
            }
        }
        mysql_free_result(result);
    }
    return true;
}

LinkedList<Record> * MyDB::query(string sql) {
    if (mysql_query(mysql,sql.c_str()))
    {
        cout<<"Query Error: "<<mysql_error(mysql);
        return nullptr;
    }
    else // 查询成功
    {
        result = mysql_store_result(mysql);  //获取结果集
        if (result)  // 返回了结果集
        {
            int num_fields = mysql_num_fields(result);   
            int num_rows = mysql_num_rows(result);       
            MYSQL_FIELD* fields = mysql_fetch_fields(result);
            // string fields[num_fields + 1];
            // for(int i = 0; i < num_fields; i++)
            //     fields[i] = mysql_fetch_fields(result)[i]->name;

            LinkedList<Record> * list = new LinkedList<Record>();
            for(int i=0;i<num_rows;i++)
            {
                Record* record = new Record();
                row = mysql_fetch_row(result);
                if(row<0) break;
                for(int j=0;j<num_fields;j++)
                    (*record).set(fields[j].name, row[j] == NULL ? "_NULL_" : row[j]);
                list->add(record);
            }
            // delete fields;
            mysql_free_result(result);
            return list;
        }
        else
        {
            cout<<"Not a query statement!"<<endl;
            return nullptr;
        }
    }
}

Record * MyDB::queryFirst(string sql) {
    if (mysql_query(mysql,sql.c_str()))
    {
        cout<<"Query Error: "<<mysql_error(mysql);
        return nullptr;
    }
    else // 查询成功
    {
        result = mysql_store_result(mysql);  //获取结果集
        if (result)  // 返回了结果集
        {
            int num_fields = mysql_num_fields(result);   
            int num_rows = mysql_num_rows(result);       
            MYSQL_FIELD* fields = mysql_fetch_fields(result);

            Record * record = new Record();
            row = mysql_fetch_row(result);
            if(row >= 0) 
                for(int j=0;j<num_fields;j++)
                    (*record).set(fields[j].name, row[j] == NULL ? "_NULL_" : row[j]);
            else {
                mysql_free_result(result);
                return nullptr;
            }
            mysql_free_result(result);
            return record;
        }
        else
        {
            cout<<"Not a query statement!"<<endl;
            return nullptr;
        }
    }
}

Record * MyDB::queryById(string table, int id) {
    stringstream ss;
    ss << "SELECT * FROM " << table << " WHERE id = " << id;
    return queryFirst(ss.str());
}

LinkedList<Record> * MyDB::query(string table, Record& record) {
    stringstream ss;
    ss << "SELECT * FROM " << table << " WHERE ";
    for(int i = 0; i < record.getLength(); i++) {
        ss << record.getField(i) << " = " << record[record.getField(i)];
        if(i != record.getLength() - 1) ss << " AND ";
    }
    return query(ss.str());
}