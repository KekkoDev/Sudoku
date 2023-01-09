/**================================================================================================
 * *                                           INFO
 *  Autore    : Francesco Pio Nocerino
 *  @email    : kekko.dev16@gmail.com
 *  File      : main.cpp
 *  Versione  : 1.0
 *  Data      : 02/01/2023
 *  Descr     :
 * ? Gioco del Sudoku
 *================================================================================================**/
#include <iostream>
#include "../lib/sudoku.h"
#include "../lib/logica.h"
#include "../lib/giocatore.h"
#include "../lib/errori.h"
#include "../lib/grafica.h"
#include "../lib/supporto_grafica.h"
using namespace std;

int main()
{
    _intro();
    string inp, inp2;
    Sudoku sudoku;
    Logica logica;
    Errori errori;
    Giocatore giocatore;
    Color color;
    int x, y, numero;
    bool verticale, orizzontale, tabella, found = false;

#ifdef _WIN32 // ridimensiona la console
    color.resize_console(700, 800);
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    color.resize_console("89", "49");
#endif

    do
    {
        cl();
        _banner();
        logica._info(giocatore);
        sudoku.stampa();
        cout << "[Seleziona Cella] (0;0) > ";
        fflush(stdin);
        getline(cin, inp);
        errori._erroreInserimento(logica, inp, x, y);

        if (inp != ":q")
        {
            if (logica._cntrlOccupata(sudoku, x, y))
                errori._erroreOccupata(sudoku, logica, inp, x, y);
            cout << "[Inserisci Numero] (0-9) > ";
            cin >> numero;
            if (!logica._cntrlVerticale(sudoku, x, y, numero) && !logica._cntrlOrizzontale(sudoku, x, y, numero) && logica._cntrlM(sudoku, x, y, numero) == 0)
            {
                sudoku.set_xy(x, y);
                sudoku.set_mossa(numero);
            }
            else
            {
                giocatore.agg_punti();
#ifdef _WIN32
                color.foreground(RED_WHITE_INTENSE);
                cout << "[Numero Errato!]";
                color.reset();
                cout << endl;
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                cout << color.background(RED_INTENSE, WHITE_INTENSE, "[Numero Errato!]") << endl;
#endif
                fflush(stdin);
                cin.get();
            }
        }
    } while (giocatore.get_punti() <= 3 && inp != ":q");
    if (inp != ":q")
        logica._finale(giocatore.get_punti());
    else
        cout << "Ciao a Presto!\n";
    cin.get();

    return 0;
}