FLAGS=-DUSECOLORS -Wall -g -DPRODUCTION 

strncmp.o: strncmp.c strncmp.h 
	gcc $(FLAGS) -c $^

install: strncmp.o strncmp.h
	cp -v strncmp.o ../lib/
	cp -v strncmp.h ../include/
