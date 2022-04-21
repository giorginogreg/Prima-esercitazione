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

#include "balancedtree.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
using namespace std;

int main() {


	unsigned int temp = 0;
	balanced_tree<int> tree(100);
	srand(time(0));
	while (temp >= 10) {
		temp = rand();
	}
	int j;
	tree.autoInserimentoFiglioBilanciato(rand());
	for (unsigned int i = 0; i < 50; i++) {
		j = rand() % 30;
		tree.autoInserimentoFiglioBilanciato(j);

	}
	tree.stampaAlbero();

	cout << endl;
	cout << tree.is_height_balanced() << endl;
	cout << tree.contaNodi(tree.getRoot()) << endl;
	cout << tree.complete_nodes() << endl;





}
