/*
 * MultipleStack.h
 *
 *  Created on: 4 ago 2020
 *      Author: utente
 */

#ifndef MULTIPLESTACK_H_
#define MULTIPLESTACK_H_
#include "Pila.h"

template<class T>
class MultipleStack {
public:
	MultipleStack(unsigned int);
	~MultipleStack();
	void Push(T&, unsigned int);
	T& Pop(unsigned int);
	void stampaStacks();
private:
	unsigned int nrStack;
	Pila<T> *multipleStack;
};

template<class T> MultipleStack<T>::MultipleStack(unsigned int a) {
	nrStack = a;
	multipleStack = new Pila<T> [a];
}

template<class T> MultipleStack<T>::~MultipleStack() {
	delete[] multipleStack;
}

template<class T> void MultipleStack<T>::Push(T& elemento, unsigned int index) {
	multipleStack[(index - 1)].inPila(elemento);
}

template<class T> T& MultipleStack<T>::Pop(unsigned int index) {
	T elemento = multipleStack[index].leggiPila();
	multipleStack[index - 1].fuoriPila();
	return elemento;
}

template<class T> void MultipleStack<T>::stampaStacks() {
	for (unsigned int i = 0; i < nrStack; i++) {
		multipleStack[i].stampaPila();
	}
}

#endif /* MULTIPLESTACK_H_ */
