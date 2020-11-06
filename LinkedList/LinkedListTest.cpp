#include "LinkedList.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
    LinkedList<int> test;
    test.printForDebug();
    test.add(new int(5)).add(new int(10)).add(new int(15)).add(new int(20));
    cout << endl << "Test:" << test[3] << "   " << *test[2] << endl << endl;
    test.printForDebug();
    test.remove(1).remove(1);
    test.printForDebug();
    test.remove().remove();
    test.printForDebug();
}