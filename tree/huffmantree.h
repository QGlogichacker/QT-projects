#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H
# include <QSet>
#include <QList>
# include <qDebug>
//template<class T>
class Node{
public :
    char el;
    Node * left;
    Node *right;
    double weight;
    Node(char elem,double weight);
    Node(Node*left,Node*right);

};

//template<class T>
class HuffmanTree
{
public:
    HuffmanTree();
    ~HuffmanTree();
    void trans();
    void tran(Node * node);
    void insert(const  &el);
    void clear();
    void build(QList<Node*>list);
protected:
    Node *root;
    void delNode(Node *root);
};


#endif // HUFFMANTREE_H
