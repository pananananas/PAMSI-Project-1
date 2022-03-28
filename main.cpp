#include "Menu.hpp"
void Menu (int i) {
    if (i == 1)
        std::cout
        << " * * * * * * * * * * * * * * * * * * *\n"
        << " *  Wybierz wielkość tablicy:        *\n"
        << " *   1   -      10 000               *\n"
        << " *   2   -      50 000               *\n"
        << " *   3   -     100 000               *\n"
        << " *   4   -     500 000               *\n"
        << " *   5   -   1 000 000               *\n"
        << " * * * * * * * * * * * * * * * * * * *\n";
    else if (i == 2)
        std::cout
        << "\n * * * * * * * * * * * * * * * * * * *\n"
        << " *  Wybierz przypadek sortowania     *\n"
        << " *   1   -   Wszystkie el. losowe    *\n"
        << " *   2   -   % el. losowych          *\n"
        << " *   3   -   Odwrotna kolejność      *\n"
        << " * * * * * * * * * * * * * * * * * * *\n";
    else if (i == 3)
        std::cout
        << "\n * * * * * * * * * * * * * * * * * * *\n"
        << " *  Wybierz rodzaj sortowania        *\n"
        << " *   1   -   Scalanie                *\n"
        << " *   2   -   Quicksort               *\n"
        << " *   3   -   Kopcowanie              *\n"
        << " *   4   -   Wstawianie              *\n"
        << " *   5   -   Introspektywne          *\n"
        << " * * * * * * * * * * * * * * * * * * *\n";
    std::cout << " Twój wybór: ";
}

int main(){
    int IlTab = 100,   WTab = 0;
    int** Tab = new int*[IlTab];
    Menu(1);  if (UstawRozmTab (IlTab, WTab, Tab)) return 1;
    Menu(2);  if (UstawElWTab  (IlTab, WTab, Tab)) return 2;
    Menu(3);  if (Sortuj       (IlTab, WTab, Tab)) return 3;
                                                   return 0;
}
