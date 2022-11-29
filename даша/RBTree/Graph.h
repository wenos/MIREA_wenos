//
// Created by Гусейнов Рамал on 20.11.2022.
//

#ifndef RBTREE_GRAPH_H
#define RBTREE_GRAPH_H

#include <vector>
#include "Hash_t.h"

class Graph: Hash_t {
private:
    int n{};
    void matrixToGraph(int** &matrix);
public:
    void input(int style);
    Graph() = default;
    void output(int style);
    void pathOutput(int vertex, std::vector<int> &listOfVertex, char &ident, std::vector<bool> &visited);
    void pathOutput(int vertex);
    void floyd();
    void undirectedGraph(int** &matrix);
    void insertEdge(int startVertex, int endVertex, int value);
};


#endif //RBTREE_GRAPH_H
