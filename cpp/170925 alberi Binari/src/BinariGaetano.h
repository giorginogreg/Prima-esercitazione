/*
 * BinariGaetano.h
 *
 *  Created on: 28 ago 2020
 *      Author: utente
 */

#ifndef BINARIGAETANO_H_
#define BINARIGAETANO_H_
#include <iostream>
using namespace std;

template<class T>
class BinariGaetano {
public:
	typedef int Nodo;
	typedef struct _nodo {
		T value = -1;
		Nodo figliodx = -1;
		Nodo figliosx = -1;
	} Cella;
	BinariGaetano();
	BinariGaetano(int);
	~BinariGaetano();
	void creaAlbero();
	bool binalberovuoto();
	Nodo binradice();
	Nodo binpadre(Nodo);
	Nodo figliosinistro(Nodo);
	Nodo figliodestro(Nodo);
	bool sinistrovuoto(Nodo);
	bool destrovuoto(Nodo);
	T leggiValoreNodo(Nodo);
	void scriviValoreNodo(T, Nodo);
	void insBinRadice();
	void insFiglioSinistro(Nodo);
	void insFiglioDestro(Nodo);
	void stampaAlbero();
	Nodo operator =(Nodo);
private:
	void stampaSottoAlbero(Nodo);
	void erase(Nodo);

	Cella *spazio;
	int MAXLUNG = 10;
	int nNodi;
};

template<class T> BinariGaetano<T>::BinariGaetano() {
	creaAlbero();
}

template<class T> BinariGaetano<T>::BinariGaetano(int n) {
	MAXLUNG = n;
	creaAlbero();
}

template<class T> BinariGaetano<T>::~BinariGaetano() {
	delete[] spazio;
}


template<class T> void BinariGaetano<T>::creaAlbero() {
	spazio = new Cella[MAXLUNG];
	nNodi = 0;
}

template<class T> bool BinariGaetano<T>::binalberovuoto() {
	return (nNodi == 0);
}

template<class T> typename BinariGaetano<T>::Nodo BinariGaetano<T>::binradice() {
	if (!binalberovuoto())
		return 0;
	else {
		cout << "Albero Vuoto";
		return -1;
	}
}

template<class T> typename BinariGaetano<T>::Nodo BinariGaetano<T>::binpadre(
		Nodo t) {
	Nodo temp;
	if (t != binradice() && !binalberovuoto()) {
		for (int i = 0; i < nNodi; i++) {
			if (spazio[i]->figliodx == -1 && spazio[i]->figliosx == -1) {
				return -1;
			} else {
				if (spazio[i]->figliosx == -1) {

				} else if (spazio[i]->figliosx == t) {
					return i;
				}

				if (spazio[i]->figliodx == -1) {

				} else if (spazio[i]->figliodx == t) {
					return spazio[i];
				}
			}
		}
	}
	cout << "Padre di " ;
	cout << t;
			cout << " non trovato";
	return -1;
}

template<class T> typename BinariGaetano<T>::Nodo BinariGaetano<T>::figliodestro(
		Nodo t) {
	return spazio[t].figliodx;
}

template<class T> typename BinariGaetano<T>::Nodo BinariGaetano<T>::figliosinistro(
		Nodo t) {
	return spazio[t].figliosx;
}

template<class T> bool BinariGaetano<T>::sinistrovuoto(Nodo t) {
	return (spazio[t].figliosx == -1);
}

template<class T> bool BinariGaetano<T>::destrovuoto(Nodo t) {
	return (spazio[t].figliodx == -1);
}

template<class T> T BinariGaetano<T>::leggiValoreNodo(Nodo t) {
	return spazio[t]->value;
}

template<class T> void BinariGaetano<T>::scriviValoreNodo(T elemento, Nodo t) {
	spazio[t].value = elemento;
}

template<class T> void BinariGaetano<T>::insBinRadice() {
	if (binalberovuoto()) {
		spazio[nNodi].value = 0;
		nNodi++;
	}
}

template<class T> void BinariGaetano<T>::insFiglioDestro(Nodo t) {
	if (spazio[t].value != -1 && destrovuoto(t)) {
		spazio[t].figliodx = nNodi;
		if (spazio[t].value == 0)
			spazio[nNodi].value = 1;
		else
			spazio[nNodi].value = 0;
		nNodi++;
	}
}

template<class T> void BinariGaetano<T>::insFiglioSinistro(Nodo t) {
	if (spazio[t].value != -1 && sinistrovuoto(t)) {
		spazio[t].figliosx = nNodi;
		if (spazio[t].value == 0)
			spazio[nNodi].value = 1;
		else
			spazio[nNodi].value = 0;
		nNodi++;
	}
}

template<class T> void BinariGaetano<T>::stampaAlbero() {
	stampaSottoAlbero(binradice());
}

template<class T> void BinariGaetano<T>::stampaSottoAlbero(Nodo t) {
	cout << "[ ";
	cout << spazio[t].value;
	cout << " ,";
	if (spazio[t].figliosx != -1)
		stampaSottoAlbero(spazio[t].figliosx);
	else
		cout << "NULL";
	cout << " ,";
	if (spazio[t].figliodx != -1)
		stampaSottoAlbero(spazio[t].figliodx);
	else
		cout << "NULL";
	cout << " ]";
}

template<class T>
std::ostream& operator<<(std::ostream &out, BinariGaetano<T> t) {
	t.stampaAlbero();
	return out;
}


#endif /* BINARIGAETANO_H_ */
