//
// Created by Гусейнов Рамал on 12.11.2022.
//

#ifndef RBTREE_RBTREE_H
#define RBTREE_RBTREE_H


#include"RBNode.h"
#include <iomanip>


class  RBTree {
public:
    int size = 0;
    int countRotate = 0;
    int countCompare = 0;
    void insert(int key, int val);
    void remove(int key);
    RBNode* search(int key);
    void print();
    RBTree(){};
    void input();
private:
    void leftRotate(RBNode* &root, RBNode* x);
    void rightRotate(RBNode* &root, RBNode* y);
    void insert(RBNode* &root, RBNode* node);
    void InsertFixUp(RBNode* &root, RBNode* node);
    void destory(RBNode* &node);
    void out_right_left(RBNode *&root, int h, int lvl=0);
    void remove(RBNode*& root, RBNode*node);// Удалить узел как KEY
    void removeFixUp(RBNode* &root, RBNode* node, RBNode*parent);
    RBNode * search(RBNode*node, int key);
    RBNode*root = nullptr;
    int hei(RBNode *&root, int h = 0);

};



#endif //RBTREE_RBTREE_H
