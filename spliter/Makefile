FLAGS=-Wall -g

spliter.o: spliter.c spliter.h
	gcc $(FLAGS) -c $^ ../lib/strncmp.o ../lib/strlen.o

install: spliter.o spliter.h
	echo "Coping files ... "
	cp -v spliter.o ../lib/spliter.o
	cp -v spliter.h ../include/spliter.h
