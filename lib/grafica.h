#ifndef GRAFICA_H
#define GRAFICA_H
/**================================================================================================
 * *                                           INFO
 *  Autore    : Francesco Pio Nocerino
 *  @email    : kekko.dev16@gmail.com
 *  File      : grafica.h
 *  Versione  : 1.0
 *  Data      : 05/01/2023
 *  Descr     :
 * ? Libreria Grafica
 *================================================================================================**/
#include <iostream>
#include <iomanip>
#include <string>
#include "supporto_grafica.h"
using namespace std;
#define BAR "█"

void _barraCaricamento(int dim);
void _banner();
void _intro();

void _barraCaricamento(int dim)
{
    Color color;
    cl();
    _banner();
    cout << endl;
#ifdef _WIN32
    _UTF_16;
#endif
    for (int i = 0; i < dim; i++)
    {
        if (dim <= 20)
        {
#ifdef _WIN32
            color.foreground(RED_INTENSE);
            cout << flush << BAR;
            color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
            cout << flush << color.foreground(RED_INTENSE, BAR);
#endif
        }
        else
        {
            if (dim > 20 && dim <= 40)
            {
#ifdef _WIN32
                color.foreground(BLUE_INTESE);
                cout << flush << BAR;
                color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                cout << flush << color.foreground(BLUE_INTESE, BAR);
#endif
            }
            else
            {
#ifdef _WIN32
                color.foreground(GREEN_INTESE);
                cout << flush << BAR;
                color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
                cout << flush << color.foreground(GREEN_INTESE, BAR);
#endif
            }
        }
    }

    cout << endl;
    cout << "CARICAMENTO DEI FILE.... [" << dim * 2.46 << "%]\n";
}

void _banner()
{
    Color color;
#ifdef _WIN32
    color.foreground(BLUE_INTESE);
    cout << " _______          __       __          \n";
    cout << "|   _   .--.--.--|  .-----|  |--.--.--.\n";
    cout << "|   1___|  |  |  _  |  _  |    <|  |  |\n";
    color.foreground(GREEN_INTESE);
    cout << "|____   |_____|_____|_____|__|__|_____|\n";
    cout << "|:  1   |                              \n";
    cout << "|::.. . |                              \n";
    cout << "`-------' By> Francesco Pio Nocerino\n";
    color.reset();
#elif defined(__APPLE__) || defined(__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    cout << color.foreground(BLUE_INTESE, " _______          __       __          \n");
    cout << color.foreground(BLUE_INTESE, "|   _   .--.--.--|  .-----|  |--.--.--.\n");
    cout << color.foreground(BLUE_INTESE, "|   1___|  |  |  _  |  _  |    <|  |  |\n");
    cout << color.foreground(GREEN_INTESE, "|____   |_____|_____|_____|__|__|_____|\n");
    cout << color.foreground(GREEN_INTESE, "|:  1   |                              \n");
    cout << color.foreground(GREEN_INTESE, "|::.. . |                              \n");
    cout << color.foreground(GREEN_INTESE, "`-------' By> Francesco Pio Nocerino\n");
#endif
}

void _intro()
{
    cl();
    _banner();
    cout << "\nSudoku Classico\n";
    cout << "------------------\n";
    cout << "Nel gioco del Sudoku si parte da una griglia in cui sono gia' inseriti alcuni numeri.\nIl Sudoku,viene risolto quando in ciascuno dei 9 blocchi, righe e colonne compaiono, solo una volta, tutti i numeri da 1 a 9.\nEsamina la griglia e individua i numeri che possono essere inseriti in ciascuna casella.\n";
    cout << "----------------\n";
    cout << "> Come si Gioca?\n";
    cout << "Inserire le coordinate della cella dive da \';\' (1;1)\n";
    cout << "Una volta selezionata la cella inserire il numero\n";
    cout << "> Si possono fare al Massimo 3 errori dopo di che' il gioco finisce\n";
    cout << "----------------\n";
    cout << "> Per fermare il gioco inserire nella selezione della cella \':q\'\n";
    cout << "\nPremere Invio per iniziare.....";
    cin.get();
}

#endif /* GRAFICA_H */
