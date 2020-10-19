#include <iostream>
#include "sequence/Sequence.h"
#include "sequence/ArraySequence.h"
#include "sequence/ListSequence.h"
#include "sequence/LinkedList.h"
#include "sequence/DynamicArray.h"

template<typename T>
int default_cmp(T a, T b) {
    if (a > b) {
        return 1;
    } else if (a < b) {
        return -1;
    } else return 0;

}

template<typename T>
void shuffle(Sequence<T> *seq) {
    srand(time(0));
    for (int i = 0; i < seq->get_size(); ++i) {
        swap(seq, i, rand() % seq->get_size());
    }

}

template<typename T>
void reverse(Sequence<T> *seq) {
    for (int i = 0; i < seq->get_size() - 1; ++i) {
        swap(seq, i, seq->get_size() - 1 - i);
    }
}

template<typename T>
void swap(Sequence<T> *seq, int i, int j) {
    T tmp = (*seq)[i];
    (*seq)[i] = (*seq)[j];
    (*seq)[j] = tmp;

}

template<typename T>
int max(Sequence<T> *seq, int n, int (*cmp)(T, T) = &default_cmp) {
    T max_el = -1;
    int max_idx = -1;
    for (int i = 0; i < n; ++i) {
        if ((*cmp)((*seq)[i], max_el) > 0) {
            max_el = (*seq)[i];
            max_idx = i;
        }
    }
    return max_idx;
}

template<class T>
Sequence<T> *QuickSort(Sequence<T> *seq, int low, int high, int (*cmp)(T, T) = &default_cmp) {

    int i = low, j = high;

    T pivot = (*seq)[low];

    while (i <= j) {
        while ((*cmp)((*seq)[i], pivot) < 0)
            i++;
        while ((*cmp)((*seq)[j], pivot) > 0)
            j--;
        if (i <= j) {
            swap(seq, i, j);
            i++;
            j--;
        }
    }

    if (j - low > 0)
        QuickSort(seq, low, j);
    if (high > i)
        QuickSort(seq, i, high);

    return seq;
}

template<class T>
void SelectionSort(Sequence<T> *seq, int (*cmp)(T, T) = &default_cmp) {
    for (int i = seq->get_size() - 1; i >= 1; --i) {
        swap(seq, max(seq, i + 1), i);
    }
}

template<class T>
void InsertSort(Sequence<T> *seq, int (*cmp)(T, T) = &default_cmp) {
    for (int i = 1; i < seq->get_size(); ++i) {

        for (int j = i; j > 0 and (*cmp)((*seq)[j], (*seq)[j - 1]) < 0; --j) {
            swap(seq, j - 1, j);
        }
    }
}

