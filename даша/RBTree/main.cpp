#include <iostream>
#include "RBTree.h"
#include "BFTree.h"
#include "Hash_t.h"
#include "BinFile.h"
#include "Graph.h"
#include <chrono>
using namespace std::chrono;

void task_1();

void task_2();

void task_3();

int main() {
    setlocale(0, "");
    Graph a;
    bool activate = true;
    std::cout << "Выберите операцию: \n";
    std::cout << "1. Ввести ориентированный граф\n";
    std::cout << "2. Вывести ориентированный граф\n";
    std::cout << "3. Ввести неориентированный граф\n";
    std::cout << "4. Вывести неориентированный граф\n";
    std::cout << "5. Вставить ребро в граф\n";
    std::cout << "6. Вывести все пути в ориентированном графе от вашей вершины\n";
    std::cout << "7. Использовать метод Флойда для ориентированного графа\n";

    while (activate) {
        int condition;
        std::cout << "Введите номер операции: ";
        std::cin >> condition;
        switch (condition) {
            case 1: {
                a.input(1);
                break;
            }
            case 2: {
                a.output(1);
                break;
            }
            case 3: {
                a.input(0);
                break;
            }
            case 4: {
                a.output(0);
                break;
            }
            case 5: {
                std::cout << "Введите начало, конец и стоимость ребра: ";
                int startVertex, endVertex, value;
                std::cin >> startVertex >> endVertex >> value;
                a.insertEdge(startVertex, endVertex, value);
                break;
            };
            case 6: {
                std::cout << "Введите номер вершины: ";
                int vertex;
                std::cin >> vertex;
                a.pathOutput(vertex);
                break;
            }
            case 7: {
                a.floyd();
                a.output(1);
                break;
            }
        }
        std::cout << "Желаете продолжить?\n";
        std::cin >> activate;
    }

    return 0;
}





void task_2(){
    BinFile b_f;
    BFTree b_f_t;
    std::cout << "Выберите операцию и введите ее номер\n";
    std::cout << "1. Создать новый бинарный файл\n";
    std::cout << "2. Заполнить бинарное дерево поиска\n";
    std::cout << "3. Найти элемент в бинарном дереве поиска\n";
    std::cout << "4. Удалить элемент из бинарного дерева поиска и бинарного файла \n";
    std::cout << "5. Вывести бинарный файл\n";
    std::cout << "6. Вывести бинарное дерево поиска\n";
    std::cout << "7. Поменять структуру\n";
    int condition_2;
    bool activate_2 = true;
    while (activate_2){
        std::cout << "Command: ";
        std::cin >> condition_2;
        if (condition_2 == 7) {
            condition_2 = 0;
            break;
        }
        switch (condition_2) {
            case 1: {
                int n_2;
                std::cout << "Enter the number of entries in the file: ";
                std::cin >> n_2;
                b_f.bin_input(n_2);
                std::cout << "The binary file has been updated\n";
                break;
            }
            case 2: {
                b_f_t.input();
                std::cout << "Tree created\n";
                break;
            }
            case 3: {
                int k_2;
                std::cout << "\ninput key\n";
                std::cin >> k_2;
                high_resolution_clock::time_point t1 = high_resolution_clock::now();

                BFNode* s_2 = b_f_t.search(k_2);

                high_resolution_clock::time_point t2 = high_resolution_clock::now();
                auto duration = duration_cast<nanoseconds>(t2 - t1).count();
                if (s_2) {
                    std::cout << "Key found: ";
                    b_f.bin_output_string(s_2->val);
                    std::cout << "countCompare " << b_f_t.countCompare << std::endl;
                } else {
                    std::cout << "Element not found\n";
                }
                std::cout << "time: " << duration << "nn\n";
                break;
            }
            case 4: {
                int k_2_1;
                std::cout << "\ninput key\n";
                std::cin >> k_2_1;
                BFNode* s_2_1 = b_f_t.search(k_2_1);
                if (s_2_1) {
                    std::cout << "Deletion completed\n";
                    b_f.bin_delete(s_2_1->val);
                    b_f_t.remove(k_2_1);
                } else {
                    std::cout << "Deletion failed, element not found\n";
                }
                break;
            }
            case 5: {
                std::cout << "\nBinary file\n";
                b_f.bin_output();
                break;
            }
            case 6: {
                std::cout << "\nBin tree\n";
                b_f_t.print();
                break;
            }
        }
        std::cout << "Would you like to continue Yes - 1, No - 0: ";
        std::cin >> activate_2;
    }
}

void task_3(){
    BinFile b_f;
    RBTree r_b_t;
    std::cout << "Выберите операцию и введите ее номер\n";
    std::cout << "1. Создать новый бинарный файл\n";
    std::cout << "2. Заполнить бинарное дерево поиска\n";
    std::cout << "3. Найти элемент в красно-черном дереве поиска\n";
    std::cout << "4. Удалить элемент из красно-черного дерева поиска и бинарного файла \n";
    std::cout << "5. Вывести бинарный файл\n";
    std::cout << "6. Вывести красно-черное дереве поиска\n";
    std::cout << "7. Поменять структуру\n";
    int condition_3;
    bool activate_3 = true;
    while (activate_3){
        std::cout << "Command: ";
        std::cin >> condition_3;
        if (condition_3 == 7) {
            condition_3 = 0;
            break;
        }
        switch (condition_3) {
            case 1: {
                int n_3;
                std::cout << "Enter the number of entries in the file: ";
                std::cin >> n_3;
                b_f.bin_input(n_3);
                std::cout << "The binary file has been updated\n";
                break;
            }
            case 2: {
                r_b_t.input();
                std::cout << "Tree created\n";
                std::cout << "midCount " << float(r_b_t.size) / r_b_t.countRotate << std::endl;
                break;
            }
            case 3: {
                int k_3;
                std::cout << "\ninput key\n";
                std::cin >> k_3;
                high_resolution_clock::time_point t1 = high_resolution_clock::now();
                RBNode* s_3 = r_b_t.search(k_3);
                high_resolution_clock::time_point t2 = high_resolution_clock::now();
                auto duration = duration_cast<nanoseconds>(t2 - t1).count();
                if (s_3) {
                    std::cout << "Key found: ";
                    b_f.bin_output_string(s_3->val);

                    std::cout << "countCompare " << r_b_t.countCompare << std::endl;
                } else {
                    std::cout << "Element not found\n";
                }
                std::cout << "time: " << duration << "nn\n";
                break;
            }

            case 4: {
                int k_3_1;
                std::cout << "\ninput key\n";
                std::cin >> k_3_1;
                RBNode* s_3_1 = r_b_t.search(k_3_1);
                if (s_3_1) {
                    std::cout << "Deletion completed\n";
                    b_f.bin_delete(s_3_1->val);
                    r_b_t.remove(k_3_1);
                } else {
                    std::cout << "Deletion failed, element not found\n";
                }
                break;
            }
            case 5: {
                std::cout << "\nBinary file\n";
                b_f.bin_output();
                break;
            }
            case 6: {
                std::cout << "\nBin tree\n";
                r_b_t.print();
                break;
            }
        }
        std::cout << "Would you like to continue Yes - 1, No - 0: ";
        std::cin >> activate_3;
    }
}