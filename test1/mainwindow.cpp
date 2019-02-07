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
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setWindowTitle(tr("Main Window"));

    openAction = new QAction(QIcon(":/images/file-open"), tr("&Open..."), this);
    //构造函数：QIcon，字符串，和this
    //&符号是快捷键
    openAction->setShortcuts(QKeySequence::Open);
    //跨平台实现快捷键(不同设备可能没有Ctrl)
    openAction->setStatusTip(tr("Open an existing file"));
    //设置状态栏提示
    connect(openAction, &QAction::triggered, this, &MainWindow::open);

    
    saveAction = new QAction(QIcon(":/images/file-save"), tr("&Open..."), this);
    saveAction->setShortcuts(QKeySequence::Save);
    saveAction->setStatusTip(tr("Save a new file .."));
    connect(saveAction, &QAction::triggered, this, &MainWindow::save);

    QMenu *file = menuBar()->addMenu(tr("&File"));
    //注意观察如何正确创建Menu
    file->addAction(openAction);
    file->addAction(saveAction);

    QToolBar *toolBar = addToolBar(tr("&File"));
    //和使用toolbar
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);

    statusBar() ;
    //最后加一个状态栏

    textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);
    //textEdit->installEventFilter(this);

    connect(textEdit, &QTextEdit::textChanged, [=]() {
        this->setWindowModified(true);
    });

    setWindowTitle("TextPad [*]");
}

MainWindow::~MainWindow()
{
}

void MainWindow::open()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open File"), ".", tr("Text Files(*.txt)"));
    if(!path.isEmpty()){ //选择为空的分支
        QFile file(path);
        if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){ //文件无法打开的分支
            QMessageBox::warning(this, tr("Open File"), tr("Cannot Open this file:\n%1").arg(path));
            return;
        }
        //真正产生效用的
        QTextStream in(&file);
        textEdit->setText(in.readAll());
        file.close();
        this->setWindowModified(false);
    }else{
        QMessageBox::warning(this, tr("path"), tr("You didn't selected any file!"));
    }
}

void MainWindow::save(){
    QString path = QFileDialog::getSaveFileName(this, tr("Save File"), ".", tr("Text Files(*.txt)"));
    if(!path.isEmpty()){ //选择为空的分支
        QFile file(path);
        if(!file.open(QIODevice::WriteOnly|QIODevice::Text)){ //文件无法打开的分支
            QMessageBox::warning(this, tr("Save File"), tr("Cannot Open this file:\n%1").arg(path));
            return;
        }
        //真正产生效用的
        QTextStream out(&file);
        out << textEdit->toPlainText();
        file.close();
        this->setWindowModified(false);
    }else{
        QMessageBox::warning(this, tr("path"), tr("You didn't selected any file!"));
    }
}

void MainWindow::closeEvent(QCloseEvent *e){
    if(isWindowModified()){
        bool exit = QMessageBox::question(this, tr("Quit"), tr("Are you sure to quit this application?"), QMessageBox::Yes|QMessageBox::No, QMessageBox::No) == QMessageBox::Yes;
        if(exit) e->accept();
        else e->ignore();
    }else{
        e->accept();
    }
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event){
    if(obj == textEdit){
        if(event->type() == QEvent::KeyPress){
            QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
            qDebug() << "Any Press" <<keyEvent->key();
            return true;
        }else{
            return false;
        }
    }else{
        return QMainWindow::eventFilter(obj,event);
    }
}
