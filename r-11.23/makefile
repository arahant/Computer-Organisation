program: main.o swap.o
	gcc -std=c99 main.o -o swap.out
main.o: main.c
	gcc -std=c99 -c main.c -o main.o
swap.o: swap.c
	gcc -std=c99 -c swap.c -o swap.o
clean:
	rm -f *.o *.out
