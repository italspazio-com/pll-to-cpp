
# PLL to CPP
Nel file `clean_pll_loop_GNUPLOT.cpp` viene utilizzata una libreria esterna che permette l'utilizzo di GNUPlot su C++. [Libreria presa da questa repo.](https://github.com/martinruenz/gnuplot-cpp)

Altra libreria per utilizzare GNUPlot su C++ [visionabile qui,](http://stahlke.org/dan/gnuplot-iostream/)

## Plot creato con gnuplot
```set datafile separator ','
plot "esportazione.csv" using 1  with lines lw 2, '' using 2 with lines lw 2
```

Si può caricare lo script con 
```
load "plot_gnuplot.gp"
```
