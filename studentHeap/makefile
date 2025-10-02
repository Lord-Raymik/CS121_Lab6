CC = g++
CFLAGS = -g -Wall

studentHeap: date.o address.o main.o
	$(CC) $(CFLAGS) date.o address.o main.o -o studentHeap

date.o: date.cpp date.h
	$(CC) $(CFLAGS) -c date.cpp

address.o: address.cpp addres.h
	$(CC) $(CFLAGS) -c address.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f *.o
	rm studentHeap

run: studentHeap
	./studentHeap

debug: studentHeap
	gdb studentHeap
