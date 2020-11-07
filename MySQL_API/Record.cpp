#include "Record.h"
// #include "../LinkedList/LinkedList.h"

#include <string>
#include <iostream>
using namespace std;

Record::Record() : capacity(DEFAULT_CAPACITY), size(0) {
    fieldList = new string[DEFAULT_CAPACITY];
    dataList = new string[DEFAULT_CAPACITY];
}

Record::Record(int capacity) : capacity(capacity), size(0) {
    fieldList = new string[capacity];
    dataList = new string[capacity];
}

Record::~Record() {
    delete [] fieldList;
    delete [] dataList;
}

string Record::get(string field) {
    for(int i = 0; i < size; i++)
        if( fieldList[i] == field ) return dataList[i];
    return "";
}

Record& Record::set(string field, string data) {
    int index = getIndex(field);
    if(index >= 0) {
        dataList[index] = data;
        return *this;
    }
    if(size == capacity) expansion(capacity*2);
    fieldList[size] = field;
    dataList[size] = data;
    size++;
    return *this;
}

void Record::printForDebug() {
    cout << "-----PRINT_START-----" << endl;
    cout << "The capacity of the Record is " << capacity << endl;
    cout << "The size of the Record is " << size << endl;
    for(int i = 0; i < size; i++) {
        // cout << "---------------------" << endl;
        cout << fieldList[i] << "\t|\t" << dataList[i] << endl;
    }
    cout << "------PRINT_END------" << endl << endl;
}

void Record::expansion(int newCapacity) {
    string * tempField = new string[newCapacity];
    string * tempData = new string[newCapacity];
    for(int i = 0; i < size; i++) {
        tempField[i] = fieldList[i];
        tempData[i] = dataList[i];
    }
    delete [] fieldList;
    delete [] dataList;
    capacity = newCapacity;
    fieldList = tempField;
    dataList = tempData;
}

int Record::getIndex(string field) {
    for(int i = 0; i < size; i++)
        if( fieldList[i] == field ) return i;
    return -1;
}