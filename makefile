all: Signal.o
	gcc -o sig Signal.o

stats.o: Signal.c Signal.h
	gcc -c -g Signal.c

run: all
	./sig

clean:
	rm *~
	rm *.o
