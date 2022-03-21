//
// Created by Greg on 20/03/22.
//

#ifndef ALGORITHM_DATA_STRUCTURES_OUTOFBOUNDEXCEPTION_H
#define ALGORITHM_DATA_STRUCTURES_OUTOFBOUNDEXCEPTION_H


#include <string>

class OutOfBoundException: public std::exception{
public:
    OutOfBoundException(std::string);
};


#endif //ALGORITHM_DATA_STRUCTURES_OUTOFBOUNDEXCEPTION_H
