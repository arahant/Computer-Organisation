program: main.o util.o array.o prime.o hw1.o
	gcc -std=c99 main.o -o program
main.o: main.c
	gcc -std=c99 -c main.c -o main.o
util.o: util.c
	gcc -std=c99 -c util.c -o util.o
array.o: array.c
	gcc -std=c99 -c array.c -o array.o
prime.o: prime.c
	gcc -std=c99 -c prime.c -o prime.o
hw1.o: hw1.c
	gcc -std=c99 -c hw1.c -o hw1.o
clean:
	rm -f *.o program
