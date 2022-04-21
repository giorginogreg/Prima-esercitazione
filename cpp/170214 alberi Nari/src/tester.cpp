/***************************************************************************
 *   Copyright (C) 2010 by Nicola Di Mauro                                 *
 *   ndm@di.uniba.it                                                       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "AlberiNari.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
using namespace std;

int main() {

	AlberiNari<int> tree(100);
	unsigned int temp = 0;
	srand(time(0));
	while (temp >= 10) {
		temp = rand();
	}
	int j;
	tree.insRadice(rand());
	for (unsigned int i = 0; i < 100; i++) {
		j= rand() %30;
		if ( rand() % 2 == 0)
			tree.insFiglio(j, rand());

	}
	tree.stampaAlbero();

	cout << endl;
	cout << tree.contaFoglie() << endl;
	cout << tree.contaNodi(2) << endl;

//	AlberiNari<int> tree;
//	cout << tree.alberovuoto() << endl;
//	cout << tree.radice() << endl;
//	cout << tree.padre(3) << endl;
//	tree.insRadice(2);
//	tree.stampaAlbero();
//	cout <<  endl;
//	tree.insRadice(3);
//	tree.stampaAlbero();
//	cout <<  endl;
//
//	tree.insFiglio((tree.radice()), 4);
//	tree.stampaAlbero();
//	cout <<  endl;
//
//	tree.insFiglio((tree.primoFiglio(tree.radice())), 5);
//	tree.stampaAlbero();
//	cout <<  endl;
//
//
//	tree.insFiglio(tree.primoFiglio((tree.primoFiglio(tree.radice()))), 6);
//
//	tree.stampaAlbero();

}
