CFLAGS=-g -W -Wall -Werror -DDEBUG

List: SortedList.o List.o
	gcc -o List SortedList.o List.o -g

SortedList.o: SortedList.c SortedList.h
	gcc -c SortedList.c -o SortedList.o

List.o: List.c
	gcc -c List.c -o List.o

