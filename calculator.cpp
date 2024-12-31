#include "calculator.h"

template <>
void Calculator<int64_t(int64_t, int64_t)>::addDigit(uint8_t digit)
{
    if ((INT64_MAX - digit) / 10 <= this->current_result) {
        error = true;
        return;
    }
    this->current_result = this->current_result*10 + digit*(this->current_result >= 0? 1:-1);
    std::cout << this->current_result << " " << this->saved_result <<std::endl;
}

template <>
void Calculator<int64_t(int64_t, int64_t)>::useOperator() {
    try {
        current_result = (*op)(current_result, saved_result);
    } catch (std::overflow_error) {
        error = true;
    }
    saved_result = 0;
}

template <>
void Calculator<int64_t(int64_t, int64_t)>::clearError()
{
    error = false;
    current_result = 0;
    saved_result = 0;
}

template <>
void Calculator<int64_t(int64_t, int64_t)>::setOperator(int64_t func(int64_t, int64_t)) {
    this->op = func;
    saved_result = current_result;
    current_result = 0;
}

template <>
std::string Calculator<int64_t(int64_t, int64_t)>::getResult() {
    if (error) {
        return "ERR";
    }
    return std::to_string(this->current_result);
}
