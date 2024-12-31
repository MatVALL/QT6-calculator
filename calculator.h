#ifndef __CALC__
#define __CALC__
#include <QWidget>
#include <QPushButton>
#include <QPlainTextEdit>
#include <iostream>

template <typename Operator>
class Calculator {
    private:
        bool error = false;
        int64_t current_result = 0;
        int64_t saved_result = 0;
        Operator *op = [](int64_t b, int64_t c)->int64_t{return b;};
    public:
        Calculator() {};
        void addDigit(uint8_t digit);
        void useOperator();
        void setOperator(const Operator* func);
        void clearError();
        std::string getResult();
};

#endif
