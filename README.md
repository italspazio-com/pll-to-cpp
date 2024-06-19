# pll-to-cpp
Trasformazione codice da python a cpp

## Plot creato con gnuplot
```set datafile separator ','
plot "esportazione.csv" using 1  with lines lw 2, '' using 2 with lines lw 2
```

Si può caricare lo script con 
```load "plot_gnuplot.gp"
```
