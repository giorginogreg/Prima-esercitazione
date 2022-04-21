/*
 * grid.h
 *
 *  Created on: 6 set 2020
 *      Author: utente
 */

#ifndef GRID_H_
#define GRID_H_

#include <list>
#include <iostream>
#include "cell.h"
using namespace std;

class grid {
public:

	grid();
	~grid();
// inserisce una cella viva nella griglia
	void insert(cell&);
// rimuove una cella nella griglia
	void remove(cell&);
// sposta a sinistra di una posizione la cella viva presente in posizione (x,y)
	void moveLeft(int x, int y);
// sposta a destra di una posizione la cella viva presente in posizione (x,y)
	void moveRight(int x, int y);
// sposta in alto di una posizione la cella viva presente in posizione (x,y)
	void moveUpper(int x, int y);
// sposta in basso di una posizione la cella viva presente in posizione (x,y)
	void moveDown(int x, int y);
// stabilisce se la cella viva presente in posizione (x,y) `e circondata,
// ovvero tutte le celle vicine alla cella data sono vive
	bool surrounded(int x, int y);
// rimuove dalla griglia tutte le celle circondate
	void removeSurrounded();
// ... //
	void stampaGriglia();
private:
	list<cell> cells;
// ... //
};

grid::grid(){
	cells.emplace(cells.begin());
}

grid::~grid(){
	delete &cells;
}

void grid::stampaGriglia() {
	for (cell x : cells) {
		cout << x.x << ' ' << x.y << endl;
	}
}

void grid::insert(cell &t) {
	bool check = false;
	for (cell x : cells) {
		if (x.x == t.x && x.y == t.y) {
			check = true;
			break;
		}
	}

	if (!check) {
		cells.push_back(t);
	}
}

void grid::remove(cell &t) {
	for (cell x : cells) {
		if (x.x == t.x && x.y == t.y) {
			cells.remove(x);
			break;
		}
	}
}

void grid::moveLeft(int x, int y) {
	bool free = true;
	for (cell c : cells) {
		if (c.x == x && c.y == y - 1) {
			free = false;
			break;
		}
	}
	if (free) {
		for (cell c : cells) {
			if (c.x == x && c.y == y) {
				c.y--;
				break;
			}
		}
	}
}

void grid::moveRight(int x, int y) {
	bool free = true;
	for (cell c : cells) {
		if (c.x == x && c.y == y + 1) {
			free = false;
			break;
		}
	}
	if (free) {
		for (cell c : cells) {
			if (c.x == x && c.y == y) {
				c.y++;
				break;
			}
		}
	}
}

void grid::moveUpper(int x, int y) {
	bool free = true;
	for (cell c : cells) {
		if (c.x == x - 1 && c.y == y) {
			free = false;
			break;
		}
	}
	if (free) {
		for (cell c : cells) {
			if (c.x == x && c.y == y) {
				c.x--;
				break;
			}
		}
	}
}

void grid::moveDown(int x, int y) {
	bool free = true;
	for (cell c : cells) {
		if (c.x == x + 1 && c.y == y) {
			free = false;
			break;
		}
	}
	if (free) {
		for (cell c : cells) {
			if (c.x == x && c.y == y) {
				c.x++;
				break;
			}
		}
	}
}

bool grid::surrounded(int x, int y) {
	bool check = false;
	bool checkSx = false, checkDx = false, checkUp = false, checkDw = false;
	for (cell c : cells) {
		if (c.x == x && c.y == y) {
			check = true;
		} else if (c.x == x && c.y == y - 1) {
			checkSx = true;
		} else if (c.x == x && c.y == y + 1) {
			checkDx = true;
		} else if (c.x == x - 1 && c.y == y) {
			checkUp = true;
		} else if (c.x == x + 1 && c.y == y) {
			checkDw = true;
		}
	}

	return (check && checkSx && checkDx && checkUp && checkDw);

}

void grid::removeSurrounded() {
	for (cell x : cells) {
		if (surrounded(x.x, x.y)) {
			remove(x);
		}
	}
}
#endif /* GRID_H_ */
