#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QObject>
#include <QEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent *e);
    bool eventFilter(QObject *obj,QEvent *event);
private:
    void open();
    void save();
    QAction *openAction;
    QAction *saveAction;
    QTextEdit *textEdit;
};

#endif // MAINWINDOW_H
