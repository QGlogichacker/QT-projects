#ifndef MSTGRAPH_H
#define MSTGRAPH_H
#include <QList>
#define NODENUM 50
#define ARCNUM 200
#define MAXWEIGHT 20
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
struct Arc //边
{
    int u;
    int v;
    int w;
    Arc(int i,int j,int k){
        u = i;
        v = j;
        w = k;
    }
    Arc(){
    }
};

class MSTGraph
{
public:
    int nodenum = NODENUM;
    int arcnum = ARCNUM;
    int maxweight = MAXWEIGHT;
    Arc Arcs[200];  //弧边
    MSTGraph();
    int DisJoint[NODENUM]; //并查集
    int Graph[NODENUM][NODENUM]; //图
    int DisJoint_Find(int idx);
    bool DisJoint_Merge(int node1, int node2);
    int primcost = 0;
    int kruskalcost= 0;
public:
    void print();
    QList<Arc> prim();
    QList<Arc> kruskal();
    void main();
};

#endif // MSTGRAPH_H
