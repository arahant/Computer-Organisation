program: main.o node1d.o node2d.o
	gcc -std=c99 main.o -o htable
main.o: main.c
	gcc -std=c99 -c main.c -o main.o
node1d.o: node1d.c
	gcc -std=c99 -c node1d.c -o node1d.o
node2d.o: node2d.c
	gcc -std=c99 -c node2d.c -o node2d.o
clean:
	rm -f *.o *.out htable
