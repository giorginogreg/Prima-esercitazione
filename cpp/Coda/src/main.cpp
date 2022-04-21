//============================================================================
// Name        : Coda.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Coda.h"
#include "Dequeue.h"
using namespace std;

int main() {

	Dequeue<int> coda(5);
	cout << coda.codaVuota() << endl;
	cout << coda.pop_front() << endl;
	coda.push_back(5);
	coda.stampaCoda();
	coda.push_back(2);
	coda.stampaCoda();
	coda.push_back(3);
	coda.stampaCoda();
	coda.push_back(4);
	coda.stampaCoda();
	coda.push_front(5);
	coda.stampaCoda();
	coda.push_front(6);
	coda.stampaCoda();

	return 0;
}
