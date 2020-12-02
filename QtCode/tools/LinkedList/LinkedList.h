#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <iostream>
using namespace std;

template<class T>
struct Node{
	Node<T> * prev;
	T * data;
	Node<T> * next;
};

template <class T>
class LinkedList {
public:
	LinkedList() {
		length = 0;
		head = new Node<T>;
		tail = new Node<T>;
		head->next = tail;
		head->prev = nullptr;
		tail->prev = head;
		tail->next = nullptr;
	}

	~LinkedList(){
		while(head != nullptr){
			delete head->data;
			Node<T> * temp = head;
			head = head->next;
			delete temp;
		}
	}

	typedef Node<T>* iterator;

	Node<T>* begin()
	{
		return head->next;
	}

	Node<T>* operator++()
	{
		return this->next;
	}

	LinkedList<T>& add(T * t) {
		if(t == nullptr) return *this;
		length++;
		Node<T> * temp = new Node<T>;
		temp->data = t;
		temp->next = tail;
		temp->prev = tail->prev;
		tail->prev->next = temp;
		tail->prev = temp;
		return *this;
	}

	LinkedList<T>& remove() {
		if(length == 0) return *this;
		length--;
		Node<T> * temp = tail->prev;
		temp->prev->next = tail;
		tail->prev = temp->prev;
		delete temp->data;
		delete temp;
		return *this;
	}

	LinkedList<T>& remove(int index) {
		if(length == 0) return *this;
		if(index < 0 || index >= length) return *this;
		length--;
		Node<T> * temp = getNode(index);
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp->data;
		delete temp;
		return *this;
	}

	T * get(int index) {
		return getNode(index)->data;
	}

	int getLength() const {
		return length;
	}

	// The Node Must Be PRINTABLE!!
	void printForDebug() const {
		cout << "-----PRINT_START-----" << endl;
		if(length == 0) { cout<<"EMPYT"<<endl; cout << "------PRINT_END------" << endl << endl; return ; }
		Node<T> * temp = head -> next;
		for(int i = 0; i < length; i++, temp = temp->next){
			if(i!=0) cout << "---------------------" << endl;
			cout << "Node NO." << i << endl;
			cout << *(temp->data) << endl;
			cout << "This: " << temp << "  Next: " << temp->next << "  Prev: " << temp->prev << endl;
		}
		cout << "------PRINT_END------" << endl << endl;
	}

	void operator+=(T t){ add(&t); }
	T * operator[](int index){ return get(index); }

private:
	Node<T> * head;
	Node<T> * tail;
	int length;

	Node<T> * getNode(int index){
		if(index < 0 || index >= length) return nullptr;
		Node<T> * temp = head -> next;
		for(int i=0; i < index; i++, temp=temp->next);
		return temp;
	}
};

#endif