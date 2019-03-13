#!/usr/bin/gnuplot
set terminal png size 1920,1080 enhanced font 'Arial, 16'

set style line 1 linetype 1 linewidth 2 linecolor rgb 'red'
set style line 2 linetype 1 linewidth 2 linecolor rgb 'blue'
set style line 3 linetype 1 linewidth 2 linecolor rgb 'green'
set style line 4 linetype 1 linewidth 2 linecolor rgb 'yellow'
set style line 5 linetype 1 linewidth 2 linecolor rgb 'pink'
set style line 6 linetype 1 linewidth 2 linecolor rgb 'cyan'
set style line 7 linetype 1 linewidth 2 linecolor rgb 'brown'
set style line 8 linetype 1 linewidth 2 linecolor rgb 'black'
set style line 9 linetype 1 linewidth 2 linecolor rgb 'grey'
set style line 10 linetype 1 linewidth 2 linecolor rgb 'orange'
set style line 11 linetype 1 linewidth 2 linecolor rgb 'cyan'
set style line 12 linetype 1 linewidth 2 linecolor rgb 'brown'
set style line 13 linetype 1 linewidth 2 linecolor rgb 'black'

set border linewidth 1
set key top right
set grid
set mytics 1
set format x "%.3f"
set xlabel "Number n of elementary machines in base subsystem" font "Arial, 16"
set format y "%.3f"
set yrange [*:*]
set ylabel "Mean time between failures" font "Arial, 16"
set xtics font "Arial, 10"
set ytics font "Arial, 10"
set rmargin 4
set tmargin 2
set mxtics

set output './result/result_1.png'
plot for [col=2:8] './result/1.dat' using 1:col with linespoints ls col-1 title columnheader(col)

set output './result/result_2.png'
plot for [col=2:13] './result/2.dat' using 1:col with linespoints ls col-1 title columnheader(col)
