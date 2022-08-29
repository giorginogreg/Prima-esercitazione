//
// Created by Greg on 26/04/22.
//

#ifndef TDAGREG_GRAPHNODE_H
#define TDAGREG_GRAPHNODE_H

#include "Node.h"
#include <string>

using TDA_Greg::Node;
using std::string;

template<class T>
class GraphNode : public Node<T> {
public:
    GraphNode() {}

    GraphNode(T t) {
        Node<T>::setElem(t);
    }

    int getId() const {
        return _id;
    }

    void setId(int id) {
        _id = id;
    }

    string getLabel() const {
        return Node<T>::getElem();
    }

    void setLabel(const T label) {
        Node<T>::setElem(label);
    }

    bool isSoftDeleted() const {
        return _softDeleted;
    }

    void setSoftDeleted(bool softDeleted) {
        _softDeleted = softDeleted;
    }

    int getLinks() const {
        return _links;
    }

    bool hasLinks() const {
        return getLinks() > 0;
    }

    void setLinks(int links) {
        _links = links;
    }

    bool operator==(const GraphNode &rhs) const {
        auto n = static_cast<Node<T>>(*this);
        auto n2 = static_cast<Node<T>>(rhs);
        return
            n == n2 &&
           _softDeleted == rhs._softDeleted &&
           _links == rhs._links &&
           _id == rhs._id;
    }

    bool operator!=(const GraphNode &rhs) const {
        return rhs != *this;
    }

    GraphNode<T>* getNextPos() const {
        return _nextPos;
    }

    GraphNode<T>* getPrevPos() const {
        return _prevPos;
    }


    void setNextPos(GraphNode<T>* nextPos) {
        _nextPos = nextPos;
    }

    void setPrevPos(GraphNode<T>* prevPos) {
        _prevPos = prevPos;
    }

private:
    bool _softDeleted = false;
    int _links = 0;
    int _id = -1;
    GraphNode<T>* _nextPos;
    GraphNode<T>* _prevPos;
};


#endif //TDAGREG_GRAPHNODE_H
