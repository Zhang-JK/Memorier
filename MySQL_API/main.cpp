#include <iostream>
#include "MyDB.h"

using namespace std;

int main() {
    MyDB db;
    db.initDB("laojk.club", "root", "45922622qaz", "enroll_general");
    db.exeSQL("SELECT * FROM student_info LIMIT 1");
}