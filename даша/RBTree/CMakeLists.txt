cmake_minimum_required(VERSION 3.23)
project(RBTree)

set(CMAKE_CXX_STANDARD 20)

add_executable(RBTree main.cpp RBNode.h RBTree.cpp RBTree.h BFTree.cpp BFTree.h Hash_t.cpp Hash_t.h BinFile.h Graph.cpp Graph.h)
