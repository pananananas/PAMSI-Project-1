#ifndef Algotrymy_hpp
#define Algotrymy_hpp
#include "Tablica.hpp"
using std:: swap;


template <class Type>
static void Scal (Type *tab, int left, int middle, int right) {
    
    Type *pom=new Type[right+1];
    for (int i = (int) left; i <= right; i++)
        pom[i] = tab[i];
    int i = left, q = left, j = middle + 1;
    while (i <= middle && j <= right) {
        if (pom[i] < pom[j])
            tab[q++] = pom[i++];
        else
            tab[q++] = pom[j++];
    }
    while (i <= middle) tab[q++] = pom[i++];
    delete[] pom;
}


template <class Type>
static void MergeSort (Type *tab, int left, int right) {
    
    if (right <= left)    return;
    int middle = (right + left) / 2;
    MergeSort(tab, left, middle);
    MergeSort(tab, middle + 1, right);
    Scal(tab, left, middle, right);
}


template <class Type>
static void QuickSort (Type *tab, int left, int right) {

    int i = left,  j = right;
    Type x = tab[(left + right) / 2];
    while (i <= j) {
        while (tab[i] < x)      i++;
        while (tab[j] > x)      j--;

        if (i <= j) {
            swap(tab[i], tab[j]);
            i++;  j--;
        }
    }
    if (left  < j)      QuickSort(tab, left, j);
    if (right > i)      QuickSort(tab, i, right);
}


template <class Type>
static void InsertionSort(Type *tab, int size) {
    for (int i = 1; i < size; ++i) {
        int j = i;
        while ((j > 0))
        
            if (tab[j - 1] > tab[j]) {
                tab[j - 1] ^= tab[j];
                tab[j] ^= tab[j - 1];
                tab[j - 1] ^= tab[j];
                --j;
            }else    break;
    }
}


template <class Type>
static int Partition(Type *tab, int left, int right) {
    int pivot = tab[right];
    int temp;
    int i = left;

    for (int j = left; j < right; ++j)
        if (tab[j] <= pivot) {
            temp = tab[j];
            tab[j] = tab[i];
            tab[i] = temp;
            i++;
        }
    tab[right] = tab[i];
    tab[i] = pivot;

    return i;
}


template <class Type>
static void MaxHeapify(Type *tab, int heapSize, int index) {
    int left = (index + 1) * 2 - 1;
    int right = (index + 1) * 2;
    int largest = 0;

    if (left < heapSize && tab[left] > tab[index])          largest = left;
    else                                                    largest = index;
    if (right < heapSize && tab[right] > tab[largest])      largest = right;
    
    if (largest != index) {
        int tmp = tab[index];
        tab[index] = tab[largest];
        tab[largest] = tmp;

        MaxHeapify(tab, heapSize, largest);
    }
}


template <class Type>
static void HeapSort(Type *tab, int size) {
    int heapSize = size;

    for (int p = (heapSize - 1) / 2; p >= 0; --p)
        MaxHeapify(tab, heapSize, p);
    for (int i = size - 1; i > 0; --i) {
        int tmp = tab[i];
        tab[i] = tab[0];
        tab[0] = tmp;
        --heapSize;
        MaxHeapify(tab, heapSize, 0);
    }
}


template <class Type>
static void IntroSort(Type *tab, int size) {
        
    int partitionSize = Partition(tab, 0, size-1);
    if (partitionSize < 16 && partitionSize != 0)  InsertionSort(tab, size);
    else if (0 == (2 * log(size)))                 HeapSort(tab, size);
    else                                           QuickSort(tab, 0, size - 1);
}


#endif
