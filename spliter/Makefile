spliter.o: spliter.c spliter.h ../lib/strlen.o ../lib/strncmp.o
	gcc -Wall -g -c spliter.c ../lib/strlen.o ../lib/strncmp.o

install: spliter.o
	cp -v spliter.o ../lib/spliter.o
	cp -v spliter.h ../include/spliter.h
