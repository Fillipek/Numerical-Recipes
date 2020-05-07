set term jpeg size 500,500

set xlabel "i"
set ylabel "|x_{exact} - x_{est}|"

set logscale y


set title "f(x) - Golden"
set out "plotGf.jpg"
plot "wynikiGf.dat" using 1:3 with lines linewidth 2 title ""

set title "g(x) - Triple"
set out "plotGg.jpg"
plot "wynikiGg.dat" using 1:3 with lines linewidth 2 title ""

set title "f(x) - Golden"
set out "plotTf.jpg"
plot "wynikiTf.dat" using 1:3 with lines linewidth 2 title ""

set title "g(x) - Triple"
set out "plotTg.jpg"
plot "wynikiTf.dat" using 1:3 with lines linewidth 2 title ""
