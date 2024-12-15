#ifndef __CALCWINDOW__
#define __CALCWINDOW__
#include <QWidget>
#include <QPushButton>
#include <QPlainTextEdit>
#include <iostream>
#include "calculator.h"
#include "calcbutton.h"

class CalcWindow : public QWidget
{
    Q_OBJECT
    public:
      Calculator<int (int, int)> calc;
      DigitButton *digits[10];
      PlusButton *plus;
      ClearButton *clear;
      EqualButton *equal;

      ~CalcWindow();
      CalcWindow(QWidget *w=NULL);
    signals:
            /* this object only receives for now */
    public slots:
        void onDigit(DigitButton*);
        void onOp(CalcButton*);
};

#endif
