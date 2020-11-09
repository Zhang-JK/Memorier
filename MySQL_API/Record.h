#ifndef _RECORD_H
#define _RECORD_H

#include <string>

using namespace std;

class Record {
public:
    Record();
    Record(int capacity);
    ~Record();
    string operator[](string field) const { return get(field); }
    string get(string field) const ;
    Record& set(string field, string data);
    string getField(int index) const ;
    int getLength() const ;
    void printForDebug() const ;
private:
    string * fieldList;
    string * dataList;
    int size;
    int DEFAULT_CAPACITY = 4;
    int capacity;
    void expansion(int newCapacity);
    int getIndex(string field) const ;
};

#endif