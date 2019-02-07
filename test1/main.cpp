#include "mainwindow.h"
#include <QApplication>
#include "eventlabel.h"
#include "custombutton.h"
#include "paintedwidget.h"
#include <QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QGraphicsScene scene;
    //scene.setSceneRect(0, 0, 300, 300);
    scene.addLine(0, 0, 150, 150);

    QGraphicsView view(&scene);
    view.setWindowTitle("Graphics View");
    view.resize(500, 500);
    view.show();

    return app.exec();
}
