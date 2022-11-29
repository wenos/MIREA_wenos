//
// Created by Гусейнов Рамал on 13.11.2022.
//

#ifndef RBTREE_BINFILE_H
#define RBTREE_BINFILE_H
#include <iostream>
#include <fstream>
#include "RBNode.h"

class BinFile {

public:
    void bin_delete(int num);
    void bin_input(int n);
    void bin_output_string(int num);
    void bin_output();
};

void BinFile::bin_delete(int num) {
    std::ifstream fin("first.bin", std::ios::binary);
    std::ofstream fout("second.bin", std::ios::binary);
    int i = 0;
    note a;
    while (fin.read((char *) &a, sizeof(note))) {
        if (i++ != num) {
            fout.write((char *) &a, sizeof(note));
        }
    }
    fin.close();
    fout.close();
    remove("first.bin");
    rename("second.bin", "first.bin");
}

void BinFile::bin_input(int n) {
    std::ofstream fout("first.bin", std::ios::binary);
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        note a;
        a.num = abs(rand() * RAND_MAX + rand());

        if (i == 0 || i == n - 1 || i == n / 2) {
            a.num = i;
        }
        a.code = rand() % 10000 + 1;

        for (int j = 0; j < 6; ++j) {
            a.fam[j] = char(rand() % 26 + 65);
        }
        a.fam[6] = '\0';
        fout.write((char*)&a, sizeof(note));
    }
    fout.close();
}

void BinFile::bin_output_string(int num) {
    std::ifstream fin("first.bin", std::ios::binary);
    note b;
    fin.seekg(num * sizeof(note), std::ios::beg);
    fin.read((char*)&b, sizeof(note));
    std::cout << b.num << " " << b.code << " " << b.fam << '\n';
    fin.close();
}

void BinFile::bin_output() {
    std::ifstream f("first.bin", std::ios::binary);
    int i = 0;
    note a;
    while (f.read((char*)&a, sizeof(note))) {
        std::cout << i++ << " " << a.num << " " << a.code << " " << a.fam << '\n';
    }
    f.close();
}


#endif //RBTREE_BINFILE_H


