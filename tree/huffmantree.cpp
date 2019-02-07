#include "huffmantree.h"
//template<class T>
HuffmanTree::HuffmanTree()
{

}

Node::Node(char elem,double weight){
    this->el = elem;
    this->weight = weight;
    left=right=0;
}

Node::Node(Node *left, Node *right){
    this->el = '*';
    this->left=left;
    this->right=right;
    this->weight = left->weight + right->weight;
}

//template<class T>
//void HuffmanTree<T>::insert(const T &el)
//{
//    if (!root)
//        root =new BSTNode<T>(el);
//    BSTNode<T> *nptr = new BSTNode<T>(el);
//    BSTNode<T> *ptr = root;
//    while(ptr!=nullptr)
//    {
//        if (elem == ptr->elem) return &root->elem;
//        else if (elem > root->elem) root = root->right;
//        else root = root->left;
//    }
//}
void HuffmanTree::delNode(Node *root){
    if(!root)
        return;
    Node* leftNode = root->left;
    Node* rightNode = root->right;
    delete root;
    if(leftNode) delNode(leftNode);
    if(rightNode) delNode(rightNode);
}


void HuffmanTree::clear(){
    delNode(root);
    root = 0;
}


HuffmanTree::~HuffmanTree(){
    clear();
}

void HuffmanTree::build(QList<Node *>list){
//    clear();
    QSet<Node*> set;
    foreach(Node *ptr123,list){
        set << ptr123;
    }

    Node* nodeptr;
    Node* min = list.first();
    Node* min2 = list.first();
    while(set.size()!=1){
        //qDebug() << set.size();
        foreach(nodeptr,set){
            min = *set.begin();
            if (nodeptr->weight < min->weight)
                min = nodeptr;
        }
        set.erase(set.find(min));
        foreach(nodeptr,set){
            min2 = *set.begin();
            if (nodeptr->weight < min2->weight)
                min2 = nodeptr;
        }
                set.erase(set.find(min2));
        nodeptr = new Node(min ,min2);
        set.insert(nodeptr);
    }
    root = nodeptr;
}

void HuffmanTree::trans(){
    tran(root);
}
void HuffmanTree::tran(Node *node){
    if(node){
        qDebug() << node->el << "and" << node->weight;
        tran(node->left);
        tran(node->right);
    }else return;
}

//void HuffmanTree::trans2(){
//    tran2(root);
//}

//void HuffmanTree::tran2(Node *node){
//    if(node){
//        tran(node->left);
//        qDebug() << node->el << "and" << node->weight;
//        tran(node->right);
//    }
//}
