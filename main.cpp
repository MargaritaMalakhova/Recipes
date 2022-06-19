#include <QApplication>
#include "viewservice.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ViewService master;

    return a.exec();
}
