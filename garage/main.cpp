#include "mainwindow.h"
#include "currencymodel.h"
#include "cartablemodel.h"
#include <QApplication>
#include <QMap>
#include <QTableView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();




    return a.exec();
}
