/*
 * Dequeue.h
 *
 *  Created on: 5 ago 2020
 *      Author: utente
 */

#ifndef DEQUEUE_H_
#define DEQUEUE_H_

template<class T>
class Dequeue {
public:
	Dequeue(int);
	~Dequeue();
	void creaDequeue();
	void push_back(T);
	void push_front(T);
	bool codaVuota();
	T pop_back();
	T pop_front();
	void stampaCoda();
private:
	T *elementi;
	int testa, coda, maxlung;
};

template<class T> Dequeue<T>::Dequeue(int a) {
	maxlung = a;
	creaDequeue();

}

template<class T> Dequeue<T>::~Dequeue() {
	delete[] elementi;

}

template<class T> void Dequeue<T>::creaDequeue() {
	elementi = new T[maxlung];
	testa = 0;
	coda = 0;
}

template<class T> bool Dequeue<T>::codaVuota() {
	if (coda == 0)
		return true;
	else
		return false;
}

template<class T> void Dequeue<T>::push_front(T a) {
	if (coda < maxlung) {
		testa = (testa-1)%maxlung;
		elementi[testa]=a;
		coda++;
	} else
		cout << "Coda piena" << endl;
}

template<class T> void Dequeue<T>::push_back(T a) {
	if (coda < maxlung) {
		elementi[(testa + coda) % maxlung] = a;
		coda++;
	} else
		cout << "Coda piena" << endl;
}

template<class T> T Dequeue<T>::pop_front() {
	T risultato;
	if (!codaVuota()) {
		risultato = elementi[testa];
		testa = (testa + 1) % maxlung;
		coda--;
	}
	return risultato;
}

template<class T> T Dequeue<T>::pop_back() {
	T risultato;
	if (!codaVuota()) {
		coda--;
	}

}

template<class T> void Dequeue<T>::stampaCoda() {
	for (int i = testa, j = 0; j < coda; (i++) % maxlung, j++) {
		cout << elementi[i] << " - ";
	}

	cout << endl;
}

#endif /* DEQUEUE_H_ */
