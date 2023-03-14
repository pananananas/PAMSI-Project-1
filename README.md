# Sorting-algorithms
Algorytmy sortowania 

Projekt realizowany w ramach kursu: Projektowanie Algorytmów i Metod Sztucznej Inteligencji.

Samodzielna implementacja algorytmów sortowania:

### MergeSort
Jest to algorytm dzielący tablice rekurencyjnie na dwie podtablice, sortuje je oddzielnie przez scalanie, chyba że pozostał już tylko jeden element, a następnie łączy posortowane podtablice w jedną posortowaną. Złożoność obliczeniowa tego algorytmu wynosi O(n logn).

### Quicksort
Jest to jeden z najpopularniejszych algorytmów sortowania. Na początku wybiera się element osiowy (w tym przypadku środek tablicy), po czym pierwszy element od początku tablicy większy od element osiowego zamienia się miejscami z pierwszym elementem od końca tablicy mniejszym od elementu osiowego. następnie sortuje się osobno lewą i prawą część tablicy. Złożoność obliczeniowa tego algorytmu wynosi O (n log n), a w pesymistycznym przypadku O (n2).

### HeapSort
W algorytmie tym wykorzystywana jest struktura zwana drzewem binarnym. Na początku jego działania tworzony jest kopiec, w taki sposób, że każdy kolejny dodany element tablicy przemieszczany jest w górę kopca. Po utworzeniu kopca następuje sortowanie właściwe. Wtedy górny element kopca jest usuwany, w jego miejsce wstawia się element maksymalny, a usunięty element ląduje przed ustawionym właśnie elementem maksymalnym. W ten sposób ilość elementów kopca kurczy się, a ilość elementów tablicy rośnie. Jego atutem jest dobra złożoność pesymistyczna, wynosząca O (n logn).

### InsertionSort
Jest to jeden z najprostszych do zaimplementowania algorytmów, lecz jest on bardzo złożony obliczeniowo. Zasada jego działania polega na pobieraniu kolejnego elementu z nieposortowanej tablicy i porównywaniu go z kolejnymi elementami posortowanego zbioru, dopóki nie napotkamy elementu większego lub równego. Jest efektywny jedynie dla małych zbiorów danych i dla nich może być szybszy niż algorytmy o teoretycznie lepszej złożoności obliczeniowej. Jego złożoność obliczeniowa wynosi O (n2). Ten algorytm nie będzie brany pod uwagę w badaniach, ze względu na wydłużony czas operacji. Został jednak zaimplementowany ze względu na kolejny rodzaj sortowania.

### IntroSort
Jest to algorytm hybrydowy, wykorzystujący najlepsze cechy algorytmów Quicksort, Heapsort oraz Insertionsort, jednocześnie unikając ich wad. Sortowanie introspektywne zaczyna się od sortowania szybkiego, chyba że mamy do czynienia z dużą tablicą, wtedy korzysta z sortowania przez kopcowanie. Gdy partycja jest mała korzysta z sortowania przez wstawianie. Korzystając z zalet wymienionych algorytmów złożoność pesymistyczna wynosi O (n log n).

## Wnioski z testów
- Z wykresów zależności czasu od ilości elementów widać, że Quicksort poradził sobie najlepiej, lecz tuż za nim plasował się Introsort, który w teorii powinien być szybszy, jednak częściowo korzystał z sortowania przez wstawianie, co przy tak dużych tablicach nie jest efektywne.
- Zgodnie z przewidywaniami sortowanie przez scalanie przez swoją złożoność obliczeniową jest najwolniejsze z wszystkich badanych algorytmów. Co ciekawe czas nie wydłuża się znacznie ze względu na przypadki, więc czas sortowania w pełni losowanej tablicy jest całkiem podobny do czasu tablicy posortowanej w 99%.
- Sortowanie przez kopcowanie jest szybkie, wolniejsze od quicksorta, lecz to było spodziewane. W przypadku kopcowania jest podobnie jak w scalaniu, czas nie różni się znacznie w zależności od sortowanej tablicy.
- Zgodnie z przewidywaniami sortowanie losowe trwa najdłużej dla wszystkich algorytmów, lecz nie spodziewałem się, że sortowanie odwrotnych liczb w niemalże każdym przypadku trwa najkrócej, nawet krócej niż posortowanej tablicy w 99.7%.
