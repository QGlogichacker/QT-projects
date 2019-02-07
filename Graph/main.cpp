#include <QCoreApplication>
#include <qDebug>
#include "mstgraph.h"
#include "paintedwidget.h"

//int main(int argc, char *argv[]) {
//    for (int count = 0; count < 200;) {
//        int i = rand() % NODENUM, j = rand() % NODENUM;
//        if (Graph[i][j] == MAXWEIGHT) {
//            Graph[i][j] = Graph[j][i] = rand() % MAXWEIGHT;
//            DisJoint_Merge(i, j);
//            count++;
//        }
//    }
//    cout << endl << "并查集数组:";
//    for (int i = 0; i < NODENUM; i++)
//        cout << DisJoint[i] << ' ';
//    cout <<endl;

//    for (int i = 0; i < NODENUM-1; i++) {
//        int idx1 = DisJoint_Find(i), idx2 = DisJoint_Find(i + 1);//顺便更新并查集
//        if (idx1 != idx2) {
//            cout << "补充连接" << idx1 << "和" << idx2 << endl;
//            Graph[idx1][idx2] = rand() % MAXWEIGHT; // 连接代表元
//            if (!DisJoint_Merge(idx1, idx2)) //若idx1和idx2已经连接，说明有逻辑错误
//                cout << "BIG BUG!!!";
//        }
//    }

//    cout << endl << "补充连接后:";
//    for (int i = 0; i < NODENUM; i++)
//        cout << DisJoint_Find(i) << ' ';
//    cout << endl;

//    int arridx = 0;
//    cout << "输出形成的边:" << endl;
//    for (int i = 0; i < NODENUM; i++)
//        for (int j = 0; j < NODENUM; j++)
//            if (i < j && Graph[i][j] != MAXWEIGHT) // 输出半边矩阵
//            {
//                cout << i << '\t' << j << '\t' << Graph[i][j] << endl;
//                Arcs[arridx].u = i, Arcs[arridx].v = j, Arcs[arridx].w = Graph[i][j];
//                arridx++;
//            }
//    cout << "成功生成了200余条边的单连通图" << endl;

//    cout << "以下是Kruskal算法的生成情况" << endl;
//    //Kruskal 算法
//    int sum = 0;
//    qsort(Arcs, ARCNUM , sizeof(Arcs[0]), cmp);
//    DisJoint_Init();

//    int idx = 0;
//    for (int i = 0; i < ARCNUM; i++)
//    {
//        if (DisJoint_Merge(Arcs[i].u, Arcs[i].v))
//        {
//            sum += Arcs[i].w;
//            cout << idx <<": "<< Arcs[i].u << ", "<<Arcs[i].v << " "<<endl;
//            idx++;
//        }
//    }
//    cout <<endl<<"总的权值和为："<< sum << endl;

//    cout << "以下是Prim算法的生成情况" << endl;
//    qDebug() << "以下是Prim算法的生成情况" << endl;
//    qDebug() << "以下是Prim算法的生成情况" ;
//    bool visited[NODENUM];
//    for (int i = 0; i < NODENUM; i++)
//        visited[i] = false;
//    visited[0] = true; //从0号节点开始产生
//    int i, j, k;
//    int power, power_j, power_k;
//    idx = 0;
//    sum = 0;
//    for (i = 0; i < NODENUM; i++) {
//        power = MAXWEIGHT;
//        for (j = 0; j < NODENUM; j++) {
//            if (visited[j]) {
//                for (k = 0; k < NODENUM; k++) {
//                    if (power > Graph[j][k] && !visited[k]) {
//                        power = Graph[j][k];
//                        power_j = j;
//                        power_k = k;
//                    }
//                }
//            }
//        }
//        if (!visited[power_k]) {
//            visited[power_k] = true;
//            sum += power;
//            cout << idx << ": " << power_j << ", " << power_k << " " << endl;
//            idx++;
//        }
//    }

//    cout << endl << "总的权值和为：" << sum << endl;
//    //    QCoreApplication a(argc, argv);
//    //    return a.exec();
//    return 0;
//}

int main(int argc, char *argv[]){
        QCoreApplication a(argc, argv);
        //MSTGraph ga;
        //ga.print();
        PaintedWidget pw;
        pw.exec();
        return a.exec();
}
