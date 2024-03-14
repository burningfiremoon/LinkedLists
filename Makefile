all: test-OSLL test-OSULL

test-OSLL: test-OSLL.o
	g++ -Wall -o test-OSLL test-OSLL.o  

test-OSULL: test-OSULL.o
	g++ -Wall -o test-OSULL test-OSULL.o

test-OSULL.o: test-OSULL.cpp OSULL.h
	g++ -Wall -o test-OSULL.o -c test-OSULL.cpp

test-OSLL.o: test-OSLL.cpp OSLL.h 
	g++ -Wall -o test-OSLL.o -c test-OSLL.cpp 

clean:
	rm -f test-OSLL  *.o
	rm-f test-OSUll *.o
