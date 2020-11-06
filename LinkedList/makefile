CXX = g++
CXXFLAGS = -std=c++11
OBJS_DEBUG = main_debug.o

debug : main.out

main.out : $(OBJS_DEBUG)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS_DEBUG)

main_debug.o : LinkedListTest.cpp LinkedList.h
	$(CXX) $(CXXFLAGS) -g -c $< -o $@

clean :
	rm -f *.o *.out