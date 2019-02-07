#ifndef WIDGET_H
#define WIDGET_H
#define RATIO 100
#define THIN 40

#include "mstgraph.h"
#include <QWidget>
#include <QPainter>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    int position[50][2];
    void base(QPainter &painter);
    void arc(QPainter &painter,int u, int v);
    MSTGraph *g;
    void ListArc(QPainter &painter, QList<Arc> list);
    void arrArc(QPainter &painter);
    bool usep = false;
    bool useo = false;
    bool usek = false;
    void setusep();
    void setuseo();
    void setusek();
protected:
    void paintEvent(QPaintEvent *);
    QList<Arc> prim;
    QList<Arc> k;
private slots:
    void on_kruskal_clicked(bool checked);

    void on_origin_clicked(bool checked);

    void on_prim_clicked(bool checked);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
