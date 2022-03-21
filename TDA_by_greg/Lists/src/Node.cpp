#include "../include/Node.h"

template <typename T>
TDA_Greg::Node<T>::Node(T elem)
{
    _elem = elem;
    _nextPos = nullptr; //TODO: secondo me da fare astratto con metodo da implementare
}