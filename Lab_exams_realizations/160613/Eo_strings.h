//
// Created by Greg on 05/04/22.
//

#ifndef POINTERQUEUE_EO_STRINGS_H
#define POINTERQUEUE_EO_STRINGS_H

#include <string>
#include "/Users/greg/Desktop/Universita/ASD/Esercitazioni_ASD/TDA_by_greg/Lists/pointer_implementation/Linked List/include/LinkedList.h"
using namespace std;

class Eo_strings {

    // inserisce una stringa nella corrispondente lista
    void inserisci(string s);

    // rimuove la stringa dalla corrispondente lista
    void rimuovi(string s);

    // rimuove le stringhe di lunghezza pari che iniziano con il carattere c
    void rimuovi(char c);

    // restituisce il numero di stringhe di lunghezza pari
    int freq_pari();

    // visualizza le stringhe di lunghezza dispari ordinate per lunghezza
    void visualizza_dispari();

private:
    LinkedList<string, 0> pari;
    LinkedList<string, 0> dispari;
};

#endif //POINTERQUEUE_EO_STRINGS_H
