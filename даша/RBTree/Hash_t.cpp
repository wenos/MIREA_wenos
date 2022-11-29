//
// Created by Гусейнов Рамал on 13.11.2022.
//

#include "Hash_t.h"
#include <iostream>

Hash_t::Hash_t(int n) {
    h_table = new node *[n]{};
    size = n;
    real_size = 0;
}

int h(int key, int mod) {
    return key % mod;
}

bool Hash_t::delet(int key) {
    node *tmp = h_table[h(key, size)];
    if (tmp) {
        if (tmp->key == key) {
            h_table[h(key, size)] = h_table[h(key, size)]->next;
            --real_size;
            return 1;
        } else {
            node *prev = h_table[h(key, size)];
            while (tmp) {
                if (tmp->key == key) {
                    prev->next = tmp->next;
                    --real_size;
                    return 1;
                }
                prev = tmp;
                tmp = tmp->next;
            }
        }
    }
    return 0;
}

void Hash_t::add(int key, int num) {
    int res = h(key, size);
    node *tmp = new node;
    if (h_table[res]) {
        tmp->next = h_table[res];
    }
    tmp->key = key;
    tmp->num = num;
    h_table[res] = tmp;
    real_size++;
}

void Hash_t::output() {
    std::cout << "node [shape = circle];" << '\n';
    for (int i = 0; i < size; ++i) {
        node *tmp = h_table[i];
        while (tmp) {
            std::cout << "\"" << i << "\" -- \"" << tmp->key << "\"[label=" << tmp->num << "];" <<'\n';
            tmp = tmp->next;
        }
    }
}

void Hash_t::input() {
    std::ifstream fin("first.bin", std::ios::binary);
    int i = 0;
    note b{};
    while (fin.read((char *) &b, sizeof(note))) {
        add(b.num, i++);
        if (float(real_size) / size > 0.75) {
            rehash();
        }
    }
}

int Hash_t::find(int key) {
    node *tmp = h_table[h(key, size)];
    while (tmp) {
        countCoumpare++;
        if (tmp->key == key) {
            return tmp->num;
        }
        tmp = tmp->next;
    }
    return -1;
}

void Hash_t::rehash() {
    size *= 2;
    node **new_hash_table = new node *[size * 2]{};
    for (int i = 0; i < size / 2; ++i) {
        node *tmp = h_table[i];
        while (tmp) {
            int res = h(tmp->key, size);
            node *tmp_1 = new node;
            if (new_hash_table[res]) {
                tmp_1->next = new_hash_table[res];
            }
            tmp_1->key = tmp->key;
            tmp_1->num = tmp->num;
            new_hash_table[res] = tmp_1;
            tmp = tmp->next;
        }
    }
    h_table = new_hash_table;
}

