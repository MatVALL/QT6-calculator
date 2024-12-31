#ifndef __CALCWINDOW__
#define __CALCWINDOW__
#include <QWidget>
#include <QPushButton>
#include <QPlainTextEdit>
#include <iostream>
#include "calculator.h"
#include "calcbutton.h"
#include <QLabel>

class CalcWindow : public QWidget
{
    Q_OBJECT
    public:
      Calculator<int64_t (int64_t, int64_t)> calc;
      DigitButton *digits[10];
      PlusButton *plus;
      ClearButton *clear;
      EqualButton *equal;
      QLabel *result;

      ~CalcWindow();
      CalcWindow(QWidget *w=NULL);
    signals:
            /* this object only receives for now */
    public slots:
        void onDigit(DigitButton*);
        void onOp(CalcButton*);
};

#endif
