//
// Created by Greg on 20/03/22.
//

#include <iostream>
#include "OutOfBoundException.h"

OutOfBoundException::OutOfBoundException(std::string msg) {
    std::cout << msg << std::endl;
}
