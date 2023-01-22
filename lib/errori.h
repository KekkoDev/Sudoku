#ifndef ERRORI_H
#define ERRORI_H
/**================================================================================================
 * *                                           INFO
 *  Autore    : Francesco Pio Nocerino
 *  @email    : kekko.dev16@gmail.com
 *  File      : errori.h
 *  Versione  : 1.0
 *  Data      : 05/01/2023
 *  Descr     :
 * ? Libreria per gli errori di input/runtime
 *================================================================================================**/
#include <iostream>
#include <iomanip>
#include <string>
#include "logica.h"
using namespace std;

class Errori
{
public:
    void _erroreInserimento(Logica logica, string &str, int &x, int &y);
    void _erroreMossa(Logica logica, string &str, int &num);
    void _erroreOccupata(Sudoku sudoku, Logica logica, string &str, int &x, int &y);
};

void Errori::_erroreInserimento(Logica logica, string &str, int &x, int &y)
{
    bool found = false;
    do
    {
        if (logica._estrai(str, x, y) && logica._cntrlNumeri(x, y) || str.compare(":q") == 0) // controlla se le coordinate inserite sono accettabili
            found = true;
        if (!found) // altrimenti le richiede in input
        {
            cout << "[Inserimento non Valido!]\n";
            cout << "[Seleziona Cella] (0;0) > ";
            fflush(stdin);
            getline(cin, str);
        }
    } while (!found);
}

void Errori::_erroreOccupata(Sudoku sudoku, Logica logica, string &str, int &x, int &y)
{
    bool found = false;
    do
    {
        if (logica._cntrlOccupata(sudoku, x, y) == 0)
            found = true;
        if (!found)
        {
            cout << "[Posizione Occupata!]\n";
            cout << "[Seleziona Cella] (0;0) > ";
            fflush(stdin);
            getline(cin, str);
            _erroreInserimento(logica, str, x, y);
        }
    } while (!found);
}

#endif /* ERRORI_H */
