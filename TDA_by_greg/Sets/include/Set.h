//
// Created by Greg on 06/04/22.
//

#ifndef POINTERQUEUE_SET_H
#define POINTERQUEUE_SET_H

template<class T, class PositionType>
class Set {
public:

    virtual void create() = 0;
    virtual bool isEmpty() = 0;
    virtual bool belongsTo(T) = 0;
    virtual void insert(T) = 0;
    virtual void remove(T) = 0;
    virtual T find(T) = 0;
    virtual Set<T, PositionType>* union_op(Set<T, PositionType>* ) = 0;
    /*virtual Set<T, PositionType>* intersect(Set<T, PositionType>);
    virtual Set<T, PositionType>* difference(Set<T, PositionType>);
*/
    int getElemsInside() const {
        return elems_inside;
    }
protected:
    int elems_inside = 0;
    int max_elems_inside = 0;
};

#endif //POINTERQUEUE_SET_H
