#ifndef Menu_hpp
#define Menu_hpp
#include "Algotrymy.hpp"
using std:: cout;
using std:: cerr;
using std:: endl;
using std:: cin;


template <class Type>
int UstawRozmTab (int IlTab, int &WTab, Type &Tab) {
    int wybor = 0;
    cin >> wybor;
    switch (wybor) {
        case 1:         // Wielkość tablicy:    10 000
            WTab = 10000;
            break;
        case 2:         // Wielkość tablicy:    50 000
            WTab = 50000;
            break;
        case 3:         // Wielkość tablicy:   100 000
            WTab = 100000;
            break;
        case 4:         // Wielkość tablicy:   500 000
            WTab = 500000;
            break;
        case 5:         // Wielkość tablicy: 1 000 000
            WTab = 1000000;
            break;
        default:
            cerr << " Błąd wyboru opcji! " << endl;
            delete [] *Tab;
            return 1;
    }
    for (int i = 0; i < IlTab; ++i)
        Tab[i] = new int[WTab];
    cout << "\n Stworzono: " << IlTab << " tablic po " << WTab << " liczb.\n";

    return 0;
}


template <class Type>
int UstawElWTab (int IlTab, int WTab,  Type &Tab) {
    int wybor = 0;
    cin >> wybor;
    switch (wybor) {
        case 1:
            for (int i = 0; i < IlTab; ++i)
                TabLosowo(Tab[i], WTab);
            cout << "\n Wszystkie elementy losowe.\n";
            break;
        case 2:
            cout << "\n Podaj procent: ";
            float procent;
            cin  >> procent;
            for (int i = 0; i < IlTab; ++i)
                TabNaProcent(Tab[i], WTab, procent);
            cout <<"\n "<< procent << "% elementów posortowanych.\n";
            break;
        case 3:
            for (int i = 0; i < IlTab; ++i)
                TabNaOdwrot(Tab[i], WTab);
            cout << "\n Wszystkie elementy posortowane w odwrotnej kolejności.\n";
            break;
        default:
            cerr << " Błąd wyboru opcji! " << endl;
            delete [] *Tab;
            return 1;
    }
//    ZapiszTabliceWPliku(IlTab, WTab, Tab);
    return 0;
}


template <class Type>
int Sortuj (int IlTab, int WTab,  Type &Tab) {
    int wybor = 0;
    cin >> wybor;
    cout << " Sortuję tablicę...";
    auto start = std::chrono::high_resolution_clock::now();
    switch (wybor) {
        case 1:         // Scalanie
            for (int i = 0; i < IlTab; ++i)
                MergeSort(Tab[i], 0, WTab-1);
            break;
            
        case 2:         // Quicksort
            for (int i = 0; i < IlTab; ++i)
                QuickSort(Tab[i], 0, WTab - 1);
            break;
            
        case 3:         // Kopcowanie
            for (int i = 0; i < IlTab; ++i)
                HeapSort(Tab[i], WTab);
            break;
            
        case 4:         // Wstawianie
            for (int i = 0; i < IlTab; ++i)
                InsertionSort(Tab[i], WTab);
            break;
            
        case 5:         // Introspektywne
            for (int i = 0; i < IlTab; ++i)
                IntroSort(Tab[i], WTab);
            break;
            
        default:
            cerr << " Błąd wyboru opcji! " << endl;
            delete [] *Tab;
            return 1;
    }
    auto end = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < IlTab; ++i)
        if (!CzyPosortowane(Tab[i], WTab)){
            cerr << "\n Nie udało się posortować. Wydrukować tablicę w pliku?  \n Twój wybór (0/1): ";
            cin  >> wybor;
            if (wybor)  ZapiszTabliceWPliku(IlTab, WTab, Tab);
            delete [] *Tab;
            return 1;
        }
    cout << "\n Udało się posortować!! C:\n Czas wykonania: "
         << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms\n\n";
//        ZapiszTabliceWPliku(IlTab, WTab, Tab);
    delete [] *Tab;
    return 0;
}


#endif
