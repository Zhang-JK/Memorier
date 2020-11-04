#ifndef _RECORD_H
#define _RECORD_H

#include <string>

using namespace std;

class Record {
public:
    Record();
    Record(int size);
    Record(Record& record);
    ~Record();
    void operator=(Record record);
    void operator[](string field);
    string get(string field);
    Record& set(string field, string data);
private:
    string * fieldList;
    string * dataList;
    int size;
    void expansion(int size);
};

#endif