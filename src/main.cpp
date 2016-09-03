#include "mainwindow.h"
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(argc, argv);
    w.resize(600,390);
    w.setWindowTitle("Fly Control GUI");
    w.show();

    return a.exec();
}

