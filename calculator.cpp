#include "calculator.h"

template <>
void Calculator<int64_t(int64_t, int64_t)>::addDigit(uint8_t digit)
{
    this->current_result = this->current_result*10 + digit*(this->current_result >= 0? 1:-1);
    std::cout << this->current_result << " " << this->saved_result <<std::endl;
}

template <>
void Calculator<int64_t(int64_t, int64_t)>::useOperator() {
    current_result = (*op)(current_result, saved_result);
    saved_result = 0;
}

template <>
void Calculator<int64_t(int64_t, int64_t)>::setOperator(int64_t func(int64_t, int64_t)) {
    this->op = func;
    saved_result = current_result;
    current_result = 0;
}

template <>
int64_t Calculator<int64_t(int64_t, int64_t)>::getResult() {
    return this->current_result;
}
