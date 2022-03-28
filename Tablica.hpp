#ifndef Tablica_hpp
#define Tablica_hpp
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <chrono>    // Do liczenia czasu
#include <ctime>
#include <cmath>
using std:: cin;
using std:: cout;
using std:: endl;


template <class Type>
bool CzyPosortowane (Type tab[], int size) {
    for (int i = 0; i < size - 1; i++)
        if (tab[i] > tab[i + 1])
            return false;
    return true;
}


template <class Type>
void TabNaOdwrot (Type tab[], int size) {
    for (int i = 0; i < size; ++i)
        tab[i] = size - i;
}


template <class Type>
void TabNaProcent (Type tab[], int size, float proc) {
    srand( (unsigned int) time(NULL) );   /* Inicjuje losowanie liczb. Normalnie
                                             srand() potrzebuje unsigned int, a time()
                                             zwraca long int, więc trzeba skonwertowac
                                             to podajac nawias przed time() */
    for (int i = 0; i < size; i++)
        if (i < size*proc / 100)    tab[i] = i;
        else                        tab[i] = rand();
}


template <class Type>
void TabLosowo (Type *tab, int size) {
    srand( (unsigned int) time(NULL) );
    for (int i = 0; i < size; i++)
        tab[i] = rand();
}


template <class Type>
void WyswietlTablice (int IlTab, int WTab, Type Tab) {
    
    for (int j=0; j<IlTab; ++j)
        for (int i = 0; i < WTab; ++i) {
            cout << Tab[j][i] << ", ";
            if ((i+1) % 1000 == 0)
                cout << endl;
        }
}


template <class Type>
void ZapiszTabliceWPliku (int IlTab, int WTab, Type Tab) {
    std::fstream zapis;
    zapis.open("zapis.txt", std::ios::out);
    zapis << " Tablica:\n";
    for (int j=0; j<IlTab; ++j)
        for (int i = 0; i < WTab; ++i) {
            zapis << Tab[j][i] << ", ";
            if ((i+1) % 1000 == 0)
                zapis << endl;
        }
    cout << " Zapisano tablicę w pliku \"zapis.txt\".\n";
}


#endif
