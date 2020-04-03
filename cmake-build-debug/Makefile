# A5_368
# Joseph McFarland
# 9072511679
# mcfarland3@wisc.edu

CXX = g++
CXXFLAGS = -Wall -g

InfiniteInt.o: InfiniteInt.cpp InfiniteInt.h
	$(CXX) $(CXXFLAGS) -c InfiniteInt.cpp

demo.o: demo.cpp InfiniteInt.h
	$(CXX) $(CXXFLAGS) -c demo.cpp

clean:
	-rm InfiniteInt.o
	-rm demo.o
	-rm InfiniteInt

SummarizeGrades: demo.o SummarizeGrades.o
	$(CXX) $(CXXFLAGS) -o InfiniteInt demo.o InfiniteInt.o
