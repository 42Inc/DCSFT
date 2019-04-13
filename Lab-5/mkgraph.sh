#!/usr/bin/gnuplot
set terminal png size 1920,1080 enhanced font 'Arial, 16'
set title "Dobryyi vecher, ya dispetcher"

set style line 1 linecolor rgb 'red' linetype 2 linewidth 2
set style line 2 linecolor rgb 'green' linetype 2 linewidth 2

set border linewidth 1
set key top left
set grid
set format y "%.4f"
set xlabel "Amount of tasks" font "Arial, 18"
set format x "%.0f"
set ylabel "Execution time" font "Arial, 18"
set xtics 100 font "Arial, 12"
set yrange [0:*]
set ytics 0.5 font "Arial, 12"
set rmargin 4
set tmargin 2
set mxtics

set output 'Dobryyi vecher, ya dispetcher.png'
  plot "./result/1.dat" i 0 using 1:2 title "n in range 100-1000" with lp ls 1
set output 'Dobryyi vecher, ya dispetcher numba 2.png'
  plot "./result/1.dat" i 1 using 1:2 title "n in range 900-1000" with lp ls 2
