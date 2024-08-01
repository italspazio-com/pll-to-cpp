# 📊 PLL to C++
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white) ![Static Badge](https://img.shields.io/badge/Linux%20OS%20-%20Linux?style=flat&logo=linux&logoColor=heavenly&logoSize=big&color=black&link=https%3A%2F%2Fwww.linux.it%2F)

![video_demo](https://github.com/italspazio-com/pll-to-cpp/blob/main/demo.gif)

## Indice
- [Riguardo al Codice](#riguardo-al-codice)
    - [Creato con](#creato-con)
- [Installazione e Setup](#installazione-e-setup)
    - [Prerequisiti e Installazione](#prerequisiti-e-installazione)
- [Codice che anima il grafico](#pezzo-di-codice-animato-GNUPlot)

## Riguardo al codice
Il file principale è `clean_pll_loop.cpp`, in cui viene utilizzata libreria `gnuplot-iostream.h` (_presente in questa repo_). Per maggiori informazioni sulla libreria usata visitare [questo link](https://github.com/dstahlke/gnuplot-iostream)

### Creato con
- C++
- [GNUplot](http://www.gnuplot.info/)
- [GNUPlot-iostream](https://stahlke.org/dan/gnuplot-iostream/)

## Installazione e Setup
Il seguente codice è stato testato su Linux in particolare sulla distro ZorinOS, di conseguenza non sono conoscenza dei possibili problemi su Windows o altri OS. Per qualsiasi informazioni contattare @angelof-exe. 

### Prerequisiti e Installazione
1) Installare libreria _BOOST_ necessaria per eseguire il codice, su **Linux** bastera eseguire il seguente codice sul terminale `sudo apt install libboost-all-dev`. Su **Windows** bisognerà scaricare la libreria direttamente [dal sito ufficiale](https://www.boost.org/users/download/)
2. Clonare la seguente repo  `git clone https://github.com/italspazio-com/pll-to-cpp.git`
3. Se si vuole vedere direttamente il grafico eseguire il comando sul terminale `./main`, altrimenti se si vogliono apportare modifiche al codice bisognerà poi compilarlo con il seguente codice
```
g++ clean_pll_loop.cpp -o main -lboost_iostreams -lboost_system -lboost_filesystem
```


##  Pezzo di codice animato GNUPlot
```            
cout << "Press Ctrl-C to quit (closing gnuplot window doesn't quit)." << endl;

gp << "plot '-' binary" << gp.binFmt1d(cos_out, "array") << "with lines lw 5 title 'cos_out', "
               << "'-' binary" << gp.binFmt1d(input_signal, "array") << "with lines lw 5 title 'input_signal'\n";
gp.sendBinary1d(cos_out);
gp.sendBinary1d(input_signal);

gp.flush();
mysleep(50);
```
