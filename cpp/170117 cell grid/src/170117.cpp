//============================================================================
// Name        : 170117.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "grid.h"
#include "cell.h"
#include <iostream>
#include<time.h>
using namespace std;

int main() {

	grid gr;
	cell cella;

	unsigned int temp = 0;
	srand(time(0));
	while (temp >= 25) {
		temp = rand();
	}

	for (unsigned int i = 0; i < 25; i++) {

		cella.x = rand() % 25;
		cella.y = rand() % 25;
		gr.insert(cella);
	}

	gr.stampaGriglia();

	cout << endl;

	cella.x = 4;
	cella.y = 1;
	gr.insert(cella);

	gr.stampaGriglia();
	cout << endl;

	cella.x = 5;
	cella.y = 1;
	gr.insert(cella);

	gr.stampaGriglia();
	cout << endl;

	cella.x = 3;
	cella.y = 1;
	gr.insert(cella);

	gr.stampaGriglia();
	cout << endl;
	cella.x = 4;
	cella.y = 2;
	gr.insert(cella);


	gr.stampaGriglia();
	cout << endl;
	cella.x = 4;
	cella.y = 0;
	gr.insert(cella);

	gr.stampaGriglia();
	cout << endl;

	gr.removeSurrounded();
	cout << endl;

	cella.x = 4;
	cella.y = 0;
	gr.remove(cella);

	gr.stampaGriglia();


}
