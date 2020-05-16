charts: program data 
	mkdir -p charts
	gnuplot plot.p

program: main.c
	gcc main.c -o program -lm -lgsl -lgslcblas -Wall

data: program
	./program

clean:
	rm -rf charts data program