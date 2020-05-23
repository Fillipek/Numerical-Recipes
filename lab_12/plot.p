set term jpeg size 500,500

set xlabel "ilość węzłów"
set ylabel "|C-I|"

set logscale y

set out "plot_2a.jpg"
set title "m=0 k=1"
plot "calka_2a.dat" using 1:3 with points ps 2 pt 7 title ""

set out "plot_2b.jpg"
set title "m=1 k=1"
plot "calka_2b.dat" using 1:3 with points ps 2 pt 7 title ""

set out "plot_2c.jpg"
set title "m=5 k=5"
plot "calka_2c.dat" using 1:3 with points ps 2 pt 7 title ""