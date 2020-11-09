#include <iostream>
#include "MyDB.h"
#include "Record.h"

using namespace std;

int main() {

    // **Record Test**
    // Record test1;
    // Record test2(8);
    // test1.set("a", "1").set("b", "2").set("c", "3").set("d", "4").set("e", "5");
    // test2.set("a", "1").set("b", "2").set("c", "3").set("d", "4").set("e", "5");
    // test2.set("a", "1").set("b", "2").set("c", "3").set("d", "4").set("e", "5");
    // test2.set("a", "1!").set("b", "2!").set("f", "6").set("g", "7").set("h", "8").set("I", "9");

    // test1.printForDebug(); test2.printForDebug();
    // cout << test1.get("a") << "      " << test2["b"] << "      " << endl;
    // if(test1["?"].empty())
    //     cout << "? do not exist" << endl;
    // else
    //     cout << test1["?"];

    //**MyDB Test**
    MyDB db;
    db.initDB("laojk.club", "root", "45922622qaz", "enroll_general");
    // db.exeSQL("SELECT * FROM student_info");
    LinkedList<Record> * test = db.query("SELECT * FROM student_info LIMIT 5");
    for(int i = 0; i < test->getLength(); i++)
        (*test)[i]->printForDebug();
    delete test;

    cout << "################" << endl;
    Record * test2 = db.queryFirst("SELECT * FROM student_info");
    test2->printForDebug();
    delete test2;

    cout << "################" << endl;
    Record * test3 = new Record();
    test3 = db.queryById("student_info", 20);
    test3->printForDebug();
    delete test3;

    cout << "################" << endl;
    Record test4_1;
    test4_1.set("attr_id", "1").set("student_id", "1");
    LinkedList<Record> * test4_2 = db.query("student_info", test4_1);
    for(int i = 0; i < test4_2->getLength(); i++)
        (*test4_2)[i]->printForDebug();
    delete test4_2;
    return 0;
}