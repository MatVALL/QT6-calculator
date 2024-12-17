#include "calculator.h"

template <>
void Calculator<int(int, int)>::addDigit(uint8_t digit)
{
    this->current_result = this->current_result*10 + digit*(this->current_result >= 0? 1:-1);
    std::cout << this->current_result << " " << this->saved_result <<std::endl;
}

template <>
void Calculator<int(int, int)>::useOperator() {
    current_result = (*op)(current_result, saved_result);
    saved_result = 0;
}

template <>
void Calculator<int(int, int)>::setOperator(int func(int, int)) {
    this->op = func;
    saved_result = current_result;
    current_result = 0;
}

template <>
int Calculator<int(int, int)>::getResult() {
    return this->current_result;
}
