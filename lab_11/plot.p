set term jpeg size 300,300

set out 'filrered_signal.jpg'
plot 'filtered_signal.dat' using 1:2 with lines title ''