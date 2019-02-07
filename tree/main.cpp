#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
# include "huffmantree.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Node *node = new Node('A', 27);
    Node *node2 = new Node('B',8);
    Node *node3 = new Node('C',15);
    Node *node4 = new Node('D',15);
    Node *node5 = new Node('E',30);
    Node *node6 = new Node('F',5);
    QList<Node*> list;

    list.append(node);
    list.append(node2);
    list.append(node3);
    list.append(node4);
    list.append(node5);
    list.append(node6);
    HuffmanTree tree;
    //qDebug() << "d";
    tree.build(list);

    //qDebug() << "s";
    tree.trans();
//    MainWindow w;
//    w.show();

//    return a.exec();
    return 0;
}
