//
// Created by Greg on 20/03/22.
//

#include <iostream>
#include "IllegalStateException.h"

IllegalStateException::IllegalStateException(std::string msg) {
    std::cout << msg << std::endl;
}
