charts: program data
	gnuplot plot.p

program: main.c generators.c
	gcc main.c generators.c -o -O3 program -lm -Wall

data: program
	./program

clean:
	rm -f *.jpg *.dat program
