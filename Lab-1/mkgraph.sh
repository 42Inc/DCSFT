#!/usr/bin/gnuplot
set terminal png size 1920,1080 enhanced font 'Arial, 16'

set style line 1 linetype 1 linewidth 2 linecolor rgb 'red'
set style line 2 linetype 1 linewidth 2 linecolor rgb 'blue'
set style line 3 linetype 1 linewidth 2 linecolor rgb 'green'
set style line 4 linetype 1 linewidth 2 linecolor rgb 'yellow'

set border linewidth 1
set key top right
set grid
set mytics 1
set format x "%.0f"
set xlabel "Number n of elementary machines in base subsystem" font "Arial, 16"
set format y "%.0f"
set ylabel "Mean time between failures" font "Arial, 16"
set xtics font "Arial, 10"
set ytics font "Arial, 10"
set rmargin 4
set tmargin 2
set mxtics

set output './result/result_1.png'
plot for [col=2:5] './result/1.dat' using 1:col with linespoints ls col-1
