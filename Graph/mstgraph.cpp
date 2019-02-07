#include "mstgraph.h"
#include <qDebug>

MSTGraph::MSTGraph()
{
    //初始化查并集
    for (int i = 0; i < NODENUM; i++)
        DisJoint[i] = i;
    //初始化权值表
    for (int i = 0; i < NODENUM; i++)
        for (int j = 0; j < NODENUM; j++)
            if (i == j)
                Graph[i][j] = 0;
            else
                Graph[i][j] = MAXWEIGHT;
}

int cmp(const void *a, const void *b)// 比较器
{
    return ((Arc *)a)->w > ((Arc *)b)->w ? 1 : -1;
}

void MSTGraph::print(){
    main();
    QList<Arc> list = prim();
    foreach (Arc a, list) {
        qDebug() << a.u << a.v << a.w;
    }
}

int MSTGraph::DisJoint_Find(int idx) {
    if (DisJoint[idx] == idx)
        return idx;
    DisJoint[idx] = DisJoint_Find(DisJoint[idx]);
    // 压缩路径，而且若根节点已经更新也会递归更新上一层
    return DisJoint[idx];
}

bool MSTGraph::DisJoint_Merge(int node1, int node2) {
    int node1_iden = DisJoint_Find(node1);
    int node2_iden = DisJoint_Find(node2);
    if (node1_iden == node2_iden)
        return false;
    DisJoint[node2_iden] = node1_iden;
    return true;
}

void MSTGraph::main(){
    for (int count = 0; count < 200;) {
        int i = rand() % NODENUM, j = rand() % NODENUM;
        if (Graph[i][j] == MAXWEIGHT) {
            Graph[i][j] = Graph[j][i] = rand() % MAXWEIGHT;
            DisJoint_Merge(i, j);
            count++;
        }
    }


    for (int i = 0; i < NODENUM-1; i++) {
        int idx1 = DisJoint_Find(i), idx2 = DisJoint_Find(i + 1);//顺便更新并查集
        if (idx1 != idx2) {
            Graph[idx1][idx2] = rand() % MAXWEIGHT; // 连接代表元
            if (!DisJoint_Merge(idx1, idx2)) //若idx1和idx2已经连接，说明有逻辑错误
                qDebug() << "BIG BUG!!!";
        }
    }

    int arridx = 0;
    for (int i = 0; i < NODENUM; i++)
        for (int j = 0; j < NODENUM; j++)
            if (i < j && Graph[i][j] != MAXWEIGHT){ // 输出半边矩阵
                Arcs[arridx].u = i, Arcs[arridx].v = j, Arcs[arridx].w = Graph[i][j];
                arridx ++;
            }
}


QList<Arc> MSTGraph::kruskal(){
    kruskalcost = 0;
    QList<Arc> list;
    //Kruskal 算法
    qsort(Arcs, ARCNUM , sizeof(Arcs[0]), cmp);
    //初始化并查集
    for(int i = 0;i< NODENUM;i++){
        DisJoint[i] = i;
    }

    for (int i = 0; i < ARCNUM; i++)
    {
        if (DisJoint_Merge(Arcs[i].u, Arcs[i].v))
        {
            kruskalcost += Arcs[i].w;
            list << Arcs[i];
        }
    }
    return list;
}

QList<Arc> MSTGraph::prim(){
    primcost = 0;
    QList<Arc> list;
    bool visited[NODENUM];
    for (int i = 0; i < NODENUM; i++)
        visited[i] = false;
    visited[0] = true; //从0号节点开始产生
    int i, j, k;
    int power, power_j, power_k;
    for (i = 0; i < NODENUM; i++) {
        power = MAXWEIGHT;
        for (j = 0; j < NODENUM; j++) {
            if (visited[j]) {
                for (k = 0; k < NODENUM; k++) {
                    if (power > Graph[j][k] && !visited[k]) {
                        power = Graph[j][k];
                        power_j = j;
                        power_k = k;
                    }
                }
            }
        }
        if (!visited[power_k]) {
            visited[power_k] = true;
            primcost += power;
            list<< Arc(power_j, power_k, power);
        }
    }
    return list;
}
