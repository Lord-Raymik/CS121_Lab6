CC = g++
CFLAGS = -g -Wall

studentHeap: date.o address.o student.o main.o
	$(CC) $(CFLAGS) date.o address.o main.o student.o -o studentHeap

date.o: date.cpp date.h
	$(CC) $(CFLAGS) -c date.cpp

address.o: address.cpp address.h
	$(CC) $(CFLAGS) -c address.cpp

student.o: student.cpp student.h address.h date.h
	$(CC) $(CFLAGS) -c student.cpp

main.o: main.cpp student.h address.h date.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f *.o
	rm studentHeap

run: studentHeap
	./studentHeap

debug: studentHeap
	gdb studentHeap
