#include <string>
#include "../include/VectorList.h"
#include "../include/OutOfBoundException.h"

template<typename T, int S>
VectorList<T, S>::VectorList() {
    _dimension = S;
    _list = new T[S];
    initialize();
}

template<class T, int S>
VectorList<T, S>::VectorList(const VectorList &vectorListToCopy) {
    _dimension = vectorListToCopy._dimension;
    _list = new T[S];
    for (int i = 0; i < getDimension(); i++) {
        this->_list[i] = vectorListToCopy[i];
    }
    initialize();
    return &this;
}

template<typename T, int S>
VectorList<T, S>::~VectorList() {
    delete[] _list;
}

template<class T, int S>
void VectorList<T, S>::initialize() {
    _elements_inside = 0;
}

template<class T, int S>
void VectorList<T, S>::writeValueAt(int p, T t) {
    if (outOfBound(p))
        throw OutOfBoundException("Error: out of boundary indexes");
    _list[p] = t;
}

template<class T, int S>
void VectorList<T, S>::insertNodeAfter(int position, T elementToAdd) {
    change_list_size(getDimension() + 1);
    shiftElementsToRight(position);
    writeValueAt(position, elementToAdd);
    _elements_inside++;
}

template<typename T, int S>
void VectorList<T, S>::deleteNodeAt(int p) {
    shiftElementsToLeft(p);
    change_list_size(getDimension() - 1);
    _elements_inside--;
}

template<typename T, int S>
T VectorList<T, S>::readValueAt(int p) {
    return _list[p];
}

template<typename T, int S>
bool VectorList<T, S>::isEmpty() {
    return _elements_inside == 0;
}

template<typename T, int S>
bool VectorList<T, S>::isLastValue(int p) {
    return p == _dimension;
}

template<typename T, int S>
int VectorList<T, S>::firstNodeList() {
    return 0;
}

template<typename T, int S>
int VectorList<T, S>::nextPosition(int p) {
    return p + 1;
}

template<typename T, int S>
int VectorList<T, S>::previousPosition(int p) {
    return p - 1;
}

template<class T, int S>
void VectorList<T, S>::change_list_size(const int new_dimension) {
    if (new_dimension < 0)
        throw OutOfBoundException("La dimensione deve essere maggiore di 0");
    auto *temp = new VectorList<T, 0>;
    T* list = new T[std::max(new_dimension - 1, 1)];
    temp->setDimension(new_dimension);
    temp->setList(list);

    int number = (getDimension() < new_dimension) ? getDimension() : new_dimension;
    for (int i = 0; i < number; i++)
        temp->writeValueAt(i,readValueAt(i));
    delete[] getList();
    _dimension = new_dimension;
    setList(temp->getList());
}

// ------ Getters and setters ------

template<class T, int S>
int VectorList<T, S>::getDimension() const {
    return _dimension;
}

template<class T, int S>
void VectorList<T, S>::setDimension(int dimension) {
    _dimension = dimension; // Human Readable format
}

template<class T, int S>
int VectorList<T, S>::getElementsInside() const {
    return _elements_inside;
}

template<class T, int S>
void VectorList<T, S>::setElementsInside(int elementsInside) {
    _elements_inside = elementsInside;
}

template<class T, int S>
T *VectorList<T, S>::getList() const {
    return _list;
}

template<class T, int S>
void VectorList<T, S>::setList(T *list) {
    _list = list;
}

template<class T, int S>
bool VectorList<T, S>::outOfBound(int desired_position) {
    return desired_position < 0 || desired_position > _dimension;
}

template<class T, int S>
void VectorList<T, S>::shiftElementsToRight(const int starting_position) {

    if (outOfBound(starting_position))
        throw OutOfBoundException("Error: out of boundary indexes");

    int nextPos = starting_position; // goes from right to left
    while (!isLastValue(nextPosition(nextPos)))
        nextPos = nextPosition(nextPos);

    while (firstNodeList() > nextPos || nextPos > starting_position) {
        writeValueAt(nextPos, readValueAt(previousPosition(nextPos)));
        nextPos = previousPosition(nextPos);
    }

}

template<class T, int S>
void VectorList<T, S>::shiftElementsToLeft(const int starting_position) {
    if (outOfBound(starting_position))
        throw OutOfBoundException("Error: out of boundary indexes");

    int nextPos = starting_position;

    while (!isLastValue(nextPos)) {
        writeValueAt(nextPos, readValueAt(nextPosition(nextPos)));
        nextPos = nextPosition(nextPos);
    }
}
