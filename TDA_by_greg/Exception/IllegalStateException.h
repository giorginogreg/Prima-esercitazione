//
// Created by Greg on 20/03/22.
//

#ifndef ALGORITHM_DATA_STRUCTURES_ILLEGALSTATEEXCEPTION_H
#define ALGORITHM_DATA_STRUCTURES_ILLEGALSTATEEXCEPTION_H

#include <string>
#include <exception>

class IllegalStateException: public std::exception{
public:
    IllegalStateException(std::string);
};


#endif //ALGORITHM_DATA_STRUCTURES_ILLEGALSTATEEXCEPTION_H
