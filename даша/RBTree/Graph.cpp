//
// Created by Гусейнов Рамал on 20.11.2022.
//
#include "vector"
#include "Graph.h"
#include "iostream"

void Graph::input(int style) {
    std::cout << "Enter the dimension of the matrix" << std::endl;
    std::cin >> n;
    size = n;
    int **matrix = new int *[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; ++j) {
            std::cin >> matrix[i][j];
        }
    }
    if (style)
        matrixToGraph(matrix);
    else
        undirectedGraph(matrix);
}

void Graph::matrixToGraph(int **&matrix) {
    h_table = new node *[n]{};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] && matrix[i][j] != 10000) {
                node *tmp = new node;
                if (h_table[i]) {
                    tmp->next = h_table[i];
                }
                tmp->key = j;
                tmp->num = matrix[i][j];
                h_table[i] = tmp;
            }
        }
    }
}

void Graph::output(int o) {
    char a = (o ? '>' : '-');
    std::cout << (o ? "Digraph {" : "Graph {") << '\n';
    std::cout << "    node [shape = circle];" << '\n';
    for (int i = 0; i < size; ++i) {
        node *tmp = h_table[i];
        while (tmp) {
            std::cout << "    \"" << i << "\" -" << a << " \"" << tmp->key << "\"[label=" << tmp->num << "];" << '\n';
            tmp = tmp->next;
        }
    }
    std::cout << "}" << '\n';
}




void Graph::pathOutput(int vertex) {
    std::vector<int> listOfVertex;
    std::vector<bool> visited(size, 0);
    char ident = 'A';
    std::cout << "Digraph {\n";
    pathOutput(vertex, listOfVertex, ident, visited);
    std::cout << "}\n";
}

void Graph::pathOutput(int vertex, std::vector<int> &listOfVertex, char &ident, std::vector<bool> &visited) {
    node *tmp = h_table[vertex];
    listOfVertex.push_back(vertex);
    if (!tmp || visited[vertex]) {
        std::cout << "  subgraph " << ident << " {\n";
        for (int i = 0; i < listOfVertex.size() - 1 - visited[vertex]; ++i){
            std::cout << "    \"" << ident << listOfVertex[i] << "\" -> \"" << ident << listOfVertex[i + 1] << "\";" << '\n';
        }
        std::cout << "  }\n";
        ident++;
    }
    visited[vertex] = true;
    while (tmp) {
        pathOutput(tmp->key, listOfVertex, ident, visited);
        tmp = tmp->next;
    }
    visited[vertex] = false;
    listOfVertex.pop_back();
}

void Graph::floyd(){
    int** matrix = new int*[size];
    for (int i = 0; i < size; ++i) {
        matrix[i] = new int[size];
        node* tmp = h_table[i];
        while (tmp){
            matrix[i][tmp->key] = tmp->num;
            tmp = tmp->next;
        }
        for (int j = 0; j < size; ++j){
            if (!matrix[i][j]) {
                matrix[i][j] = 10000;
            }
        }
    }
    for (int i = 0; i < size; ++i){
        for (int u = 0; u < size; ++u){
            for (int v = 0; v < size; ++v){
                if (matrix[u][i] + matrix[i][v] < matrix[u][v]) {
                    matrix[u][v] = matrix[u][i] + matrix[i][v];
                }
            }
        }
    }
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j){
            std::cout << matrix[i][j] << "    ";
        }
        std::cout << '\n';
    }
    matrixToGraph(matrix);
}

void Graph::undirectedGraph(int** &matrix) {
    h_table = new node *[n]{};
    for (int i = 0; i < size; ++i){
        for (int j = i; j < size; ++j){
            if (matrix[i][j] && matrix[i][j] != 10000) {
                node *tmp = new node;
                if (h_table[i]) {
                    tmp->next = h_table[i];
                }
                tmp->key = j;
                tmp->num = matrix[i][j];
                h_table[i] = tmp;
            }
        }
    }
}

void Graph::insertEdge(int startVertex, int endVertex, int value) {
    node *tmp = new node;
    if (h_table[startVertex]) {
        tmp->next = h_table[startVertex];
    }
    tmp->key = endVertex;
    tmp->num = value;
    h_table[startVertex] = tmp;
}

