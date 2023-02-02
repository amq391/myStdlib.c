
mem.o: mem.h mem.c
	gcc -fno-builtin -c mem.c mem.h

main.o: main.c mem.o
	gcc -fno-builtin main.c mem.o

run_tests: test.c mem.o
	gcc -fno-builtin test.c mem.o
