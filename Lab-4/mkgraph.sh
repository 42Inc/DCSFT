#!/usr/bin/gnuplot
set terminal png size 1920, 1080 enhanced font 'Arial, 16'
set title "2DSP"

set style line 1 linecolor rgb 'red' linetype 2 linewidth 2
set style line 2 linecolor rgb 'green' linetype 2 linewidth 2
set style line 3 linecolor rgb 'blue' linetype 2 linewidth 2
set style line 4 linecolor rgb 'yellow' linetype 2 linewidth 2

set border linewidth 1
set key top left
set grid
set format y "%.4f"
set xlabel "Amount of tasks" font "Arial, 18"
set format x "%.0f"
set ylabel "Execution time" font "Arial, 18"
set xtics 500 font "Arial, 12"
set yrange [0:4]
set ytics 0.5 font "Arial, 12"
set rmargin 4
set tmargin 2
set mxtics

set output '2DSP.png'
plot "./results.dat" i 0 using 1:2 title "NFDH, n = 1024" with lp ls 1,\
     "./results.dat" i 1 using 1:2 title "NFDH, n = 4096" with lp ls 2,\
     "./results.dat" i 2 using 1:2 title "FFDH, n = 1024" with lp ls 3,\
     "./results.dat" i 3 using 1:2 title "FFDH, n = 4096" with lp ls 4
