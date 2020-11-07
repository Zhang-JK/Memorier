#include <iostream>
#include "MyDB.h"
#include "Record.h"

using namespace std;

int main() {
    // MyDB db;
    // db.initDB("laojk.club", "root", "45922622qaz", "enroll_general");
    // db.exeSQL("SELECT * FROM student_info LIMIT 1");

    // **Record Test**
    Record test1;
    Record test2(8);
    test1.set("a", "1").set("b", "2").set("c", "3").set("d", "4").set("e", "5");
    test2.set("a", "1").set("b", "2").set("c", "3").set("d", "4").set("e", "5");
    test2.set("a", "1").set("b", "2").set("c", "3").set("d", "4").set("e", "5");
    test2.set("a", "1!").set("b", "2!").set("f", "6").set("g", "7").set("h", "8").set("I", "9");

    test1.printForDebug(); test2.printForDebug();
    cout << test1.get("a") << "      " << test2["b"] << "      " << endl;
    if(test1["?"].empty())
        cout << "? do not exist" << endl;
    else
        cout << test1["?"];
}