#ifndef SUDOKU_H
#define SUDOKU_H
/**================================================================================================
 * *                                           INFO
 *  Autore    : Francesco Pio Nocerino
 *  @email    : kekko.dev16@gmail.com
 *  File      : sudoku.h
 *  Versione  : 2.0
 *  Data      : 02/01/2023
 *  Descr     :
 * ? Libreria gioco Sudoku
 *================================================================================================**/
#ifdef _WIN32
#include <windows.h>
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
#include <unistd.h>
#endif
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <time.h>
#include "genera.h"
#include "grafica.h"
#include "giocatore.h"
#include "supporto_grafica.h"
using namespace std;
#define RC 9                               // numero righe-colonne
#define MAPPA_1 "../file/mappe/mappa1.csv" // mappe la scacchiera
#define MAPPA_2 "../file/mappe/mappa2.csv"
#define MAPPA_3 "../file/mappe/mappa3.csv"
#define MAPPA_4 "../file/mappe/mappa4.csv"
#define MAPPA_5 "../file/mappe/mappa5.csv"
#define MAPPA_6 "../file/mappe/mappa6.csv"
#define MAPPA_7 "../file/mappe/mappa7.csv"
#define MAPPA_8 "../file/mappe/mappa8.csv"
#define MAPPA_9 "../file/mappe/mappa9.csv"
#define MAPPA_10 "../file/mappe/mappa10.csv"
#define MAPPA_11 "../file/mappe/mappa11.csv"
#define MAPPA_12 "../file/mappe/mappa12.csv"
#define MAPPA_13 "../file/mappe/mappa13.csv"
#define MAPPA_14 "../file/mappe/mappa14.csv"
#define MAPPA_15 "../file/mappe/mappa15.csv"
#define MAPPA_16 "../file/mappe/mappa16.csv"
#define MAPPA_17 "../file/mappe/mappa17.csv"
#define MAPPA_18 "../file/mappe/mappa18.csv"
#define MAPPA_19 "../file/mappe/mappa19.csv"
#define MAPPA_20 "../file/mappe/mappa20.csv"
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
        Genera genera;
        int map, diff;
        string n, en;
        map = genera._generaNumero(1, 20);
        switch (map)
        {
        case 1:
            File.open(MAPPA_1, ios::in);
            break;
        case 2:
            File.open(MAPPA_2, ios::in);
            break;
        case 3:
            File.open(MAPPA_3, ios::in);
            break;
        case 4:
            File.open(MAPPA_4, ios::in);
            break;
        case 5:
            File.open(MAPPA_5, ios::in);
            break;
        case 6:
            File.open(MAPPA_6, ios::in);
            break;
        case 7:
            File.open(MAPPA_7, ios::in);
            break;
        case 8:
            File.open(MAPPA_8, ios::in);
            break;
        case 9:
            File.open(MAPPA_9, ios::in);
            break;
        case 10:
            File.open(MAPPA_10, ios::in);
            break;
        case 11:
            File.open(MAPPA_11, ios::in);
            break;
        case 12:
            File.open(MAPPA_12, ios::in);
            break;
        case 13:
            File.open(MAPPA_13, ios::in);
            break;
        case 14:
            File.open(MAPPA_14, ios::in);
            break;
        case 15:
            File.open(MAPPA_15, ios::in);
            break;
        case 16:
            File.open(MAPPA_16, ios::in);
            break;
        case 17:
            File.open(MAPPA_17, ios::in);
            break;
        case 18:
            File.open(MAPPA_18, ios::in);
            break;
        case 19:
            File.open(MAPPA_19, ios::in);
            break;
        case 20:
            File.open(MAPPA_20, ios::in);
            break;
        default:
            break;
        }
        while (!File.eof())
        {
            for (int i = 0; i < RC; i++)
            {
                diff = 0;
                for (int j = 0; j < RC; j++)
                {
                    getline(File, n, ',');
                    scacchiera[i][j] = toInt(n);
                }
                getline(File, en, '\n');
            }
        }
        shiftNum();
        File.close();
    };
    void shiftNum();
    int toInt(string str);
    void _sleep(int d);
    void set_xy(int x, int y);             // setta la posizione
    void set_mossa(int num);               // assegna il numero alla posizione settata
    int get_cella(int x, int y);           // restituisce il contenuto della cella
    void salva_stato(Giocatore giocatore); // salva lo stato attuale della scacchiera
    bool _orizzontaleInit(int i, int j, int m[RC][RC]);
    bool _verticaleInit(int i, int j, int m[RC][RC]);
    void stampa(); // stampa della scacchiera
};
void Sudoku::shiftNum()
{
    Genera genera;

    int i = 0; // diagonale
    for (int y = 0; y < RC; y++, i++)
        scacchiera[i][y] = 0;
    i = RC - 1; // antidiagonali
    for (int y = 0; y < RC; y++, i--)
        scacchiera[i][y] = 0;

    i = 2;
    for (int y = 2; y < RC; y++, i++)
        scacchiera[i][y] = 0;

    i = RC - 2;
    for (int y = 2; y < RC; y++, i--)
        scacchiera[i][y] = 0;

    for (int k = 0; k < RC; k += 2) // colonne
    {
        for (int p = 0; p < RC; p += 2)
        {
            scacchiera[k][p] = 0;
        }
    }
}

int Sudoku::toInt(string str)
{
    int r;
    stringstream ss;
    ss << str;
    ss >> r;
    return r;
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

bool Sudoku::_orizzontaleInit(int i, int j, int m[RC][RC])
{
    bool found = false;
    for (int p = 0; p < j; p++)
    {
        if (m[i][j] == m[i][p])
            found = true;
    }
    return found;
}

bool Sudoku::_verticaleInit(int i, int j, int m[RC][RC])
{
    bool found = false;
    for (int p = 0; p < i; p++)
    {
        if (m[i][j] == m[p][j])
            found = true;
    }
    return found;
}

void Sudoku::stampa()
{
    Color color;
    for (int i = 0; i < RC; i++)
    {
#ifdef _WIN32
        cout << "  ";
        color.foreground(YELLOW_INTENSE);
        cout << i;
        color.reset();
        cout << " ";

#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        cout << "  " << color.foreground(YELLOW_INTENSE, i) << " ";
#endif
    }

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
                    color.reset();
                    cout << scacchiera[i][j] << " ";

#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                    cout << color.foreground(BLUE_INTESE, "| ") << scacchiera[i][j] << " ";
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
                    color.reset();
                    cout << scacchiera[i][j] << " ";
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                    cout << color.foreground(GREEN, "| ") << scacchiera[i][j] << " ";
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

#ifdef _WIN32
        cout << " ";
        color.foreground(YELLOW_INTENSE);
        cout << i << setw(3);
        color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        cout << " " << color.foreground(YELLOW_INTENSE, i) << setw(3);
#endif

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
