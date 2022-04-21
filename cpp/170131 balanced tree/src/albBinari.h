/*
 * balancedtree.h
 *
 *  Created on: 5 set 2020
 *      Author: utente
 */

#ifndef ALBBINARI_H_
#define ALBBINARI_H_

#include <iostream>
using namespace std;

template<class T>
class albBinari {

public:
	typedef int Nodo;
	static const int NuLL = -1;

	typedef struct _cella {
		Nodo figliosx = NuLL;
		Nodo figliodx = NuLL;
		T value;
	} Cella;
	albBinari();
	albBinari(int);
	virtual ~albBinari();
	void creaAlbero();

	bool isEmpty();
	bool isLeaf(Nodo);
	Nodo getFiglioSx(Nodo);
	Nodo getFiglioDx(Nodo);
	void insFiglioSx(Nodo, T);
	void insFiglioDx(Nodo, T);
	bool isFiglioSxEmpty(Nodo);
	bool isFiglioDxEmpty(Nodo);

	bool isRoot(Nodo);
	Nodo getRoot();
	void insRoot(T);
	void insRoot();

	void setValoreNodo(Nodo, T);
	T getValoreNodo(Nodo);

	Nodo getPadre(Nodo);

	void stampaAlbero();
	Nodo operator =(Nodo);
protected:
	void stampaSottoAlbero(Nodo);
	void erase(Nodo);

	Cella *spazio;
	int nNodi;
	int MAXLUNG = 100;
};

template<class T> albBinari<T>::albBinari() {
	creaAlbero();
}

template<class T> albBinari<T>::albBinari(int n) {
	MAXLUNG = n;
	creaAlbero();
}

template<class T> albBinari<T>::~albBinari() {
	delete[] spazio;
}

template<class T> void albBinari<T>::creaAlbero() {
	spazio = new Cella[MAXLUNG];
	nNodi = 0;
}

template<class T> bool albBinari<T>::isEmpty() {
	return (nNodi == 0);
}

template<class T> bool albBinari<T>::isLeaf(Nodo t) {
	return (isFiglioDxEmpty(t) && isFiglioSxEmpty(t));
}

template<class T> typename albBinari<T>::Nodo albBinari<T>::getRoot() {
	if (!isEmpty())
		return 0;
	else {
		cout << "Albero Vuoto";
		return NuLL;
	}
}

template<class T> typename albBinari<T>::Nodo albBinari<T>::getPadre(Nodo t) {
	Nodo temp;
	if (t != getRoot() && !isEmpty()) {
		for (int i = 0; i < nNodi; i++) {
			if (spazio[i]->figliodx == NuLL && spazio[i]->figliosx == NuLL) {
				return NuLL;
			} else {
				if (spazio[i]->figliosx == NuLL) {

				} else if (spazio[i]->figliosx == t) {
					return i;
				}

				if (spazio[i]->figliodx == NuLL) {

				} else if (spazio[i]->figliodx == t) {
					return spazio[i];
				}
			}
		}
	}
	cout << "Padre di ";
	cout << t;
	cout << " non trovato";
	return NuLL;
}

template<class T> typename albBinari<T>::Nodo albBinari<T>::getFiglioDx(
		Nodo t) {
	return spazio[t].figliodx;
}

template<class T> typename albBinari<T>::Nodo albBinari<T>::getFiglioSx(
		Nodo t) {
	return spazio[t].figliosx;
}

template<class T> bool albBinari<T>::isFiglioSxEmpty(Nodo t) {
	return (spazio[t].figliosx == -1);
}

template<class T> bool albBinari<T>::isFiglioDxEmpty(Nodo t) {
	return (spazio[t].figliodx == -1);
}

template<class T> T albBinari<T>::getValoreNodo(Nodo t) {
	return spazio[t].value;
}

template<class T> void albBinari<T>::setValoreNodo(Nodo t, T elemento) {
	spazio[t].value = elemento;
}

template<class T> void albBinari<T>::insRoot(T valore) {
	if (isEmpty()) {
		spazio[nNodi].value = valore;
		nNodi++;
	}
}

template<class T> void albBinari<T>::insFiglioDx(Nodo t, T valore) {
	if (isFiglioDxEmpty(t)) {
		spazio[t].figliodx = nNodi;
		spazio[nNodi].value = valore;
		nNodi++;
	}
}

template<class T> void albBinari<T>::insFiglioSx(Nodo t, T valore) {
	if (spazio[t].value != NuLL && isFiglioSxEmpty(t)) {
		spazio[t].figliosx = nNodi;
		spazio[nNodi].value = valore;
		nNodi++;
	}
}

template<class T> void albBinari<T>::stampaAlbero() {
	stampaSottoAlbero(getRoot());
}

template<class T> void albBinari<T>::stampaSottoAlbero(Nodo t) {
	cout << "[ ";
	cout << spazio[t].value;
	cout << " ,";
	if (spazio[t].figliosx != NuLL)
		stampaSottoAlbero(spazio[t].figliosx);
	else
		cout << "NuLL";
	cout << " ,";
	if (spazio[t].figliodx != NuLL)
		stampaSottoAlbero(spazio[t].figliodx);
	else
		cout << "NuLL";
	cout << " ]";
}

template<class T>
std::ostream& operator<<(std::ostream &out, albBinari<T> t) {
	t.stampaAlbero();
	return out;
}

#endif /* ALBBINARI_H_ */
