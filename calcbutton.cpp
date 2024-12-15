#include "calcbutton.h"
#include <assert.h>

/* {{{ CalcButton*/
CalcButton::CalcButton(Calculator<int(int,int)> &c, const QString &text="?", QWidget *parent = nullptr):
                       QPushButton(text, parent), calculator(c) {}
/* }}} CalcButton */
/* {{{ DigitButton*/

DigitButton::DigitButton(Calculator<int(int,int)>& c, QWidget* parent=nullptr, uint8_t digit=0):
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

PlusButton::PlusButton(Calculator<int(int,int)>& c, QWidget* parent):
                       CalcButton::CalcButton(c, "+", parent) {}

void PlusButton::on_click()
{
    this->calculator.setOperator([](int b, int c){return b+c;});
}
/* }}} */
/* {{{ EqualButton */

EqualButton::EqualButton(Calculator<int(int,int)>& c, QWidget* parent):
                         CalcButton::CalcButton(c, "=", parent) {}
void EqualButton::on_click()
{
    this->calculator.useOperator();
}

/* }}} */
/* {{{ ClearButton */

ClearButton::ClearButton(Calculator<int(int,int)>& c, QWidget* parent):
                         CalcButton::CalcButton(c, "C", parent) {}
void ClearButton::on_click()
{
    this->calculator.setOperator([](int a, int b){(void)a; (void)b;return 0;});
    this->calculator.useOperator();
}

/* }}} */
