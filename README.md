# 📊 PLL to C++
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white) ![Static Badge](https://img.shields.io/badge/Linux%20OS%20-%20Linux?style=flat&logo=linux&logoColor=heavenly&logoSize=big&color=black&link=https%3A%2F%2Fwww.linux.it%2F)

![video_demo](https://github.com/italspazio-com/pll-to-cpp/blob/main/demo.gif)

## Indice
- [Riguardo al Codice](#riguardo-al-codice)
    - [Panoramica](#panoramica)
    - [Funzionalità del Codice](#funzionalità-del-codice)
    - [Creato con](#creato-con)
- [Installazione e Setup](#installazione-e-setup)
    - [Prerequisiti e Installazione](#prerequisiti-e-installazione)
- [Codice che anima il grafico](#codice-che-anima-il-grafico)

## Riguardo al codice

### Panoramica
Il progetto è un esempio di un PLL (Phase-Locked Loop) implementato in C++. Un PLL è un circuito elettronico che può essere usato per sincronizzare un'onda a una frequenza di riferimento. Questo esempio utilizza un PLL semplice per mostrare come le varie componenti di un PLL lavorano insieme, visualizzando il risultato tramite GNUplot.

Il file principale del progetto è `clean_pll_loop.cpp`. In questo file viene utilizzata la libreria `gnuplot-iostream.h` per creare e aggiornare i grafici dinamicamente. Le componenti principali del PLL sono il rivelatore di fase, il filtro del loop e l'oscillatore controllato in tensione.

### Funzionalità del Codice
- **Generazione del Segnale di Input:** Viene creato un segnale coseno con una frequenza definita.
- **Rivelatore di Fase:** Calcola la differenza di fase tra il segnale di input e il segnale sinusoidale generato.
- **Filtro del Loop:** Applica un filtro proporzionale-integrativo per regolare l'uscita del PLL.
- **Aggiornamento della Fase e dei Segnali:** Aggiorna le stime di fase e i segnali sinusoidali e cosenoidi basati sulla fase stimata.
- **Visualizzazione con GNUplot:** Mostra in tempo reale i segnali generati e il segnale di input utilizzando GNUplot.

### Creato con
- C++
- [GNUplot](http://www.gnuplot.info/)
- [GNUPlot-iostream](https://stahlke.org/dan/gnuplot-iostream/)

## Installazione e Setup
Il codice è stato testato principalmente su Linux (ZorinOS). Potrebbero esserci delle differenze nell'esecuzione su Windows o altri sistemi operativi.

### Prerequisiti e Installazione
1. **Installare la libreria Boost**: Necessaria per eseguire il codice. Su **Linux**, puoi installarla con il comando:
   ```bash
   sudo apt install libboost-all-dev
   ```
   Su **Windows**, scarica la libreria direttamente dal [sito ufficiale di Boost](https://www.boost.org/users/download/).

2. **Clonare il repository**:
   ```bash
   git clone https://github.com/italspazio-com/pll-to-cpp.git
   ```

3. **Compilare il codice**:
   Per eseguire direttamente il programma e vedere il grafico, usa:
   ```bash
   ./main
   ```
   Per apportare modifiche al codice e poi compilarlo, usa:
   ```bash
   g++ clean_pll_loop.cpp -o main -lboost_iostreams -lboost_system -lboost_filesystem
   ```

## Codice che anima il grafico
Il codice seguente è responsabile per l'aggiornamento dinamico del grafico tramite GNUplot:

```cpp
cout << "Press Ctrl-C to quit (closing gnuplot window doesn't quit)." << endl;

// Invia i dati a gnuplot
gp << "plot '-' binary" << gp.binFmt1d(cos_out, "array") << "with lines lw 5 title 'cos_out', "
   << "'-' binary" << gp.binFmt1d(input_signal, "array") << "with lines lw 5 title 'input_signal'\n";
gp.sendBinary1d(cos_out);
gp.sendBinary1d(input_signal);

// Pulisce e aggiorna il grafico
gp.flush();
mysleep(50);
```
Questo frammento di codice invia i dati dei segnali coseno e del segnale di input a GNUplot e aggiorna il grafico ogni 50 millisecondi. Il comando `gp.flush()` è utilizzato per assicurarsi che tutte le modifiche vengano applicate al grafico.
