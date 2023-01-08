#ifndef SUDOKU_H
#define SUDOKU_H
/**================================================================================================
 * *                                           INFO
 *  Autore    : Francesco Pio Nocerino
 *  @email    : kekko.dev16@gmail.com
 *  File      : sudoku.h
 *  Versione  : 1.0
 *  Data      : 02/01/2023
 *  Descr     :
 * ? Libreria gioco Sudoku
 *================================================================================================**/
#ifdef _WIN32
#include <windows.h>
#endif
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <time.h>
#include <unistd.h>
#include "grafica.h"
#include "giocatore.h"
#include "supporto_grafica.h"
using namespace std;
#define RC 9                               // numero righe-colonne
#define MAPPA_1 "../file/mappe/mappa1.csv" // mappe la scacchiera
#define MAPPA_2 "../file/mappe/mappa2.csv"
#define MAPPA_3 "../file/mappe/mappa3.csv"
#define MAPPA_UTENTE "../file/mappe/mappa_utente.csv"
#define STATIC_ "../file/test/_mappa_test.csv"

class Sudoku
{
protected:
    int scacchiera[RC][RC]; // scacchiera
    int x;
    int y;

public:
    Sudoku(void)
    {
        fstream File;
        int map, conta = 1, ps, ps2, dim, dim2;
        string ch, t;

        stringstream test; // per prova di mappa statica (eliminare sstream e test1)
        int test1;
        File.open(STATIC_, ios::in);
        while (!File.eof())
        {
            for (int i = 0; i < RC; i++)
            {
                _barraCaricamento(conta);
                for (int j = 0; j < RC; j++)
                {
                    ch.clear();
                    getline(File, ch, ',');
                    scacchiera[i][j] = stoi(ch);
                }
                conta += 5;
                getline(File, t, '\n');
            }
        }
        File.close();

        // map = genera_numero(3); // prende una mappa a caso tra (0-3)
        // switch (map)            // scelta della mappa
        // {
        // case 1:
        //     File.open(MAPPA_1, ios::in);
        //     break;
        // case 2:
        //     File.open(MAPPA_2, ios::in);
        //     break;
        // case 3:
        //     File.open(MAPPA_3, ios::in);
        //     break;
        // }
        // ps = 0;
        // dim = 3;
        // while (!File.eof())
        // {
        //     for (int i = 0; i < RC - 6; i++) // si muove sulle righe
        //     {
        //         ps2 = 0;
        //         dim2 = 3;
        //         for (int j = 0; j < RC - 6; j++) // si muove sulle colonne
        //         {
        //             _barraCaricamento(conta);      // mostra lo stato di avanzamento dell caricamento nella matrice (il tempo e' dovuto allo sleep di 1s)
        //             for (int k = ps; k < dim; k++) // si muove di 3 in 3 sulle righe
        //             {
        //                 for (int p = ps2; p < dim2; p++) // si muove di 3 in 3 sulle colonne
        //                 {
        //                     ch.clear();
        //                     getline(File, ch, ',');
        //                     if (ch.compare(" _") == 0)
        //                     {
        //                         scacchiera[k][p] = genera_numero(9);
        //                         _sleep(1);
        //                     }
        //                     else
        //                         scacchiera[k][p] = 0;
        //                 }
        //             }
        //             conta += 5;
        //             getline(File, t, '\n');
        //             ps2 += 3;
        //             dim2 += 3;
        //         }
        //         ps += 3;
        //         dim += 3;
        //     }
        // }
        // File.close();
        // _cntrlOrizzontaleInit();
        // cin.get();
        cout
            << endl;
    };
    int genera_numero(int _maxGen); // genera un numero casuale
    void _sleep(int d);
    void set_xy(int x, int y);             // setta la posizione
    void set_mossa(int num);               // assegna il numero alla posizione settata
    int get_cella(int x, int y);           // restituisce il contenuto della cella
    void salva_stato(Giocatore giocatore); // salva lo stato attuale della scacchiera
    void _cntrlOrizzontaleInit();
    bool _checkNum(int i, int j, int num);
    void stampa(); // stampa della scacchiera
};

int Sudoku::genera_numero(int _maxGen)
{
    srand(unsigned(time(NULL)));
    return rand() % _maxGen + 1;
}

void Sudoku::_sleep(int d)
{
#ifdef _WIN32
    Sleep(d * 1000);
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    sleep(d);
#endif
}
void Sudoku::set_xy(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Sudoku::set_mossa(int num)
{
    scacchiera[x][y] = num;
}

int Sudoku::get_cella(int x, int y)
{
    return scacchiera[x][y];
}

void Sudoku::salva_stato(Giocatore giocatore)
{
    char s;
    cout << "[Vuoi Salvare la corrente partita?] (s/[N]) > ";
    if (s)
    {
        ofstream File(MAPPA_UTENTE);
        File.clear();
        File << giocatore.get_punti() << endl;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                File << scacchiera[i][j] << ",";
            }
            File << endl;
        }
    }
    else
        cout << "[Ok!]\n";
}

