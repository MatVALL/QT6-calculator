#ifndef __CALCWINDOW__
#define __CALCWINDOW__
#include <QWidget>
#include <QPushButton>
#include <QPlainTextEdit>
#include <iostream>

class Calculator {
    public:
        std::string current_operation;
        void add_to_operation(std::string op) {
            current_operation += op;
        };
        Calculator() {
            current_operation = "";
        }
};

class CalcButton : public QPushButton {
    public:
        std::string operation;
        Calculator &calculator;
        CalcButton(Calculator &c, const QString &text, QWidget *parent = nullptr):
            QPushButton(text, parent),
            calculator(c)
        {
            this->operation = text.toStdString();
        }
};

class CalcWindow : public QWidget
{
    Q_OBJECT
        public:
          Calculator calc;
          CalcButton *m_button[10];
    
          ~CalcWindow() {};
          CalcWindow(QWidget *parent=NULL) : QWidget(parent)
          {
              (void) parent;
             // Set size of the window
             setFixedSize(300, 250);

            // Create and position the button

             for (int i = 0; i < 9; i++) {
                 int x = i % 3;
                 int y = i / 3;
                 m_button[i+1] = new CalcButton(calc, QString::fromStdString(std::to_string(i+1)), this);
                 m_button[i+1]->setGeometry(x*100, y*50+50, 100, 50);
             }
             m_button[0] = new CalcButton(calc, QString::fromStdString(std::to_string(0)), this);
             m_button[0]->setGeometry(100,200, 100, 50);
          }
    signals:
        /* this object only receives for now */
    public slots:
        void somethingHapenned(const CalcWindow* w, int i)
        {
            this->calc.add_to_operation(w->m_button[i]->operation);
            std::cout << this->calc.current_operation << std::endl;
        }
};

#endif
