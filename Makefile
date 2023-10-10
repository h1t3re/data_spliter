all : mem

FLAGS=-DUSECOLORS -Wall -g -DPRODUCTION -o
lib= lib/mem.o
DEP= mem
include= include/mem.h

compile: spliter.c $(lib) $(DEP)
	gcc $(FLAGS) spliter $< $(lib) $(include) -I lib 


