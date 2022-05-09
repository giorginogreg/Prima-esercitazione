//
// Created by Greg on 22/03/22.
//


template<class T, int S>
void StackList<T, S>::push(T elem) {
    auto last_node = getLastNode();
    _l.insertNodeAfter(last_node, elem);
}

template<class T, int S>
TDA_Greg::Node<T>* StackList<T, S>::getLastNode() {
    auto first_node = _l.firstNodeList();
    while(!_l.isLastPosition(first_node))
        first_node = first_node->getNextPos();
    return first_node;
}

template<class T, int S>
T StackList<T, S>::pop() {
    auto last_node = getLastNode();
    T temp_value = last_node->getElem();
    _l.deleteNodeAt(last_node);
    return temp_value;
}

template<class T, int S>
bool StackList<T, S>::empty() {
    return _l.isEmpty();
}

template<class T, int S>
T StackList<T, S>::top() {
    return getLastNode()->getElem();
}
