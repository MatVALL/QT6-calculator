#ifndef __CALCBUTTON__
#define __CALCBUTTON__
#include <QWidget>
#include "calculator.h"

class CalcButton : public QPushButton {
    public:
        std::string operation;
        CalcButton(Calculator<int(int, int)>&, const QString &, QWidget *);
        virtual void on_click() {};
    protected:
        Calculator<int(int,int)> &calculator;
};

class DigitButton: public CalcButton {
    public:
        uint8_t digit;
        DigitButton(Calculator<int(int, int)>&, QWidget*, uint8_t digit);
        void on_click();
};

class PlusButton: public CalcButton {
    public:
        PlusButton(Calculator<int(int, int)>&, QWidget*);
        void on_click();
};

class EqualButton: public CalcButton {
    public:
        EqualButton(Calculator<int(int, int)>&, QWidget*);
        void on_click();
};

class ClearButton: public CalcButton {
    public:
        ClearButton(Calculator<int(int, int)>&, QWidget*);
        void on_click();
};

#endif
