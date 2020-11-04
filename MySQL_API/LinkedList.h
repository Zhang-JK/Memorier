#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

template <typename T>
class LinkedList {
public:
    LinkedList();
    LinkedList(LinkedList<T>& ll);
    ~LinkedList();
    void operator=(LinkedList<T> ll);
    void operator+=(T t);
    T operator[](int index);
    void add(T t);
    void remove();
    T Find(int index);
    bool isEmpty();
    int length();
private:
    struct Node{
        T data;
        Node* next;
    };
    T * head;
    T * tail;
    int length;
};

#endif