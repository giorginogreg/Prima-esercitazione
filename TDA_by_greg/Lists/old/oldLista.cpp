#include "Nodo.h"
#include "Lista.h"

#include <stdio.h>  /* printf, scanf, NULL */
#include <stdlib.h> /* malloc, free, rand */
template <typename T>
List<T>::List()
{
    length = 0;
    nodi = NULL;
}

template <typename T>
List<T>::List(int numElem)
{
    if (numElem > 0 && numElem <= MAX_LENGTH)
    {
        //nodi = (Nodo<T> *)malloc(sizeof(Nodo<T>) * numElem);
        int i = 0;
        do
        {
            writeValue(i, NULL_VALUE);
            i += 1;
        } while (i <= MAX_LENGTH);
        numNodi = numElem;
    }
    else
        std::cout("The size of the list you want to create is not valid.");
}

template <typename T>
int getLength()
{
    return List<T>::length;
}

template <typename T>
List<T> &List<T>::writeValue(int pos, T elem)
{
    if (pos <= MAX_LENGTH)
    {
        /*         if (pos <= getLength())
            nodes[pos] = elem;
        else */
        nodes[pos] = elem;
    }
    else
        std::cout("Error: can't insert some element in a position that is not valid.");
    return this;
}

template <typename T>
List<T> &List<T>::insert(int pos, T elem)
{
    if (getLength() + 1 <= MAX_LENGTH)
    {
        int i = pos;
        T temp_elem = readValue(i);
        writeValue(i, elem);
        do
        {
            i += 1;
            swapValues(readValue(i), temp_elem);
        } while (i <= length + 1);
    }
    // if length + 1 > MAX_LENGTH some value will be removed!
    return *this;
}

template <typename T>
List<T> &List<T>::deleteElem(P pos)
{
    if (0 < pos && pos <= getLength())
    {
        int i = pos;
        while (i < length && readValue(i) != NULL_VALUE)
        {
            writeValue(i, readValue(i + 1));
            i += 1;
        }
        writeValue(i, NULL_VALUE);
    }
    return *this;
}

template <typename T>
T List<T>::readValue(P pos)
{
    if (0 < pos && pos <= getLength)
    {
        return List::nodes[pos];
    }
    else
        throw Error();
}

template <typename T>
bool List<T>::isEmpty()
{
    return List<T>::isLastValue(List<T>::firstNodeList());
}

template <typename T>
bool List<T>::isLastValue(P pos)
{
    return pos == length;
}

template <typename T>
List<T>::P List<T>::firstNodeList()
{
    return 0;
}
template <typename T>
List<T>::P List<T>::nextValue(P pos)
{
    if (pos < length)
    {
        return pos + 1;
    }
}

template <typename T>
List<T>::P List<T>::prevValue(P pos)
{
    if (pos > 0)
    {
        return pos - 1;
    }
}

template <typename T>
void swapValues(T elem1, T elem2)
{
    int temp;
    temp = elem1;
    elem1 = elem2;
    elem2 = temp;
}

//List &List::operator=(const &List l);
/* 
List::addNodo(Nodo n)
{
    this->nodi[] = n;
}

List::isEmpty()
{
    return this->numNodi == 0;
}

;
 */