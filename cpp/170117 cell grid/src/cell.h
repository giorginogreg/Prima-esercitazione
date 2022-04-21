/*
 * cell.h
 *
 *  Created on: 6 set 2020
 *      Author: utente
 */

#ifndef CELL_H_
#define CELL_H_

class cell {
public:
	cell();
	virtual ~cell();

	int x;
	int y;

	bool operator ==(cell );
};

bool cell::operator ==(cell t){
	return ( x == t.x && y == t.y);
}



cell::cell(){
	x = 0;
	y = 0;
}
cell::~cell()
{

}

#endif /* CELL_H_ */
