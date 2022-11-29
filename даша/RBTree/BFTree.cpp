//
// Created by Гусейнов Рамал on 13.11.2022.
//
#include "BFTree.h"
#include <iostream>
#include <iomanip>
#include <fstream>
void BFTree::destory(BFNode* &node) {
    if (node == nullptr)
        return;
    destory(node->left);
    destory(node->right);
    delete node;
    node = nullptr;
}


void BFTree::remove(int key) {
    BFNode*deletenode = search(root, key);
    if (deletenode != nullptr)
        remove(root, deletenode);
}

void BFTree::remove(BFNode*&root, BFNode*node) {
    BFNode *child, *parent;
    // Случай: оба ребенка существуют
    if (node->left != nullptr && node->right != nullptr) {
        BFNode *replace = node;
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
        replace->left = node->left;
        node->left->parent = replace;
        delete node;
        return;
    }
    // Когда в удаленном узле только левый (правый) узел пуст, найдите дочерний узел удаленного узла
    if (node->left != nullptr)
        child = node->left;
    else
        child = node->right;

    parent = node->parent;
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
        BFTree::root = child;
    delete node;
}



BFNode * BFTree::search(BFNode*node, int key) {
    if (!node || node->key == key) {
        return node;
    }
    else {
        countCompare++;
        if (key > node->key)
            return search(node->right, key);
        else
            return search(node->left, key);
    }
}


void BFTree::insert(int key, int val){
    auto* tmp = new BFNode(key, val);
    insert(root, tmp);
}

BFNode* BFTree::search(int key) {
    return search(root, key);
}


void BFTree::insert(BFNode* &root, BFNode* node) {
    BFNode *x = root;
    BFNode *y = nullptr;
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
    } else {
        root = node;
    }
}

void BFTree::out_right_left(BFNode* &root, int h, int lvl) {
    if (root->right) {
        out_right_left(root->right, h, lvl + 1);
    } else {
        if (lvl + 1 != h) {
            std::cout << std::setw((lvl + 2) * 15) << "n" << "\n";
        }
    }
    std::cout << std::setw((lvl + 1) * 15) << root->key<< " " << root->val << "\n";
    if (root->left) {
        out_right_left(root->left, h, lvl + 1);
    } else {
        if (lvl + 1 != h) {
            std::cout << std::setw((lvl + 2) * 15) << "n" << "\n";
        }
    }
}



int BFTree::hei(BFNode* &root, int h)const {
    if (!root){
        return h;
    }
    h++;
    return std::max(hei(root->right, h), hei(root->left, h));
}


void BFTree::input(){
    int i = 0;
    note b;
    std::ifstream fin("first.bin", std::ios::binary);

    while (fin.read((char *) &b, sizeof(note))) {
        insert(b.num, i++);
    }
}


void BFTree::print() {
    if (!root)
        std::cout << "empty RBtree\n";
    else
        out_right_left(root, 0);
}

