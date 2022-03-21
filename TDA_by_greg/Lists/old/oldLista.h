
#ifndef LISTA_H_
#define LISTA_H_

// Realization of a list with finished space
template <typename T>
class List
{
    const int MAX_LENGTH = 10;
    const NULL_VALUE = -1;
    using P = int;

private:
    int first;
    int length = 0;
    T nodes[MAX_LENGTH]; // It can be managed as finished dimension or as dynamic dimension

public:
    List(); // Default constructor - Equal to create operator
    List(int numElem);

    List<T> &writeValue(P pos, T elem);
    List<T> &insert(P pos, T elem);
    List<T> &deleteElem(P pos);

    int getLength();

    T readValue(P pos);
    bool isEmpty();
    bool isLastValue(P pos);
    P firstNodeList();
    P nextValue(P pos);
    P prevValue(P pos);
};

#endif