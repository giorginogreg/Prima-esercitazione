/*
 * Nodo.h
 *
 *  Created on: 27 ago 2020
 *      Author: utente
 */

#ifndef NODO_H_
#define NODO_H_

template <class T>
class Nodo {
public:
	Nodo();
	~Nodo();
	void scriviValoreNodo(T);
	T leggiValoreNodo();


private :
		T value;
		Nodo *figliodx = nullptr;
		Nodo *figliosx = nullptr;

};


template<class T> void Nodo<T>::scriviValoreNodo(T elemento) {
	value = elemento;
}
template<class T> T Nodo<T>::leggiValoreNodo() {
	return value;
}




#endif /* NODO_H_ */
