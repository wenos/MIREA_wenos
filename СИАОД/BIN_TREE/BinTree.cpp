//
// Created by Гусейнов Рамал on 28.10.2022.
//
#include "BinTree.h"
#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
#include <cmath>


BinTree::BinTree(int val) {
    this->val = val;
}

BinTree::BinTree() {
    this->val = 0;
}

void BinTree::fill_arr(int *arr, int l, int r) {
    val = arr[l++];
    int m = (l + r) / 2; // 2
    if (l > r) {
        return;
    }
    if (r - l == 1) {
        this->left = new BinTree(arr[l]);
        this->right = new BinTree(arr[r]);
    } else if (l == r) {
        this->left = new BinTree(arr[l]);
    } else {
        this->left = new BinTree;
        this->left->fill_arr(arr, l, m);
        if (r == m) {
            this->right = new BinTree(arr[r]);
        } else {
            this->right = new BinTree;
            this->right->fill_arr(arr, m + 1, r);
        }
    }
}

void BinTree::fill_input(int n) {
    int value;
    std::cin >> value;
    this->val = value;
    --n;
    int l, r;
    r = n / 2;
    l = n - r;
    if (l > 0) {
        this->left = new BinTree;
        this->left->fill_input(l);
    }
    if (r > 0) {
        this->right = new BinTree;
        this->right->fill_input(r);
    }
}

void BinTree::fill_random(int n) {
    this->val = rand() % 100;
    --n;
    int r = n / 2, l = n - r;
    if (l > 0) {
        this->left = new BinTree;
        this->left->fill_random(l);
    }
    if (r > 0) {
        this->right = new BinTree;
        this->right->fill_random(r);
    }
}


BinTree::BinTree(BinTree *&other) {
    this->val = other->val;
    if (other->left){
        this->left = new BinTree(other->left);
    }
    if (other->right){
        this->right = new BinTree(other->right);
    }
};

int BinTree::height() {
    BinTree *tmp = this;
    int count = 0;
    while (tmp) {
        ++count;
        tmp = tmp->left;
    }
    return count;
}

void BinTree::out_queue() {
    int h = height(), i = 0, lvl = 0, end_i = 1;
    std::queue<BinTree *> q;
    q.push(this);
    while (lvl != h) { // пока уровень не дошел до значения высоты
        std::cout << std::setw(pow(2, h - lvl) - 2) << "";
        while (i++ != end_i) {
            BinTree *tmp = q.front();
            q.pop();
            std::cout << std::setw(4) << (tmp ? std::to_string(tmp->val) : "n")
                      << std::setw(pow(2, h - lvl - 1) * 4 - 4) << "";
            if (tmp) {
                q.push(tmp->left);
                q.push(tmp->right);
            }
        }
        std::cout << std::endl;
        ++lvl;
        i = 0;
        end_i *= 2;
    }
}

void BinTree::out_vector() {
    std::vector<std::vector<BinTree *>> a;
    std::vector<BinTree *> b;
    a.push_back(b);
    a[0].push_back(this);
    for (int i = 0; i < a.size(); ++i) {
        std::vector<BinTree *> c;
        for (auto &j: a[i]) {
            if (j) {
                c.push_back(j->left);
                c.push_back(j->right);
            }
        }
        if (c[0]) {
            a.push_back(c);
        }
    }

    for (int i = 0; i < a.size(); ++i) {
        std::cout << std::setw(pow(2, a.size() - i) - 2) << "";
        for (int j = 0; j < a[i].size(); ++j) {
            std::cout << std::setw(4) << (a[i][j] ? std::to_string(a[i][j]->val) : "n")
                      << std::setw(pow(2, a.size() - i - 1) * 4 - 4) << "";
        }
        std::cout << std::endl;
    }
}

void BinTree::out_right_left(int h, int lvl) {
    if (this->right) {
        this->right->out_right_left( h,lvl + 1);
    } else {
        if (lvl + 1 != h) {
            std::cout << std::setw((lvl + 2) * 4) << "n" << "\n";
        }
    }
    std::cout << std::setw((lvl + 1) * 4) << this->val << "\n";
    if (this->left) {
        this->left->out_right_left(h, lvl + 1);
    } else {
        if (lvl + 1 != h) {
            std::cout << std::setw((lvl + 2) * 4) << "n" << "\n";
        }
    }

//    std::vector<std::vector<BinTree *>> a;
//    std::vector<BinTree *> b;
//    a.push_back(b);
//    a[0].push_back(this);
//    for (int i = 0; i < a.size(); ++i) {
//        std::vector<BinTree *> c;
//        for (auto &j: a[i]) {
//            if (j) {
//                c.push_back(j->left);
//                c.push_back(j->right);
//            }
//        }
//        if (c[0]) {
//            a.push_back(c);
//        }
//    }
//    int n = a[a.size() - 1].size() * 2;
//    int counter = 1;
//    while (counter != n) {
//        int m = 1;
//        int cnt = 0;
//        while (!(m & counter)) {
//            m <<= 1;
//            ++cnt;
//        }
//        int lvl = a.size() - cnt - 1;
//        int row = a[lvl].size() - counter / (m << 1) - 1;
//        std::cout << std::setw(4 * lvl) << (a[lvl][row] ? std::to_string(
//                a[lvl][row]->val) : "n") << std::endl;
//        counter++;
//    }
}

void BinTree::count_even() {
    int c_e_r = 0, c_e_l = 0;
    if (this->left){
        c_e_l += this->left->even();
    }
    if (this->right){
        c_e_r += this->right->even();
    }
    if (c_e_r > c_e_l) {
        std::cout << "right: " << c_e_r << std::endl;
    } else if (c_e_r < c_e_l) {
        std::cout << "left: " << c_e_l << std::endl;
    } else {
        std::cout << "equality: " << c_e_l << std::endl;
    }
}

int BinTree::even(){
    int count = 0;
    if (this->val % 2 == 0){
        count += 1;
    }
    if (this->left){
        count += this->left->even();
    }
    if (this->right){
        count += this->right->even();
    }
    return count;
}


void BinTree::new_element(int n){
    std::queue<BinTree *> q;
    q.push(this);
    while (!q.empty()){
        BinTree* tmp = q.front();
        q.pop();
        if (tmp){
            q.push(tmp->left);
            q.push(tmp->right);
        }
        if (!tmp->left){
            tmp->left = new BinTree(n);
            break;
        }
        if (!tmp->right){
            tmp->right = new BinTree(n);
            break;
        }

    }
}