void Sudoku::_cntrlOrizzontaleInit()
{
    int num, conta = 1;
    for (int i = 0; i < RC; i++)
    {
        _barraCaricamento(conta);
        for (int j = 0; j < RC; j++)
        {
            num = scacchiera[i][j];
            if (_checkNum(i, j, num))
            {

                scacchiera[i][j] = genera_numero(9);
                sleep(1);
            }
        }
        conta += 5;
    }
}

bool Sudoku::_checkNum(int i, int j, int num)
{
    bool found = false;
    for (int p = 0; p < RC; p++)
    {
        if (scacchiera[i][p] == num && scacchiera[i][p] != 0 && p != i)
            found = true;
    }
    return found;
}

void Sudoku::stampa()
{
    Color color;
    for (int i = 0; i < RC; i++)
        cout << "  " << i << " ";
    cout << endl;
    for (int i = 0; i < RC; i++)
    {

        if (i == 0 || i == 3 || i == 6)
        {
#ifdef _WIN32
            color.foreground(BLUE_INTESE);
            cout << "+---+---+---+---+---+---+---+---+---+";
            color.reset();
            cout << endl;
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
            cout << color.foreground(BLUE_INTESE, "+---+---+---+---+---+---+---+---+---+") << endl;
#endif
        }

        else
        {
#ifdef _WIN32
            color.foreground(BLUE_INTESE);
            cout << "\r+";
            color.foreground(GREEN_INTESE);
            cout << "---+---+---";
            color.foreground(BLUE_INTESE);
            cout << "+";
            color.foreground(GREEN_INTESE);
            cout << "---+---+---";
            color.foreground(BLUE_INTESE);
            cout << "+";
            color.foreground(GREEN_INTESE);
            cout << "---+---+---";
            color.foreground(BLUE_INTESE);
            cout << "+";
            color.reset();
            cout << endl;
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
            cout << color.foreground(BLUE_INTESE, "+") << color.foreground(GREEN, "---+---+---") << color.foreground(BLUE_INTESE, "+") << color.foreground(GREEN, "---+---+---") << color.foreground(BLUE_INTESE, "+") << color.foreground(GREEN, "---+---+---") << color.foreground(BLUE_INTESE, "+") << endl;

#endif
        }
        for (int j = 0; j < RC; j++)
        {
            if (j == 0 || j == 3 || j == 6)
            {
                if (scacchiera[i][j] == 0)
                {
#ifdef _WIN32
                    color.foreground(BLUE_INTESE);
                    cout << "| "
                         << " "
                         << " ";
                    color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                    cout << color.foreground(BLUE_INTESE, "| ") << " "
                         << " ";
#endif
                }

                else
                {
                    if (scacchiera[i][j] == 0)
                    {
#ifdef _WIN32
                        color.foreground(BLUE_INTESE);
                        cout << "| "
                             << " "
                             << " ";
                        color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                        cout << color.foreground(BLUE_INTESE, "| ") << " "
                             << " ";
#endif
                    }
#ifdef _WIN32
                    color.foreground(BLUE_INTESE);
                    cout << "| ";
                    color.foreground(YELLOW_INTENSE);
                    cout << scacchiera[i][j] << " ";
                    color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                    cout << color.foreground(BLUE_INTESE, "| ") << color.foreground(YELLOW_INTENSE, scacchiera[i][j]) << " ";
#endif
                }
            }
            else
            {
                if (scacchiera[i][j] == 0)
                {
#ifdef _WIN32
                    color.foreground(GREEN_INTESE);
                    cout << "| "
                         << " "
                         << " ";
                    color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                    cout << color.foreground(GREEN, "| ") << " "
                         << " ";
#endif
                }

                else
                {
#ifdef _WIN32
                    color.foreground(GREEN_INTESE);
                    cout << "| ";
                    color.foreground(YELLOW_INTENSE);
                    cout << scacchiera[i][j] << " ";
                    color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                    cout << color.foreground(GREEN, "| ") << color.foreground(YELLOW_INTENSE, scacchiera[i][j]) << " ";
#endif
                }
            }
        }
#ifdef _WIN32
        color.foreground(BLUE_INTESE);
        cout << "|";
        color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        cout << color.foreground(BLUE_INTESE, "|");
#endif

        cout << " " << i << setw(3);
        cout << endl;
    }
// cout << "+---+---+---+---+---+---+---+---+---+" << endl;
#ifdef _WIN32
    color.foreground(BLUE_INTESE);
    cout << "+---+---+---+---+---+---+---+---+---+";
    color.reset();
    cout << endl;
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    cout << color.foreground(BLUE_INTESE, "+---+---+---+---+---+---+---+---+---+") << endl;
#endif
}

#endif /* SUDOKU_H */
