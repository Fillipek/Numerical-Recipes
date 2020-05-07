charts: run
	gnuplot plot.p

program: main.c funs.c
	gcc -o program main.c funs.c -lm

run: program
	./program

clean:
	rm -f *.dat *.jpg program
