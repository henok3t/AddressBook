.PHONY: all

#compiler
CC = g++

#currentdir
CD = ~/Desktop/PROJECT/AddressBook

#include directories
LK = -I./LinkedList
AD = -I./address
ADL = -I./addresslist

all: addressbook

addressbook: main.cpp linkedlist.o address.o addresslist.o  
	$(CC) $(LK) $(AD) $(ADL) $^ -o $@

addresslist.o: ./addresslist/addresslist.cpp
	$(CC) $(LK) $(AD) -c $^ -o $@

address.o: ./address/address.cpp
	$(CC) $(LK) -c $^ -o $@

linkedlist.o: ./LinkedList/linkedlist.cpp
	$(CC) $(LK) -c $^ -o $@

clean:
	rm linkedlist.o address.o addresslist.o
