#ifndef __CALCBUTTON__
#define __CALCBUTTON__
#include <QWidget>
#include "calculator.h"

class CalcButton : public QPushButton {
    public:
        std::string operation = "?";
        CalcButton(Calculator<int64_t(int64_t, int64_t)>&, const QString &, QWidget *);
        virtual void on_click() = 0;
    protected:
        Calculator<int64_t(int64_t,int64_t)> &calculator;
};

class DigitButton: public CalcButton {
    public:
        uint8_t digit;
        DigitButton(Calculator<int64_t(int64_t, int64_t)>&, QWidget*, uint8_t digit);
        void on_click();
};

class PlusButton: public CalcButton {
    public:
        PlusButton(Calculator<int64_t(int64_t, int64_t)>&, QWidget*);
        void on_click();
};

class EqualButton: public CalcButton {
    public:
        EqualButton(Calculator<int64_t(int64_t, int64_t)>&, QWidget*);
        void on_click();
};

class ClearButton: public CalcButton {
    public:
        ClearButton(Calculator<int64_t(int64_t, int64_t)>&, QWidget*);
        void on_click();
};

class MinusButton: public CalcButton {
    public:
        MinusButton(Calculator<int64_t(int64_t, int64_t)>&, QWidget*);
        void on_click();
};

#endif
