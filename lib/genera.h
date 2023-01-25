#ifndef GENERA_H
#define GENERA_H
/**================================================================================================
 * *                                           INFO
 *  Autore    : Francesco Pio Nocerino
 *  @email    : kekko.dev16@gmail.com
 *  File      : genera.h
 *  Versione  : 1.0
 *  Data      : 10/01/2023
 *  Descr     :
 * ?
 *================================================================================================**/
#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;

class Genera
{
private:
    void _scambio(int &a, int &b)
    {
        int temp;
        temp = a;
        a = b;
        b = temp;
    }

    void to_upper(char &ch)
    {
        if (ch >= 'a' && ch <= 'z')
            ch -= 32;
        else
            ch = ch;
    }
    void to_lower(char &ch)
    {
        if (ch >= 'A' && ch <= 'Z')
            ch += 32;
        else
            ch = ch;
    }

public:
    int _generaNumero(int base, int max);
    char _generaCarattere(char ch1, char ch2);
    char _generaCarattereMin(char ch1, char ch2);
};

int Genera::_generaNumero(int base, int max)
{
    srand(unsigned(time(NULL)));
    return rand() % max + base;
}

char Genera::_generaCarattere(char ch1, char ch2)
{
    to_upper(ch1);
    to_upper(ch2);
    string v = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int p, p2;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == ch1)
            p = i;
        else if (v[i] == ch2)
            p2 = i;
    }
    if (p2 < p)
        _scambio(p2, p);
    return v[_generaNumero(p, p2 + 1)];
}

char Genera::_generaCarattereMin(char ch1, char ch2)
{
    to_lower(ch1);
    to_lower(ch2);
    string v = "abcdefghijklmnopqrstuvwxyz";
    int p, p2;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == ch1)
            p = i;
        else if (v[i] == ch2)
            p2 = i;
    }
    if (p2 < p)
        _scambio(p2, p);
    return v[_generaNumero(p, p2 + 1)];
}

#endif /* GENERA_H */
