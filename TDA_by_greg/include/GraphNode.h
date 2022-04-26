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
private:
    string _label;
    bool _softDeleted = false;
    int _links = 0;
public:
    string getLabel() const {
        return _label;
    }

    void setLabel(const string& label) {
        _label = label;
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
};

#endif //TDAGREG_GRAPHNODE_H
