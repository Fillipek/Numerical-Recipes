set term jpeg size 300,300

set out 'charts/8_raw.jpg'
plot 'data/8_raw_signal.dat' using 1:2 with lines title ''

set out 'charts/8_fourier.jpg'
plot 'data/8_fft_signal.dat' using 1:2 with lines title 'Re',\
'' using 1:3 with lines title 'Im'

set out 'charts/8_discrim_fourier.jpg'
plot 'data/8_fft_modules.dat' using 1:2 with lines title ''

set out 'charts/8_filtered.jpg'
plot 'data/8_filtered_signal.dat' using 1:2 with lines title ''

set out 'charts/12_raw.jpg'
plot 'data/12_raw_signal.dat' using 1:2 with lines title ''

set out 'charts/12_fourier.jpg'
plot 'data/12_fft_signal.dat' using 1:2 with lines title 'Re',\
'' using 1:3 with lines title 'Im'

set out 'charts/12_discrim_fourier.jpg'
plot 'data/12_fft_modules.dat' using 1:2 with lines title ''

set out 'charts/12_filtered.jpg'
plot 'data/12_filtered_signal.dat' using 1:2 with lines title ''

set out 'charts/10_raw.jpg'
plot 'data/10_raw_signal.dat' using 1:2 with lines title ''

set out 'charts/10_fourier.jpg'
plot 'data/10_fft_signal.dat' using 1:2 with lines title 'Re',\
'' using 1:3 with lines title 'Im'

set out 'charts/10_discrim_fourier.jpg'
plot 'data/10_fft_modules.dat' using 1:2 with lines title ''

set out 'charts/10_filtered.jpg'
plot 'data/10_filtered_signal.dat' using 1:2 with lines title ''