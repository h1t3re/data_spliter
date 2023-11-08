compile: test_spliter.c lib/strlen.o lib/strncmp.o lib/input_output.o lib/spliter.o
	gcc -Wall -g -o test_spliter lib/strlen.o lib/strncmp.o lib/input_output.o lib/spliter.o test_spliter.c
