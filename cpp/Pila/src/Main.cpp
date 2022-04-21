//============================================================================
// Name        : Pila.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#include "Pila.h"
#include "MultipleStack.h"

int main() {
	MultipleStack<int> mp(3);
	int* elemento;
	int elemento1;
	elemento1 = 5;
	elemento = &elemento1;

	mp.Push(*elemento, 1);
	elemento1 = 3;

	mp.Push(*elemento, 2);
	mp.stampaStacks();
	return 0;
}
