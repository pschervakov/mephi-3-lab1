//
// Created by philip on 10/6/20.
//
#include "iostream"
#include "sorts.h"
#include "string.h"

using std::cout, std::cin, std::endl, std::string;


void start(Sequence<int> *seq, int alg) {
    float start_time;
    if (alg == 1) {
        start_time = clock();
        InsertSort(seq);
        seq->print_seq();
        cout << "\n";
        cout << "Insert sort : " << (clock() - start_time) / CLOCKS_PER_SEC << " seconds" << endl;

    } else if (alg == 2) {
        start_time = clock();
        SelectionSort(seq);
        seq->print_seq();
        cout << "\n";
        cout << "Selection sort : " << (clock() - start_time) / CLOCKS_PER_SEC << " seconds" << endl;
    } else if (alg == 3) {
        start_time = clock();
        QuickSort(seq, 0, seq->get_size() - 1);
        seq->print_seq();
        cout << "\n";
        cout << "QuickSort : " << (clock() - start_time) / CLOCKS_PER_SEC << " seconds" << endl;

    } else if (alg == 4) {
        start_time = clock();
        InsertSort(seq);
        cout << "Insert sort : " << (clock() - start_time) / CLOCKS_PER_SEC << " seconds" << endl;
        start_time = clock();
        SelectionSort(seq);
        cout << "Selection sort : " << (clock() - start_time) / CLOCKS_PER_SEC << " seconds" << endl;
        start_time = clock();
        QuickSort(seq, 0, seq->get_size() - 1);
        cout << "QuickSort : " << (clock() - start_time) / CLOCKS_PER_SEC << " seconds" << endl;
    }

}

Sequence<int> *generate_seq(int num, int type, int seq_gen) {
    Sequence<int> *seq;
    if (type == 1) {
        seq = new ArraySequence<int>(num);

    } else if (type == 2) {
        seq = new ListSequence<int>(num);
    }
    if (seq_gen == 2) {
        for (int i = 0; i < num; ++i) {
            (*seq)[i] = i;
        }
        shuffle(seq);
    } else if (seq_gen == 1) {
        for (int i = 0; i < num; ++i) {
            cin >> (*seq)[i];
        }
    }
    return seq;
}

void print_menu(string type) {
    if (type == "algorithm") {
        cout << "Choose sort algorithm ";
        cout << "1. Insert sort ";
        cout << "2. Selection sort ";
        cout << "3. Quick sort ";
        cout << "4. Compare all ";
        cout << endl;
    } else if (type == "sequence type") {
        cout << "Choose sequence ";
        cout << "1. ArraySequence ";
        cout << "2. ListSequence ";
        cout << endl;
    } else if (type == "number") {
        cout << "1. Enter the number of items ";
        cout << endl;
    } else if (type == "sequence") {
        cout << "1. Enter your sequence ";
        cout << "2. Generate random sequence ";
        cout << endl;
    } else if (type == "continue") {
        cout << "1. Continue ";
        cout << "2. Exit";
        cout << endl;
    }
}


int main() {
    int alg, seq_type, num, seq_gen;
    int cont = 1;
    while (cont == 1) {
        print_menu("algorithm");
        cin >> alg;
        print_menu("sequence type");
        cin >> seq_type;
        print_menu("number");
        cin >> num;
        print_menu("sequence");
        cin >> seq_gen;
        Sequence<int> *seq = generate_seq(num, seq_type, seq_gen);
        start(seq, alg);
        print_menu("continue");
        cin >> cont;
    }
}


