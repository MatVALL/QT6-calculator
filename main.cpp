#include <QApplication>
#include "calcwindow.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    CalcWindow *calc = new CalcWindow(NULL);

    for (int i = 0; i < 10; i++) {
        QObject::connect(calc->digits[i], &QPushButton::clicked,
                         calc, [=]() { calc->onDigit(calc->digits[i]);});
    }
    QObject::connect(calc->clear, &QPushButton::clicked,
                     calc, [=]() { calc->onOp(calc->clear);});
    QObject::connect(calc->plus, &QPushButton::clicked,
                     calc, [=]() { calc->onOp(calc->plus);});
    QObject::connect(calc->equal, &QPushButton::clicked,
                     calc, [=]() { calc->onOp(calc->equal);});
    QObject::connect(calc->minus, &QPushButton::clicked,
                     calc, [=]() { calc->onOp(calc->minus);});
    calc->show();

    return app.exec();}
