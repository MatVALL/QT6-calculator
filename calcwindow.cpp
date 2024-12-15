#include "calcwindow.h"

CalcWindow::~CalcWindow() {};
CalcWindow::CalcWindow(QWidget *parent) : QWidget(parent)
{
    (void) parent;
   // Set size of the window
   setFixedSize(300, 250);

  // Create and position the button
   for (int i = 0; i < 9; i++) {
       int x = i % 3;
       int y = i / 3;
       digits[i+1] = new DigitButton(calc, this, i+1);
       digits[i+1]->setGeometry(x*100, y*50+50, 100, 50);
   }
   digits[0] = new DigitButton(calc, this, 0);
   digits[0]->setGeometry(100,200, 100, 50);
   clear = new ClearButton(calc, this);
   clear->setGeometry(0,200, 100, 50);
   plus = new PlusButton(calc, this);
   plus->setGeometry(200,200, 100, 50);
   equal = new EqualButton(calc, this);
   equal->setGeometry(100,200, 100, 50);
}

void CalcWindow::onDigit(DigitButton* w)
{
    w->on_click();
}

void CalcWindow::onOp(CalcButton* w)
{
    w->on_click();
}
