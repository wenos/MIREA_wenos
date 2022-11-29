//
// Created by Гусейнов Рамал on 13.11.2022.
//

#ifndef RBTREE_BFTREE_H
#define RBTREE_BFTREE_H
#include "RBNode.h"

class BFTree {
public:
    void print(); //+
    void input(); //+
    void remove(int key); //+
    void insert(int key, int val);//+
    BFNode* search(int key);
    int countCompare = 0;
    BFTree() {}; //+
private:
    void insert(BFNode* &root, BFNode* node);//+
    void destory(BFNode* &node);
    void out_right_left(BFNode *&root, int h, int lvl=0);//+
    void remove(BFNode*& root, BFNode*node);
    BFNode * search(BFNode*node, int key); //+
    int hei(BFNode *&root, int h = 0) const; //+

    BFNode* root = nullptr;

};


#endif //RBTREE_BFTREE_H
