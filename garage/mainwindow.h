#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QListView>
#include <QAction>
#include <QStringList>
#include <QStringListModel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QDialog>
#include <qDebug>
#include <QFileDialog>
#include <QCloseEvent>
#include <QObject>
#include <QEvent>
#include "cartablemodel.h"
#include <QTableView>
#include "priceculculate.h"
#include "realprice.h"
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void insertData();
    void deleteData();
    void searchData();
    void modifyData();

    QAction *MyInsertAction;
    QAction *MyDeleteAction;
    QAction *MySearchAction;
    QAction *MyModifyAction;
    void setPrice(PriceCulculate pc);
private:
    CarTableModel *model;
    QTableView *view;
    RealPrice *slove;
};

#endif // MAINWINDOW_H
