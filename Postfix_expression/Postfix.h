//
// Created by Greg on 23/03/22.
//

#ifndef ALGORITHM_DATA_STRUCTURES_POSTFIX_H
#define ALGORITHM_DATA_STRUCTURES_POSTFIX_H

#include "../TDA_by_greg/Lists/pointer_implementation/include/StackList.h"
#include <string>
#include <regex>

using namespace std;

template<class T, int S>
class Postfix: public StackList<T, S> {
public:
    void push(T) override;
};

enum operation {
    opPlus,
    opMinus,
    opDivide,
    opMultiply,
    opElevate
};


bool isSymbol(const string& elem) {
    regex op(R"(\+|\*|-|\/|:)");

    return regex_match(elem, op);
}

operation getEnum(const string& op) {
    if(op == "+") return opPlus;
    if(op == "-") return opMinus;
    if(op == ":" || op == "/") return opDivide;
    if(op == "*") return opMultiply;
    if(op == "**") return opElevate;
    return opElevate;
}

string execute_operation(const string& operand, const string& first_operand, const string& second_operand) {
    int first_op_int = stoi(first_operand);
    int second_op_int = stoi(second_operand);
    int result;
    switch (getEnum(operand)) {
        case opPlus:
            result = abs(first_op_int + second_op_int);
            break;
        case opMinus:
            result = abs(first_op_int - second_op_int);
            break;
        case opMultiply:
            result = abs(first_op_int * second_op_int);
            break;
        case opElevate:
            result = first_op_int;
            for (int i = 0; i < second_op_int; ++i) {
                result *= first_op_int;
            }
            break;
        case opDivide:
            result = first_op_int / second_op_int;
            break;
    }
    return to_string(result);

}

template<class T, int S>
void Postfix<T, S>::push(T elem) {
    StackList<T, S>::push(elem);

    if(isSymbol(elem)) {
        string operand = this->pop();
        string first_operand = this->pop();
        string second_operand = this->pop();
        string result = execute_operation(operand, first_operand, second_operand);
        this->push(result);
    }

}
#endif //ALGORITHM_DATA_STRUCTURES_POSTFIX_H
