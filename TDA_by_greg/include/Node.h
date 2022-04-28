#ifndef NODE_GREG_H
#define NODE_GREG_H
namespace TDA_Greg
{
    template <typename T>
    class Node
    {
        //friend class LinearList<T, Node*, 0>; // Node class is Linked List friend, so it can access private fields
    private:
        T _elem;
        Node<T> *_nextPos;
        Node<T> *_prevPos;

    public:
        Node() { }

        Node(T elem) : _elem(elem) {}

        void setElem(T elem) {
            _elem = elem;
        }

        void setNextPos(Node<T> *nextPos) {
            _nextPos = nextPos;
        }

        void setPrevPos(Node<T> *prevPos) {
            _prevPos = prevPos;
        }

        T getElem() {
            return _elem;
        }

        Node<T> *getNextPos() const {
            return _nextPos;
        }

        Node<T> *getPrevPos() const {
            return _prevPos;
        }

        bool operator==(Node &node_to_compare) {
            return node_to_compare.getElem() == this->getElem();
        }
    };

} // namespace Gregorio

#endif //NODE_GREG_H
