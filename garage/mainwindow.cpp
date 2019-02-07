#include "mainwindow.h"
#include <QInputDialog>
#include <QMap>
#include <QString>
#include <QStringList>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent)
{
    QMap <QString, QString> car;
    car["color"] = "实例颜色";
    car["time"] = "实例时间";
    car["wat"] = "随便一个属性";
    car["added"] = "123";
    car["123"] = "JSON";
    car["rande"] = "12263";
    car["ID"] = "粤J123456";
    slove = new RealPrice;
    view = new QTableView(this);
    model  = new CarTableModel(car,view);
    view->setModel(model);



    MyInsertAction = new QAction(QIcon(":/images/file-save"), tr("&Insert"), this);
    MyInsertAction->setStatusTip(tr("Insert a record of cars ..."));
    connect(MyInsertAction, &QAction::triggered, this, &MainWindow::insertData);

    MyDeleteAction = new QAction(QIcon(":/images/file-save"), tr("&Delete"), this);
    MyDeleteAction->setStatusTip(tr("Delete a record of cars ..."));
    connect(MyDeleteAction, &QAction::triggered, this, &MainWindow::deleteData);

    MySearchAction = new QAction(QIcon(":/images/file-save"), tr("&Find"), this);
    MySearchAction->setStatusTip(tr("Search for a record of cars ..."));
//    connect(MySearchAction, &QAction::triggered, this, &MainWindow::searchData);

    MyModifyAction = new QAction(QIcon(":/images/file-save"), tr("&Modify..."), this);
    MyModifyAction->setStatusTip(tr("Modify a record of cars ..."));
//    connect(MyModifyAction, &QAction::triggered, this, &MainWindow::modifyData);

    QMenuBar*menu = menuBar();
    QMenu *dataOperation = menu->addMenu(tr("Car Opearation"));
    dataOperation->addAction(MyInsertAction);
    dataOperation->addAction(MyDeleteAction);
    dataOperation->addAction(MyModifyAction);
    dataOperation->addAction(MySearchAction);

    statusBar() ;
    //最后加一个状态栏
    setCentralWidget(view);
    resize(600 , 400);
}

MainWindow::~MainWindow(){
}

void MainWindow::insertData(){
    bool isOK;
    QString text = QInputDialog::getText(this, "Insert", "Please input new data:", QLineEdit::Normal, "split with space", &isOK);
    QStringList sarr = text.split(" ");
    if(isOK){
        if(sarr.count()!=model->columnCount()){
            QMessageBox::warning(this,"Wrong Input", "Please input data in order");
            return;
        }
        qDebug() << sarr.count()<<model->columnCount();
        QMap<QString, QString> map = QMap<QString, QString>(model->std);
        for(int i=0;i<model->columnCount();i++){
            map.insert(model->currencyAt(i),sarr[i]);
        }
        map["time"] = tr("%1").arg(QDateTime::currentSecsSinceEpoch());
        model->addItem(map);
    }
}

void MainWindow::deleteData(){
    if (model->rowCount() > 1) {
                qDebug() << view->currentIndex().row();
        qint64 time = model->removeItem(view->currentIndex().row());
        QMessageBox::information(this, tr("Price"), tr("Price calculated:%1").arg(slove->calculate(time)));
    }
}

void MainWindow::searchData(){

}

void MainWindow::modifyData(){

}

