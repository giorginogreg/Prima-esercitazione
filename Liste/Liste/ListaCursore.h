#include "ListaLineare.h"
#include <bits/stdc++.h> 

template <class T>
class ListaCursore : public ListaLineare<T, int> { // Classe Lista

    public:

        typedef typename ListaLineare<T, int>::tipoelem tipoelem;
        typedef typename ListaLineare<T, int>::posizione posizione;

        // Prototipi

        ListaCursore(); // Costruttore
        ListaCursore(const ListaCursore<T, int>&); // Costruttore di copia
        ~ListaCursore(); // Distruttore

        // Operatori
        ListaCursore crealista();
        bool listaVuota() const;

        T leggiLista(posizione) const;
        void scriviLista(T, posizione);

        posizione primoLista() const; // const = vincolo che non ti permette la modifica dello stato dell'oggetto
        posizione fineLista() const; 

        posizione succLista(posizione) const;
        posizione predLista(posizione) const;

        void insLista(T, posizione);
        void cancLista(posizione);

    private:

        typedef struct nodo {
            T elem;
            posizione succ;
        };
            
        int lunghezza; // Lunghezza della lista

        const int dimVettoreSpazio = 20; // Dimensione massima della lista
        
        nodo* vetSpazio; // Vettore spazio

        int listaLibera; // Lista libera
        int listaCursore; // Lista Cursore (punto di partenza)

        void initListaLibera():

        void sposta(posizione, posizione);

}

template <class T>
ListaCursore<T>::ListaCursore() {
    this->crealista();
    this->initListaLibera();
}

template <class T>
ListaCursore<T>::crealista(){
    this->vetSpazio = new nodo[dimVettoreSpazio];
    lunghezza = 0;
    listaCursore = 0;
}

template <class T>
bool ListaCursore::listaVuota() {
    return lunghezza == 0;
}

template <class T>
T ListaCursore::leggiLista(posizione pos) {

}

template <class T>
void ListaCursore::scriviLista(T elem, posizione pos) {
    if (isInRange(pos)) {
        nodo[pos]->elem = elem;
    }
}

template <class T>
posizione ListaCursore::primolista() {
    
}

template <class T>       
posizione ListaCursore::finelista() {

}

template <class T>
posizione ListaCursore::succlista(posizione pos) {

}

template <class T>
posizione ListaCursore::predlista(posizione pos) {

}

template <class T>
void ListaCursore::inslista(T elem, posizione pos) {
    if(listaLibera == 0) {
        // ERRORE
    } else if (pos == 1) {
        this->sposta(listaLibera, listaCursore);
        vetSpazio[listaCursore]->elem = elem;
    } else {
        this->sposta(listaLibera, vetSpazio[pos]->succ);
        vetSpazio[vetSpazio[pos]->succ]->elem = elem;
    }
}
        
template <class T>
void ListaCursore::canclista(posizione pos) {
    if (pos == 1) {
        this->sposta(listaCursore, listaLibera);
    } else {
        this->sposta(vetSpazio[pos]->succ, listaLibera);
    }
}

void ListaCursore::initListaLibera() {
    listaLibera = 1;
    for (int i = 0; i < dimVettoreSpazio - 1; i++) {
        vetSpazio[i].succ = i + 1;
    }
    vetSpazio[dimVettoreSpazio - 1].succ = 0;
}

template <class T>
void ListaCursore::sposta(posizione pos1, posizione pos2) {
    posizione temp = pos2;
    pos2 = pos1;
    pos1 = ListaCursore::vetSpazio[pos1]->succ;
    ListaCursore::vetSpazio[pos2]->succ = temp;
}

bool isInRange(posizione pos) {
    return pos > 1 && pos < lunghezza;
}