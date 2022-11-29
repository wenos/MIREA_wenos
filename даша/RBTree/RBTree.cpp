//
// Created by Гусейнов Рамал on 12.11.2022.
//
#include "RBTree.h"
#include <iostream>
#include <iomanip>
#include <fstream>

void RBTree::leftRotate(RBNode* &root, RBNode* x) {
    RBNode*y = x->right;
    x->right = y->left;
    if (y->left != nullptr)
        y->left->parent = x;

    y->parent = x->parent;
    if (x->parent == nullptr)
        root = y;
    else {
        if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void RBTree::rightRotate(RBNode*&root, RBNode*y) {
    RBNode*x = y->left;
    y->left = x->right;
    if (x->right != nullptr)
        x->right->parent = y;

    x->parent = y->parent;
    if (y->parent == nullptr)
        root = x;
    else {
        if  (y == y->parent->right)
            y->parent->right = x;
        else
            y->parent->left = x;
    }
    x->right = y;
    y->parent = x;
}


void RBTree::insert(int key, int val)
{
    size++;
    RBNode*z = new RBNode(key, val, Red, nullptr, nullptr, nullptr);
    insert(root, z);
}

void RBTree::insert(RBNode* &root, RBNode* node) {
    RBNode *x = root;
    RBNode *y = nullptr;
    while (x != nullptr) { // поиск места для вставки элемента
        y = x;
        if (node->key > x->key)
            x = x->right;
        else
            x = x->left;
    }
    node->parent = y;
    if(y!=nullptr)
    {
        if (node->key > y->key)
            y->right = node;
        else
            y->left = node;
    } else
    {
        root = node;
    }
    node->color = Red;
    InsertFixUp(root, node);
}

void RBTree::InsertFixUp(RBNode* &root, RBNode* node)
{
    RBNode* parent;
    parent = node->parent;
    while (node != RBTree::root && parent->color == Red)
    {
        RBNode* gparent = parent->parent;
        if (gparent->left == parent)
        {
            RBNode* uncle = gparent->right;
            if (uncle != nullptr && uncle->color == Red)
            {
                parent->color = Black;
                uncle->color = Black;
                gparent->color = Red;
                node = gparent;
                parent = node->parent;
            }
            else {
                if (parent->right == node)
                {
                    leftRotate(root, parent);
                    std::swap(node, parent);
                }
                countRotate++;
                rightRotate(root, gparent);
                gparent->color = Red;
                parent->color = Black;
                break;
            }
        }
        else
        {
            RBNode*uncle = gparent->left;
            if (uncle != nullptr && uncle->color == Red)
            {
                gparent->color = Red;
                parent->color = Black;
                uncle->color = Black;
                node = gparent;
                parent = node->parent;
            }
            else
            {
                if (parent->left == node)
                {
                    rightRotate(root, parent);
                    std::swap(parent, node);
                }
                countRotate++;
                leftRotate(root, gparent);
                parent->color = Black;
                gparent->color = Red;
                break;
            }
        }
    }
    root->color = Black;
}

void RBTree::destory(RBNode* &node)
{
    if (node == nullptr)
        return;
    destory(node->left);
    destory(node->right);
    delete node;
    node = nullptr;
}


void RBTree::remove(int key)
{
    RBNode*deletenode = search(root, key);
    if (deletenode != nullptr)
        remove(root, deletenode);
}

void RBTree::remove(RBNode*&root, RBNode*node) {
    RBNode *child, *parent;
    RBColor color;
    // Случай: оба ребенка существуют
    if (node->left != nullptr && node->right != nullptr) {
        RBNode *replace = node;
        // Поиск самого маленького правого преемника
        replace = node->right;
        while (replace->left != nullptr) {
            replace = replace->left;
        }
        // Заменяем указатель на ребенка
        if (node->parent != nullptr) {
            if (node->parent->left == node) {
                node->parent->left = replace;
            } else {
                node->parent->right = replace;
            }
        } else
            // Случай: удаляемый элемент является корнем
            root = replace;
        child = replace->right;
        parent = replace->parent;
        color = replace->color;

        // Случай: заменяемый элемент ребенок удаляемого
        if (parent == node)
            parent = replace;
        else
        {
            // Случай: у заменяемого элемента существует правый ребенок
            if (child != nullptr)
                child->parent = parent;
            parent->left = child;
            replace->right = node->right;
            node->right->parent = replace;
        }
        replace->parent = node->parent;
        replace->color = node->color;
        replace->left = node->left;

        node->left->parent = replace;
        if (color == Black)
            removeFixUp(root, child, parent);

        delete node;
        return;
    }
    if (node->left != nullptr)
        child = node->left;
    else
        child = node->right;

    parent = node->parent;
    color = node->color;
    if (child)
    {
        child->parent = parent;
    }
    // Случай: удаленный узел не является корневым узлом
    if (parent) {
        if (node == parent->left) {
            parent->left = child;
        } else {
            parent->right = child;
        }
    }
    else
        // Случай удаленный узел является корневым узлом
        RBTree::root = child;
    if (color == Black) {
        removeFixUp(root, child, parent);
    }
    delete node;
}

void RBTree::removeFixUp(RBNode* &root, RBNode* node, RBNode*parent)
{
    RBNode*othernode;
    while ((!node) || node->color == Black && node != RBTree::root)
    {
        if (parent->left == node)
        {
            othernode = parent->right;
            if (othernode->color == Red)
            {
                othernode->color = Black;
                parent->color = Red;
                countRotate++;
                leftRotate(root, parent);
            }
            else
            {
                if (!(othernode->right) || othernode->right->color == Black)
                {
                    othernode->left->color=Black;
                    othernode->color = Red;
                    countRotate++;

                    rightRotate(root, othernode);
                    othernode = parent->right;
                }
                othernode->color = parent->color;
                parent->color = Black;
                othernode->right->color = Black;
                countRotate++;

                leftRotate(root, parent);
                node = root;
                break;
            }
        }
        else
        {
            othernode = parent->left;
            if (othernode->color == Red)
            {
                othernode->color = Black;
                parent->color = Red;
                countRotate++;
                rightRotate(root, parent);
                othernode = parent->left;
            }
            if ((!othernode->left || othernode->left->color == Black) && (!othernode->right || othernode->right->color == Black))
            {
                othernode->color = Red;
                node = parent;
                parent = node->parent;
            }
            else
            {
                if (!(othernode->left) || othernode->left->color == Black)
                {
                    othernode->right->color = Black;
                    othernode->color = Red;
                    countRotate++;

                    leftRotate(root, othernode);
                    othernode = parent->left;
                }
                othernode->color = parent->color;
                parent->color = Black;
                othernode->left->color = Black;
                countRotate++;

                rightRotate(root, parent);
                node = root;
                break;
            }
        }
    }
    if (node)
        node->color = Black;
}

RBNode* RBTree::search(int key)
{
    return search(root, key);
}

RBNode * RBTree::search(RBNode*node, int key) {
    if (!node || node->key == key)
        return node;
    else {
        countCompare++;
        if (key > node->key)
            return search(node->right, key);
        else
            return search(node->left, key);
    }
}

void RBTree::out_right_left(RBNode* &root, int h, int lvl) {
    if (root->right) {
        out_right_left(root->right, h, lvl + 1);
    } else {
        if (lvl + 1 != h) {
            std::cout << std::setw((lvl + 2) * 8) << "n" << "\n";
        }
    }
    std::cout << std::setw((lvl + 1) * 8) << root->key << " " << root->val << " " << root->color<< "\n";
    if (root->left) {
        out_right_left(root->left, h, lvl + 1);
    } else {
        if (lvl + 1 != h) {
            std::cout << std::setw((lvl + 2) * 8) << "n" << "\n";
        }
    }
}

void RBTree::print() {
    if (!root)
        std::cout << "empty RBtree\n";
    else
        out_right_left(root, 0);
}

int RBTree::hei(RBNode* &root, int h){
    if (!root){
        return h;
    }
    h++;
    return std::max(hei(root->right, h), hei(root->left, h));
}

void RBTree::input(){
    std::ifstream fin("first.bin", std::ios::binary);
    int i = 0;
    note b{};
    while (fin.read((char *) &b, sizeof(note))) {
        insert(b.num, i++);
    }
}