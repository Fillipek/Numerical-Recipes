set term jpeg size 500, 500
set print "-"

set xlabel "x"
set ylabel "y"

set title "Generator 1, offset = 0"
set out "plot_1a.jpg"
plot "generator_1a.dat" using 1:2 with points ps 0.5 pt 7 lt rgb "red" title ""

set title "Generator 1, offset = 1"
set out "plot_1b.jpg"
plot "generator_1b.dat" using 1:2 with points ps 0.5 pt 7 lt rgb "red" title ""

set title "Generator 1, offset = 2"
set out "plot_1c.jpg"
plot "generator_1c.dat" using 1:2 with points ps 0.5 pt 7 lt rgb "red" title ""

print "Part 1... DONE"

set title "Generator 2, offset = 0"
set out "plot_2a.jpg"
plot "generator_2a.dat" using 1:2 with points ps 0.5 pt 7 lt rgb "green" title ""

set title "Generator 2, offset = 1"
set out "plot_2b.jpg"
plot "generator_2b.dat" using 1:2 with points ps 0.5 pt 7 lt rgb "green" title ""

set title "Generator 2, offset = 2"
set out "plot_2c.jpg"
plot "generator_2c.dat" using 1:2 with points ps 0.5 pt 7 lt rgb "green" title ""

print "Part 2... DONE"

set title "Generator 3, offset = 0"
set out "plot_3a.jpg"
plot "generator_3a.dat" using 1:2 with points ps 0.5 pt 7 lt rgb "blue" title ""

set title "Generator 3, offset = 1"
set out "plot_3b.jpg"
plot "generator_3b.dat" using 1:2 with points ps 0.5 pt 7 lt rgb "blue" title ""

set title "Generator 3, offset = 2"
set out "plot_3c.jpg"
plot "generator_3c.dat" using 1:2 with points ps 0.5 pt 7 lt rgb "blue" title ""

print "Part 3... DONE"

set title "Sphere"
set xyplane 0
set border 4095
set out "plot_4a.jpg"
splot "generator_4a.dat" using 1:2:3 with points ps 0.5 pt 7 lt rgb "orange" title ""

print "Part 4... DONE"

set title "Ball"
set out "plot_4b.jpg"
splot "generator_4b.dat" using 1:2:3 with points ps 0.5 pt 7 lt rgb "orange" title ""

print "Part 5... DONE"
print "All OK"
