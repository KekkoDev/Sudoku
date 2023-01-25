#ifndef GIOCATORE_H
#define GIOCATORE_H
/**================================================================================================
 * *                                           INFO
 *  Autore    : Francesco Pio Nocerino
 *  @email    : kekko.dev16@gmail.com
 *  File      : giocatore.h
 *  Versione  : 1.0
 *  Data      : 05/01/2023
 *  Descr     :
 * ? Libreria Giocatore
 *================================================================================================**/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Giocatore
{
protected:
    int punti;

public:
    Giocatore()
    {
        punti = 0;
    };
    void agg_punti();
    void set_punti(int p);
    int get_punti();
};

void Giocatore::agg_punti()
{
    punti++;
}

void Giocatore::set_punti(int p)
{
    punti = p;
}

int Giocatore::get_punti()
{
    return punti;
}

#endif /* GIOCATORE_H */
