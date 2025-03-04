# Makefile

CXX=clang++

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

wordTest: lab07Test.o tddFuncs.o WordCount.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f *.o wordCount wordTest