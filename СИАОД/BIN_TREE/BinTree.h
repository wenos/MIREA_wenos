//
// Created by Гусейнов Рамал on 28.10.2022.
//

#ifndef BIN_TREE_BINTREE_H
#define BIN_TREE_BINTREE_H


class BinTree {
private:
    int val;
    BinTree* right = nullptr;
    BinTree* left = nullptr;
public:
    void fill_arr(int*, int, int);
    void fill_input(int);
    void fill_random(int);
    void out_queue();
    void out_vector();
    void out_right_left(int h, int lvl=0);
    void count_even();
    void new_element(int n);
    int height();
    int even();
    BinTree(int);
    BinTree();
    BinTree(BinTree* &);
};


#endif //BIN_TREE_BINTREE_H
