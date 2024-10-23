# animate3D.gnu - Gnuplot script to animate the 3D motion of the conical pendulum

set terminal wxt
set title "Conical Pendulum Animation"
set xlabel "X-axis"
set ylabel "Y-axis"
set zlabel "Z-axis"
set xrange [-1.1:1.1]
set yrange [-1.1:1.1]
set zrange [-0.3:0.0]

# Loop through the data file to animate the pendulum
set key off
set grid

do for [i=0:100] {
    splot "ConicalPendulum.dat" using 2:3:4 every ::i::i with linespoints \
    title "Pendulum Position", \
    "ConicalPendulum.dat" using 2:3:(-0.1) with lines title "Pendulum Trace"
    pause 0.1
}

