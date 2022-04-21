/*
 * balancedtree.h
 *
 *  Created on: 5 set 2020
 *      Author: utente
 */

#ifndef BALANCEDTREE_H_
#define BALANCEDTREE_H_

#include "albBinari.h"
#include <cmath>

template<class T>
class balanced_tree: public albBinari<T> {
	static const int NIL = -1;

	typedef typename albBinari<T>::Nodo Nodo;

public:
	typedef typename albBinari<T>::Cella Cella;
	balanced_tree();
	balanced_tree(int);
	virtual ~balanced_tree();
	void creaAlbero();
	bool is_height_balanced();
	/* Stabilisce se tutti i nodi non foglia dell’albero hanno esattamente due figli */
	bool complete_nodes();

	void autoInserimentoFiglioBilanciato(T);
	int contaNodi(Nodo);

};

template<class T> void balanced_tree<T>::creaAlbero() {
	albBinari<T>::spazio = new Cella[albBinari<T>::MAXLUNG];
	albBinari<T>::nNodi = 0;
}

template<class T> balanced_tree<T>::balanced_tree() {
	creaAlbero();
}

template<class T> balanced_tree<T>::balanced_tree(int n) {
	albBinari<T>::MAXLUNG = n;
	creaAlbero();
}

template<class T> balanced_tree<T>::~balanced_tree() {
	albBinari<T>::~albBinari();
}

template<class T> void balanced_tree<T>::autoInserimentoFiglioBilanciato(
		T value) {
	Nodo t;
	if (albBinari<T>::isEmpty()) {
		albBinari<T>::insRoot(value);
		return;
	} else {
		if (is_height_balanced()) {
			if (albBinari<T>::isFiglioSxEmpty(albBinari<T>::getRoot())) {
				t = albBinari<T>::getRoot();
			} else {
				t = albBinari<T>::getFiglioSx(albBinari<T>::getRoot());
			}
		} else {
			if (albBinari<T>::isFiglioDxEmpty(albBinari<T>::getRoot()))
				t = albBinari<T>::getRoot();
			else
				t = albBinari<T>::getFiglioDx(albBinari<T>::getRoot());
		}
		while (true) {
			if (albBinari<T>::isLeaf(t)) {
				albBinari<T>::insFiglioSx(t, value);
				return;
			} else {
				if (!albBinari<T>::isFiglioSxEmpty(t)
						&& !albBinari<T>::isFiglioDxEmpty(t)) {
					t = albBinari<T>::getFiglioSx(t);
				} else if (albBinari<T>::isFiglioSxEmpty(t))
					albBinari<T>::insFiglioSx(t, value);
				else if (albBinari<T>::isFiglioDxEmpty(t))
					albBinari<T>::insFiglioDx(t, value);
			}
		}
	}
}

template<class T> bool balanced_tree<T>::is_height_balanced() {
	if (albBinari<T>::isEmpty()
			|| (albBinari<T>::isFiglioDxEmpty(albBinari<T>::getRoot())
					&& albBinari<T>::isFiglioSxEmpty(albBinari<T>::getRoot()))) {
		return true;
	} else {

		return (abs(
				contaNodi(albBinari<T>::getFiglioSx(albBinari<T>::getRoot()))
						- contaNodi(
								albBinari<T>::getFiglioDx(
										albBinari<T>::getRoot()))) < 2);
	}
}

template<class T> int balanced_tree<T>::contaNodi(Nodo t) {
	int risultato = 0;
	if ( t == -1)
		return 0;
	if (albBinari<T>::isLeaf(t)) {
		return 1;
	} else {
		if (!albBinari<T>::isFiglioSxEmpty(t))
			risultato = risultato + contaNodi(albBinari<T>::getFiglioSx(t));
		if (!albBinari<T>::isFiglioDxEmpty(t))
			risultato = risultato + contaNodi(albBinari<T>::getFiglioDx(t));
	}
	return risultato;
}

template<class T> bool balanced_tree<T>::complete_nodes() {
	for (int i = 0; i < albBinari<T>::nNodi; i++) {
		if (!albBinari<T>::isLeaf(i)) {
			if (albBinari<T>::isFiglioSxEmpty(i)
					|| albBinari<T>::isFiglioDxEmpty(i)) {
				return false;
			}
		}
	}
	return true;
}
#endif /* BALANCEDTREE_H_ */
