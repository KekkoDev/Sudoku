#ifndef LOGICA_H
#define LOGICA_H
/**================================================================================================
 * *                                           INFO
 *  Autore    : Francesco Pio Nocerino
 *  @email    : kekko.dev16@gmail.com
 *  File      : logica.h
 *  Versione  : 1.0
 *  Data      : 02/01/2023
 *  Descr     :
 * ? Libreria logica
 *================================================================================================**/
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>
#include "sudoku.h"
#include "grafica.h"
#include "supporto_grafica.h"
using namespace std;
#define VINTA "../file/giocate/_vinte.txt"
#define PERSA "../file/giocate/_perse.txt"

class Logica
{
public:
    bool _cntrlM(Sudoku sudoku, int x, int y, int num);           // controlla la matrice 3x3
    bool _cntrlVerticale(Sudoku sudoku, int x, int y, int num);   // controlla le linee verticali
    bool _cntrlOrizzontale(Sudoku sudoku, int x, int y, int num); // controlla le linee orizzontali
    void _cntrlstart(int x, int y, int &i, int &j);               // assegna ad i,j il loro indice di partenza data una posizione x,y
    bool _estrai(string str, int &x, int &y);                     // estrae della stringa in input le coordinate x,y
    bool _cntrlNumeri(int &x, int &y);                            // controlla se i numeri sono validi
    bool _cntrlOccupata(Sudoku sudoku, int x, int y);
    void _finale(int pt);
    int _getPunti(string path);
    void _scriviP(string path, int num);
    void _info(Giocatore giocatore);
    string _data();
};

bool Logica::_cntrlM(Sudoku sudoku, int x, int y, int num)
{
    int i, j, conta = 1;
    bool found = false;
    _cntrlstart(x, y, i, j);
    int R, R2;
    if (i == 0) // assegna la dimensione in base all loro valore
    {
        R = 3;
        if (j >= 3 && j <= 5)
            R2 = 6;
        else
            R2 = 9;
    }
    else
    {
        if (i >= 3 && i <= 5)
        {
            R = 6;
            if (j >= 3 && j <= 5)
                R2 = 6;
            else
                R2 = 9;
        }
        else if (i >= 6 && i <= 8)
        {
            R = 9;
            if (j >= 3 && j <= 5)
                R2 = 6;
            else
                R2 = 9;
        }
    }
    for (int k = i; k < R; k++)
    {
        for (int l = j; l < R2; l++)
        {
            // cout << k << ";" << l << " ";
            //  cout << sudoku.get_cella(k, l) << " ";
            if (sudoku.get_cella(k, l) == num)
                conta++;
        }
        if (conta == 2) // se vengono trovati 2 numeri uguali restituirà true
            found = true;
    }
    return found;
}

bool Logica::_cntrlVerticale(Sudoku sudoku, int x, int y, int num)
{
    bool found = false;
    for (; x < RC; x++)
    {
        if (sudoku.get_cella(x, y) == num) // se sulla verticale trova numeri uguali a quello passato (num) => true
            found = true;
    }
    return found;
}

bool Logica::_cntrlOrizzontale(Sudoku sudoku, int x, int y, int num)
{
    bool found = false;
    for (; y < RC; y++)
    {
        if (sudoku.get_cella(x, y) == num) // se sulla orizzontale trova numeri uguali a quello passato (num) => true
            found = true;
    }
    return found;
}

void Logica::_cntrlstart(int x, int y, int &i, int &j)
{
    if (x <= 2 && y <= 8)
    {
        if (x >= 0 && x <= 2 && y >= 0 && y <= 2)
        {
            i = 0;
            j = 0;
        }
        else
        {
            if (x >= 0 && x <= 2 && y >= 3 && y <= 5)
            {
                i = 0;
                j = 3;
            }
            else if (x >= 0 && x <= 2 && y >= 6 && y <= 8)
            {
                i = 0;
                j = 6;
            }
        }
    }
    else
    {
        if (x >= 3 && x <= 5 && y <= 8)
        {
            if (x >= 3 && x <= 5 && y >= 0 && y <= 2)
            {
                i = 3;
                j = 0;
            }
            else
            {
                if (x >= 3 && x <= 5 && y >= 3 && y <= 5)
                {
                    i = 3;
                    j = 3;
                }
                else if (x >= 3 && x <= 5 && y >= 6 && y <= 8)
                {
                    i = 3;
                    j = 6;
                }
            }
        }
        else
        {
            if (x >= 6 && x <= 8 && y >= 0 && y <= 2)
            {
                i = 6;
                j = 0;
            }
            else
            {
                if (x >= 6 && x <= 8 && y >= 3 && y <= 5)
                {
                    i = 6;
                    j = 3;
                }
                else if (x >= 6 && x <= 8 && y >= 6 && y <= 8)
                {
                    i = 6;
                    j = 6;
                }
            }
        }
    }
}

