program: main.o util.o array.o prime.o
	gcc main.o -o program
util.o: util.c
	gcc -c util.c -o util.o
array.o: array.c
	gcc -c array.c -o array.o
prime.o: prime.c
	gcc -c prime.c -o prime.o
main.o: main.c
	gcc -c main.c -o main.o
clean:
	rm -f *.o program
