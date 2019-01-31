main: basic harness stackalloc
	gcc -pthread -o main basic_loop.o process_harness.o stack_allocation.c

harness: process_harness.c
	gcc -pthread -c process_harness.c

basic: basic_loop.c
	gcc -c basic_loop.c

stackalloc: stack_allocation.c
	gcc -c stack_allocation.c
