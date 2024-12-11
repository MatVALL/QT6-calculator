#include <QApplication>
#include "calculator.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    CalcWindow *calc = new CalcWindow(NULL);

    for (int i = 0; i < 10; i++) {
        QObject::connect(calc->m_button[i], &QPushButton::clicked,
                         calc,
            [=]() { calc->somethingHapenned(calc, i);});
    }
    calc->show();

    return app.exec();}