bool Logica::_estrai(string str, int &x, int &y)
{
    int p = 0;
    string t;
    bool found = false;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9') // quando vengono trovati caratteri che sono numeri 0-9
        {
            found = true;
            t.clear();

            if (p == 0) // se p==0 allora sara la prima volta e sara' la nostra x
            {
                t = str.substr(i, 1);
                x = stoi(t);
            }
            else if (p == 1) // se p==1 allora sara la nostra y
            {
                t = str.substr(i, 1);
                y = stoi(t);
            }
            p++;
        }
    }
    return found;
}

bool Logica::_cntrlNumeri(int &x, int &y)
{
    if (x >= 0 && x <= 8 && y >= 0 && y <= 8) // controlla se i numeri sono compresi tra 0-8
        return true;
    else
        return false;
}

bool Logica::_cntrlOccupata(Sudoku sudoku, int x, int y)
{
    if (sudoku.get_cella(x, y) == 0)
        return false;
    else
        return true;
}

int Logica::_getPunti(string path)
{
    stringstream p;
    string pt;
    int r;
    ifstream File(path);
    getline(File, pt, ',');
    p << pt;
    p >> r;
    File.close();
    return r;
}

void Logica::_scriviP(string path, int num)
{
    ofstream File(path);
    File << num << "," << _data() << endl;
    File.close();
}

void Logica::_finale(int pt)
{
    string p;
    stringstream ss;
    int s;
    if (pt <= 3)
    {
        _scriviP(VINTA, _getPunti(VINTA) + 1);
        cout << "Hai Vintoo!\n";
    }
    else
    {
        _scriviP(PERSA, _getPunti(PERSA) + 1);
        cout << "Hai Perso!\n";
    }
}

void Logica::_info(Giocatore giocatore)
{
    Color color;
    cout.flush();
#ifdef _WIN32
    cout << setw(80) << "+-------------------------+\n";
    cout << setw(70) << "+ Partite Vinte > ";
    color.foreground(GREEN_INTESE);
    cout << _getPunti(VINTA);
    color.reset();
    cout << setw(8) << "+" << endl;
    cout << setw(70) << "+ Partite Perse > ";
    color.foreground(RED_INTENSE);
    cout << _getPunti(PERSA);
    color.reset();
    cout << setw(8) << "+" << endl;
    cout << setw(63) << "+ Errori > ";
    cout << giocatore.get_punti();
    color.foreground(RED_INTENSE);
    cout << "/3";
    color.reset();
    cout << setw(13) << "+" << endl;
    cout << setw(80) << "+-------------------------+\n";

#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    cout << setw(80) << "+-------------------------+\n";
    cout << setw(70) << "+ Partite Vinte > " << color.foreground(GREEN_INTESE, _getPunti(VINTA)) << setw(8) << "+" << endl;
    cout << setw(70) << "+ Partite Perse > " << color.foreground(RED_INTENSE, _getPunti(PERSA)) << setw(8) << "+" << endl;
    cout << setw(63) << "+ Errori > " << giocatore.get_punti() << color.foreground(RED_INTENSE, "/3") << setw(13) << "+" << endl;
    cout << setw(80) << "+-------------------------+\n";
#endif
}

string Logica::_data()
{
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);
    string r;
    r += to_string(local_time->tm_yday) + "/" + to_string(local_time->tm_mon + 1) + "/" + to_string(local_time->tm_year + 1900);
    return r;
}

#endif /* LOGICA_H */
