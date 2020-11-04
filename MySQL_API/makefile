CXX = g++
CXXFLAGS = -std=c++11
OBJS = MyDB.o main.o
OBJS_DEBUG = main_debug.o MyDB_debug.o
SQL_LIB = -I/usr/include/mysql

all : release.out

release.out : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) `mysql_config --cflags --libs`

MyDB.o : MyDB.cpp MyDB.h
	$(CXX) $(CXXFLAGS) $(SQL_LIB) -c $< -o $@

main.o : main.cpp MyDB.h
	$(CXX) $(CXXFLAGS) $(SQL_LIB) -c $< -o $@

debug : main.out

main.out : $(OBJS_DEBUG)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DEBUG) `mysql_config --cflags --libs`

MyDB_debug.o : MyDB.cpp MyDB.h
	$(CXX) $(CXXFLAGS) $(SQL_LIB) -g -c $< -o $@

main_debug.o : main.cpp MyDB.h
	$(CXX) $(CXXFLAGS) $(SQL_LIB) -g -c $< -o $@

clean :
	rm -f *.o *.out