CC = gcc
DEPS = lib.h  #dependency

#de tim file trong folder ma it folder
#CFLAGS = -I inc  #Co,(-I.) tim thu muc root hien tai (../../ lui 1 folder), (-I inc) tim them trong inc
#VPATH = src

#de tim file trong folder ma nhiu folder
INC_DIR := ./inc ./core ./a ./b
SRC_DIR := ./src ./core

CFLAGS= $(foreach INC_DIR, $(INC_DIR), -I$(INC_DIR))

VPATH = $(foreach SRC_DIR, $(SRC_DIR), $(SRC_DIR))


#thay cho lib.o: lib.c
#	      	  $(CC) -c lib.c -o lib.o -I./inc
%.o: %.c $(DEPS)
	$(CC) -c $< -o $@ $(CFLAS)

#ko co -I. lam tung buoc (-I. tim trong root thoi)
al: main.o lib.o
	gcc main.o lib.o -o main.exe 

all: main.c lib.c
	gcc main.c lib.c -o main.exe -I./inc

.PHONY: clean
clean:
	rm -f *.exe *.o