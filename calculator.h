#ifndef __CALC__
#define __CALC__
#include <QWidget>
#include <QPushButton>
#include <QPlainTextEdit>
#include <iostream>

template <typename Operator>
class Calculator {
    private:
        int current_result = 0;
        int saved_result = 0;
        Operator *op = [](int b, int c){return b;};
    public:
        Calculator() {};
        void addDigit(uint8_t digit);
        void useOperator();
        void setOperator(const Operator* func);
        int getResult();
};

#endif
