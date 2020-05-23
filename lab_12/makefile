charts: program data 
	gnuplot plot.p

program: main.c
	gcc main.c -o program -lm -Wall

data: program
	./program

clean:
	rm -f *.jpg *.dat program