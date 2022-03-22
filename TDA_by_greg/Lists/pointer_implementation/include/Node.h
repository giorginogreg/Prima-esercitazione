#include "../../include/LinearList.h"
#ifndef NODE_GREG_H
#define NODE_GREG_H
namespace TDA_Greg
{
    template <typename T>
    class Node
    {
        friend class LinearList<T, Node*, 0>; // Node class is Linked List friend, so it can access private fields
    private:
        T _elem;
        Node<T> *_nextPos;
        Node<T> *_prevPos;
    public:
        void setElem(T elem) {
            _elem = elem;
        }

        void setNextPos(Node<T> *nextPos) {
            _nextPos = nextPos;
        }

        void setPrevPos(Node<T> *prevPos) {
            _prevPos = prevPos;
        }

        T getElem() const {
            return _elem;
        }

        Node<T> *getNextPos() const {
            return _nextPos;
        }

        Node<T> *getPrevPos() const {
            return _prevPos;
        }

    public:
        Node() {}

        Node(T elem) {
            _elem = elem;
        }
        //bool operator ==(Node &);
    };


    /*
        template<typename T>
     * bool Node<T>::operator==(Node &node_to_compare) {
        return node_to_compare == this;
    }*/
} // namespace Gregorio

#endif //NODE_GREG_H
