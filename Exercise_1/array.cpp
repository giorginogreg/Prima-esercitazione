/*
*/

#include <vector>
#include <iterator> // for iterators

#include "NotOrderedException.cpp"

using namespace std;
using typeElem = int;

int checkOrderBetweenTwoElements(typeElem el1, typeElem el2);

// greaterThan(array a , int k) => int (num elementi maggiori di k in a)
int greaterThan(vector<typeElem> a, int k)
{
    int count = 0;
    vector<typeElem>::iterator it;

    for (it = a.begin(); it != a.end(); it++)
    {
        if (*it > k)
            count += 1;
    }
    return count;
}

// bool member(array A, int k);  restituisce true o false se k è presente in A
bool member(vector<typeElem> a, int k)
{
    bool found = false;
    vector<typeElem>::iterator it = a.begin();

    for (; it != a.end() && !found; it++)
    {
        if (*it == k)
            found = true;
    }
    return found;
}

// struct largest { int largest, int pos } largest(a): restituisce l'elemento più grande presente in a e la sua posizione
struct largestStruct
{
    int largest;
    int pos;
};

largestStruct largest(vector<typeElem> a)
{
    largestStruct l;
    int pos;
    vector<typeElem>::iterator it;

    l.largest = *a.begin();
    l.pos = 0;
    for (it = a.begin(), pos = 0; it != a.end(); pos++, it++)
    {
        if (*it > l.largest)
        {
            l.largest = *it;
            l.pos = pos;
        }
    }
    return l;
}

// remove(&array A, int k) : rimuove la prima occorrenza di k, shiftando a sinistra tutti gli elementi e inserendo uno 0 alla fine.
// per ogni elem di A
// Se k è presente in A, dall'elemento corrente fino alla fine sposto l'elemento successivo alla posizione attuale. all'ultimo inserisco uno 0

void remove(vector<typeElem> *arr, typeElem elem)
{
    vector<typeElem>::iterator previousIt;
    bool alreadyFound = false;
    for (vector<typeElem>::iterator it = (*arr).begin(); it != (*arr).end(); it++)
    {
        if (*it == elem && !alreadyFound)
        {
            alreadyFound = true;
            previousIt = it;
            while (it != (*arr).end())
            {
                *it = *(it + 1);
                it++;
            }
            *(it - 1) = 0;
            it = previousIt;
        }
    }
}

int ordering(vector<typeElem> *arr)
{
    // Restituisce 1 se gli elementi sono ordinati in modo crescente,
    // Restituisce 0 se gli elementi sono in ordine costante
    // Restituisce -1 se gli elementi sono ordinati in modo decrescente

    int order = 0;
    int previousOrder = 0;
    for (vector<typeElem>::iterator it = (*arr).begin(); next(it) != (*arr).end(); it++)
    {
        if (it == (*arr).begin())
        {
            previousOrder = checkOrderBetweenTwoElements(*it, *(it + 1));
        }
        else
        {
            order = checkOrderBetweenTwoElements(*it, *(it + 1));
            if (previousOrder != order)
                throw NotOrderedException();
            previousOrder = order;
        }
    }
    return order;
}
/* 
void reverse(vector<typeElem> &arr)
{
    vector<typeElem>::iterator i = arr.begin();
    vector<typeElem>::iterator j = arr.end() - 1;
    typeElem temp;

    for (; i != j || i > j; i++, j--)
    {
        temp = *i;
        *i = *j;
        *j = temp;
    }
} */

template <typename T>
void reverse(vector<T> &v)
{
    typename vector<T>::iterator left, right;
    T tmp;
    for (left = v.begin(), right = v.end() - 1; left != right || left > right;
         left++, right--)
    {
        tmp = *left;
        *left = *right;
        *right = tmp;
    }
}

int checkOrderBetweenTwoElements(typeElem el1, typeElem el2)
{
    return (el1 == el2) ? 0 : (el1 < el2 ? -1 : 1);
}