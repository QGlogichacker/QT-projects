#include "widget.h"
#include "ui_widget.h"
#include "mstgraph.h"

#include <QPainter>
#include <qDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    g(new MSTGraph)
{
    ui->setupUi(this);
    resize(800, 800);
    setWindowTitle(tr("Paint Demo"));

    for(int i = 0;i< 50;i++){
        position[i][0] = (i)/7 + 1;
        position[i][1] = (i)%7 + 1;
    }
    g->gen();
    prim = g->prim();
    k = g->kruskal();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::base(QPainter &painter){
    for(int i = 0;i< 50;i++){
        painter.drawEllipse(position[i][0]*RATIO - RATIO/2, position[i][1]*RATIO - RATIO/2, THIN, THIN);
    }
}

void Widget::arc(QPainter &painter,int u, int v){
    int x1 = position[u][0]*RATIO - RATIO/2 + THIN/2,
            y1 = position[u][1]*RATIO - RATIO/2 + THIN/2,
            x2 = position[v][0]*RATIO - RATIO/2 + THIN/2,
            y2 = position[v][1]*RATIO - RATIO/2 + THIN/2;
    painter.drawLine(x1,y1,x2, y2);
}

void Widget::ListArc(QPainter &painter, QList<Arc> list){
    for(auto i = list.begin(); i != list.end() ; i++){
        arc(painter, (*i).u, (*i).v);
    }
}

void Widget::arrArc(QPainter &painter){
    for(int i = 0;i < ARCNUM ;i++){
        arc(painter, g->Arcs[i].u, g->Arcs[i].v);
    }
}


void Widget::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setBrush(Qt::blue);
    if(useo){
        painter.setPen(QPen(Qt::black, 5));
        arrArc(painter);
    }
    if(usek){
        painter.setPen(QPen(Qt::red, 5));
        ListArc(painter, k);
    }
    if(usep){
        painter.setPen(QPen(Qt::green, 5));
        ListArc(painter, prim);
    }

    base(painter);

}

void Widget::on_kruskal_clicked(bool checked)
{
    usek = checked;
    update();
}

void Widget::on_origin_clicked(bool checked)
{
    useo = checked;
    update();
}

void Widget::on_prim_clicked(bool checked)
{
    usep = checked;
    update();
}
