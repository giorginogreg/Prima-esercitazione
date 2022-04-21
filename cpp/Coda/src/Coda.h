/*
 * Coda.h
 *
 *  Created on: 4 ago 2020
 *      Author: utente
 */

#ifndef CODA_H_
#define CODA_H_
#include <iostream>
using namespace std;

template<class tipoelem>
class Coda {
public:
	Coda(int);
	~Coda();
	void creaCoda();
	bool codaVuota();
	void fuoriCoda();
	tipoelem leggicoda();
	void inCoda(tipoelem);
	void inCodaNoNew(tipoelem);
	void inCodaNoOld(tipoelem);
	void stampaCoda();
private:
	tipoelem *elementi;
	int testa, lung, maxlung;
	bool presente(tipoelem);
	void rimuovi(tipoelem);
};

template<class T> bool Coda<T>::presente(T a) {
	for (int i = testa; i < lung; i++) {
		if (elementi[i] == a)
			return true;
	}
	return false;
}

template<class T> void Coda<T>::rimuovi(T a) {
	int i = testa;
	while (elementi[i] != a) {
		i++;
	}

	while ((i != maxlung) && (i != testa + lung )) {
		elementi[i] = elementi[i + 1];
		i++;
	}
	lung--;
}

template<class T> Coda<T>::Coda(int a) {
	maxlung = a;
	creaCoda();

}
template<class T> void Coda<T>::creaCoda() {
	elementi = new T[maxlung];
	testa = 0;
	lung = 0;
}
template<class T> Coda<T>::~Coda() {
	delete[] elementi;
}

template<class T> bool Coda<T>::codaVuota() {
	if (lung == 0)
		return true;
	else
		return false;
}

template<class T> void Coda<T>::fuoriCoda() {
	if (!codaVuota()) {
		testa = (testa + 1) % maxlung;
		lung--;
	} else {
		cout << "La coda è vuota, non posso eliminare elementi" << endl;
	}

}

template<class T> T Coda<T>::leggicoda() {
	if (!codaVuota())
		return elementi[testa];
}

//incoda con possibili duplicati
template<class T> void Coda<T>::inCoda(T a) {
	if (lung != maxlung) {
		elementi[(testa + lung) % maxlung] = a;
		lung++;
	}
}

/* ignora il nuovo */
template<class T> void Coda<T>::inCodaNoNew(T a) {
	if (lung != maxlung) {
		if (!presente(a)) {
			elementi[(testa + lung) % maxlung] = a;
			lung++;
		}
	}
}
/* dimentica il vecchio */
template<class T> void Coda<T>::inCodaNoOld(T a) {
	if (lung != maxlung) {
		if (presente(a)) {
			rimuovi(a);
			elementi[(testa + lung) % maxlung] = a;
			lung++;
		}
	}
}



template <class T> void Coda<T>::stampaCoda(){
	for (int i = testa, j=0; j < lung; (i++)%maxlung, j++) {
		cout << elementi[i] << " - ";
		}

	cout << endl;
}
#endif /* CODA_H_ */



