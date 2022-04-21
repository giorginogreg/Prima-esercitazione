/*
 * AlberiNari.h
 *
 *  Created on: 28 ago 2020
 *      Author: utente
 */

#ifndef ALBERINARI_H_
#define ALBERINARI_H_
#include <iostream>
#include <vector>
using namespace std;

template<class T>
class AlberiNari {
public:
	typedef int Nodo;
	typedef struct _nodo {
		T value = -1;
		vector<Nodo> figli;
	} Cella;
	AlberiNari();
	AlberiNari(int);
	~AlberiNari();
	void creaAlbero();
	bool alberovuoto();
	Nodo radice();
	Nodo padre(Nodo);
	Nodo numeroFiglio(Nodo);
	bool foglia(Nodo);
	Nodo primoFiglio(Nodo);
	Nodo ultimoFratello(Nodo);
	Nodo succFratello(Nodo);
	T leggiValoreNodo(Nodo);
	void scriviValoreNodo(T, Nodo);

	void insRadice(T);
	void insFiglio(Nodo, T);
	void stampaAlbero();
	Nodo operator =(Nodo);
	int contaFoglie();
	int contaNodi(int livello);
private:
	void stampaSottoAlbero(Nodo);
	void erase(Nodo);
	int contaFoglie(Nodo);
	int contaNodi(int livelloTarget, int livelloAttuale, Nodo);

	Cella *spazio;
	int MAXLUNG = 10;
	int nNodi;
};

template<class T> AlberiNari<T>::AlberiNari() {
	creaAlbero();
}

template<class T> AlberiNari<T>::AlberiNari(int n) {
	MAXLUNG = n;
	creaAlbero();
}

template<class T> AlberiNari<T>::~AlberiNari() {
	delete[] spazio;
}

template<class T> void AlberiNari<T>::creaAlbero() {
	spazio = new Cella[MAXLUNG];
	nNodi = 0;
}

template<class T> bool AlberiNari<T>::alberovuoto() {
	return (nNodi == 0);
}

template<class T> typename AlberiNari<T>::Nodo AlberiNari<T>::radice() {
	if (!alberovuoto())
		return 0;
	else {
		cout << "Albero Vuoto";
		return -1;
	}
}

template<class T> typename AlberiNari<T>::Nodo AlberiNari<T>::padre(Nodo t) {
	Nodo temp;

	if (!alberovuoto() && t != radice()) {

		for (int i = 0; i < nNodi; i++) {
			for (unsigned int j = 0; j < spazio[i].figli.size(); j++) {
				if (spazio[i].figli[j] == t)
					return i;
			}
		}
	}
	cout << "Padre di ";
	cout << t;
	cout << " non trovato";
	return -1;
}

template<class T> typename AlberiNari<T>::Nodo AlberiNari<T>::numeroFiglio(
		Nodo t) {
	Nodo temp;

	if (!alberovuoto() && t != radice()) {

		for (int i = 0; i < nNodi; i++) {
			for (int j = 0; j < spazio[i]->figli.size(); j++) {
				spazio[i]->figli[j] == t;
				return j;
			}
		}
	}
	cout << "Padre di ";
	cout << t;
	cout << " non trovato";
	return -1;
}

template<class T> bool AlberiNari<T>::foglia(Nodo t) {
	return (spazio[t].figli.size() == 0);
}

template<class T> typename AlberiNari<T>::Nodo AlberiNari<T>::primoFiglio(
		Nodo t) {
	return spazio[t].figli[0];
}
template<class T> typename AlberiNari<T>::Nodo AlberiNari<T>::ultimoFratello(
		Nodo t) {
	return spazio[t]->figli[spazio[t]->figli.size() - 1];
}

template<class T> typename AlberiNari<T>::Nodo AlberiNari<T>::succFratello(
		Nodo t) {
	int i = padre(t);
	int j = numeroFiglio(t);
	if (spazio[t]->figli.size() - 1 < j) {
		return spazio[t]->figli[j + 1];
	} else {
		cout << "Non è stato possibile trovare il successivo di  ";
		cout << t;
		return -1;
	}
}

template<class T> T AlberiNari<T>::leggiValoreNodo(Nodo t) {
	return spazio[t]->value;
}

template<class T> void AlberiNari<T>::scriviValoreNodo(T elemento, Nodo t) {
	spazio[t].value = elemento;
}

template<class T> void AlberiNari<T>::insRadice(T elemento) {
	if (alberovuoto()) {
		spazio[nNodi].value = elemento;
		nNodi++;
	}
}

template<class T> void AlberiNari<T>::insFiglio(Nodo t, T elemento) {
	int size = spazio[t].figli.size();
	if (size == 0) {
		spazio[t].figli.resize(1);

		spazio[t].figli[0] = nNodi;
	} else {
		spazio[t].figli.resize(size + 1);
		spazio[t].figli[size] = nNodi;
	}
	spazio[nNodi].value = elemento;
	nNodi++;
}

template<class T> void AlberiNari<T>::stampaAlbero() {
	stampaSottoAlbero(radice());
}

template<class T> void AlberiNari<T>::stampaSottoAlbero(Nodo t) {
	int size = spazio[t].figli.size();
	cout << "[ ";
	cout << spazio[t].value;
	for (int i = 0; i < size; i++) {
		cout << " ,";
		stampaSottoAlbero(spazio[t].figli[i]);
	}

	cout << " ]";
}

template<class T>
std::ostream& operator<<(std::ostream &out, AlberiNari<T> t) {
	t.stampaAlbero();
	return out;
}

template<class T> int AlberiNari<T>::contaFoglie() {
	int risultato = 0;
	if (!alberovuoto()) {
		risultato = contaFoglie(radice());
	}
	return risultato;
}

template<class T> int AlberiNari<T>::contaFoglie(Nodo t) {
	int risultato = 0;
	if (!foglia(t)) {
		for (int unsigned i = 0; i < spazio[t].figli.size(); i++) {
			risultato = risultato + contaFoglie(spazio[t].figli[i]);
		}

	} else
		return +1;
	return risultato;
}

template<class T> int AlberiNari<T>::contaNodi(int livello) {
	int risultato;
	if (!alberovuoto()) {
		risultato = contaNodi(livello, 0, radice());
	}
	return risultato;
}

template<class T> int AlberiNari<T>::contaNodi(int livelloTarget, int livello,
		Nodo t) {
	int risultato = 0;;
	if (foglia(t)) {
		if (livelloTarget > livello) {
			return 0;
		} else if (livelloTarget == livello) {
			return 1;
		}

	} else {
		if (livello < livelloTarget - 1) {
			for (unsigned int i = 0; i < spazio[t].figli.size(); i++) {
				risultato = risultato + contaNodi(livelloTarget,livello + 1,
						spazio[t].figli[i]);
			}
		} else if (livello == livelloTarget - 1) {
			return spazio[t].figli.size();
		}
	}

return risultato;
}

#endif /* ALBERINARI_H_ */
