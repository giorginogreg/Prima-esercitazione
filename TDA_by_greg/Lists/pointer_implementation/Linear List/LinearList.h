#ifndef LINEARLIST_H
#define LINEARLIST_H

template <class ElemType, class PositionType> // Position type can be an integer (refering to a vector), a pointer to a node...
class LinearList
{

public:

    // Constructor
    void initialize(int max_elems_inside);

    // Destructor

    // Modifiers
    virtual void writeValueAt(PositionType, ElemType) = 0;
    virtual void insertNodeAfter(PositionType, ElemType) = 0;

    virtual void deleteNodeAt(PositionType) = 0;

    // Observers
    virtual ElemType readValueAt(PositionType) const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isLastPosition(PositionType) const = 0;

    virtual PositionType firstNodeList( ) const = 0;
    virtual PositionType nextPosition(PositionType) const = 0;
    virtual PositionType previousPosition(PositionType) const = 0;

    int getElementsInside() const { return _elems_inside; }
    void setElementsInside(int elementsInside) { _elems_inside = elementsInside; }

    int getMaxElementsInside() const { return _max_elems_inside; }

protected:
    int _elems_inside;
    int _max_elems_inside;
};

template<class T, class P>
void LinearList<T, P>::initialize(int max_elems_inside) {
    _max_elems_inside = max_elems_inside;
    _elems_inside = 0;
}

#endif