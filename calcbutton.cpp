#include "calcbutton.h"
#include <assert.h>

/* {{{ CalcButton*/
CalcButton::CalcButton(Calculator<int64_t(int64_t,int64_t)> &c, const QString &text="?", QWidget *parent = nullptr):
                       QPushButton(text, parent), calculator(c) {}
/* }}} CalcButton */
/* {{{ DigitButton*/

DigitButton::DigitButton(Calculator<int64_t(int64_t,int64_t)>& c, QWidget* parent=nullptr, uint8_t digit=0):
                         CalcButton::CalcButton(c, QString::fromStdString(std::to_string(digit)),
                                 parent), digit(digit)
{
    /* TODO: throw exception */
    assert(digit < 10);
};

void DigitButton::on_click()
{
    this->calculator.addDigit(this->digit);
}

/* }}} DigitButton */
/* {{{ PlusButton */

PlusButton::PlusButton(Calculator<int64_t(int64_t,int64_t)>& c, QWidget* parent):
                       CalcButton::CalcButton(c, "+", parent) {}

void PlusButton::on_click()
{
    this->calculator.setOperator([](int64_t b, int64_t c){return b+c;});
}
/* }}} */
/* {{{ MinusButton */

MinusButton::MinusButton(Calculator<int64_t(int64_t,int64_t)>& c, QWidget* parent):
                       CalcButton::CalcButton(c, "-", parent) {}

void MinusButton::on_click()
{
    this->calculator.setOperator([](int64_t b, int64_t c){return c-b;});
}
/* }}} */
/* {{{ EqualButton */

EqualButton::EqualButton(Calculator<int64_t(int64_t,int64_t)>& c, QWidget* parent):
                         CalcButton::CalcButton(c, "=", parent) {}
void EqualButton::on_click()
{
    this->calculator.useOperator();
}

/* }}} */
/* {{{ ClearButton */

ClearButton::ClearButton(Calculator<int64_t(int64_t,int64_t)>& c, QWidget* parent):
                         CalcButton::CalcButton(c, "C", parent) {}
void ClearButton::on_click()
{
    this->calculator.setOperator([](int64_t a, int64_t b){(void)a; (void)b;return (int64_t)0;});
    this->calculator.useOperator();
}

 /* }}} */

