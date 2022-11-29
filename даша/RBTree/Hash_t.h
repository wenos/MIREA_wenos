//
// Created by Гусейнов Рамал on 13.11.2022.
//

#ifndef RBTREE_HASH_T_H
#define RBTREE_HASH_T_H

#include <iostream>
#include <fstream>
#include <ctime>
#include "RBNode.h"

class Hash_t
{

protected:
    node** h_table;
    int size;
    int real_size;
    void output();

public:
    int countCoumpare = 0;
    Hash_t(int);
    Hash_t(){};
    void add(int, int);

    virtual void input();
    int find(int);
    bool delet(int);
    void rehash();
};

#endif //RBTREE_HASH_T_H
