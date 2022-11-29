//
// Created by Гусейнов Рамал on 12.11.2022.
//

#ifndef RBTREE_RBNODE_H
#define RBTREE_RBNODE_H

enum RBColor {Black, Red};

struct note
{
    int num;
    unsigned int code;
    char fam[7];
};


struct RBNode {
    int key;
    int val;
    RBColor color;
    RBNode* parent;
    RBNode* left;
    RBNode* right;
    RBNode(int k, int v, RBColor c, RBNode* p, RBNode* l, RBNode* r):
        key(k), val(v), color(c), parent(p), left(l), right(r){ };
};

struct BFNode {
    int key;
    int val;
    BFNode* parent;
    BFNode* left;
    BFNode* right;
    BFNode(int k, int v, BFNode* p = nullptr, BFNode* l = nullptr, BFNode* r = nullptr):
            key(k), val(v), parent(p), left(l), right(r){ };
};

struct node
{
    int key = -1;
    int num = -1;
    node* next = nullptr;
};



#endif //RBTREE_RBNODE_H