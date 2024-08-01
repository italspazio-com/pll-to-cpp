# 📊 PLL to C++
![video_demo](https://github.com/italspazio-com/pll-to-cpp/blob/main/demo.gif)

Nel file `clean_pll_loop_GNUPLOT_animated.cpp` viene utiizzata la libreria `gnuplot-iostream.h` [REPO gnuplot-iostream](https://github.com/dstahlke/gnuplot-iostream)

Per compilare il file bisogna digitare 
```
g++ nome_file.cpp -o main -lboost_iostreams -lboost_system -lboost_filesystem
```

### ATTENZIONE
Su **windows** è probabile che bisogna installare la libreria *BOOST*

##  Pezzo di codice animato GNUPlot
```            // PROVA ANIMAZIONE CON GNUPLOT
            cout << "Press Ctrl-C to quit (closing gnuplot window doesn't quit)." << endl;

            gp << "plot '-' binary" << gp.binFmt1d(cos_out, "array") << "with lines title 'cos_out', "
               << "'-' binary" << gp.binFmt1d(input_signal, "array") << "with lines title 'input_signal'\n";
            gp.sendBinary1d(cos_out);
            gp.sendBinary1d(input_signal);

            gp.flush();
            mysleep(50);
```

## Plot creato con gnuplot
```set datafile separator ','
plot "esportazione.csv" using 1  with lines lw 2, '' using 2 with lines lw 2
```

Si può caricare lo script con 
```
load "plot_gnuplot.gp"
```
