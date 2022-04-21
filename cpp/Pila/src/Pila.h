/*
 * Pila.h
 *
 *  Created on: 1 ago 2020
 *      Author: utente
 */

#ifndef PILA_H_
#define PILA_H_
#include <iostream>


template<class T>
class Pila {
public:
	typedef T tipoelem;
	Pila(); //costruttori
	~Pila(); // distruttore
	void creaPila(); //operatori
	bool pilaVuota() const;
	tipoelem leggiPila() const;
	void fuoriPila();
	void inPila(tipoelem);
	void stampaPila();
	tipoelem Pop();
private:
	tipoelem *elementi;
	int testa;
};


using namespace std;
const int MAXLUNG = 5;

template<class T> Pila<T>::Pila() {
	elementi = new tipoelem[MAXLUNG];
	testa = 0;
}

template<class T> Pila<T>::~Pila() {
	delete elementi;
}

template<class T> bool Pila<T>::pilaVuota() const {
	if (testa==0)
		return true;
	else
		return false;
}

template<class T> T Pila<T>::leggiPila() const {
	return elementi[testa - 1];

}

template<class T> void Pila<T>::inPila(T elemento) {
	if (testa == MAXLUNG + 1) {
		cout << "LUNGHEZZA MASSIMA RAGGIUNTA" << endl;
	} else {
		this->elementi[testa] = elemento;
		testa++;
	}
}

template<class T> void Pila<T>::fuoriPila() {
	 if (!pilaVuota()) testa-=1;
	 else{ cout<<"nessun elemento nella pila"<<endl;
}}

template<class T> T Pila<T>::Pop(){
	T elemento = leggiPila();
	fuoriPila();
	return elemento;
}

template<class T> void Pila<T>::stampaPila() {
	for (int i = testa - 1; i >= 0; i--) {
		cout << elementi[i] << endl;
	}

}
#endif /* PILA_H_ */
