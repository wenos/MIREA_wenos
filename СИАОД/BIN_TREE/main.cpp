#include <iostream>
#include "BinTree.h"
#include <ctime>

int main() {
    BinTree tree;
    BinTree tree_1;
    bool reactor = 1;
    std::cout << "Select operation:" << std::endl;
    std::cout << "1. Create a binary tree yourself" << std::endl;
    std::cout << "2. Create a binary tree" << std::endl;
    std::cout << "3. Create a binary tree with random" << std::endl;
    std::cout << "4. Output a binary tree (not by option)" << std::endl;
    std::cout << "5. Output an inverted binary tree" << std::endl;
    std::cout << "6. Insert element into binary tree" << std::endl;
    std::cout << "7. Find out which subtree has more even numbers" << std::endl;
    std::cout << "8. Create a copy of the binary tree" << std::endl;
    std::cout << "9. Output a copy of the binary tree (not by option)" << std::endl;
    while (reactor){
        int condition;
        int n;
        std::cin >> condition;
        switch (condition) {
            case 1: {
                std::cout << "Input enter the number of elements: ";
                std::cin >> n;
                std::cout << "Enter tree elements:" << std::endl;
                tree.fill_input(n);
                std::cout << "Tree completed successfully" << std::endl;
                break;
            }
            case 2: {
                std::cout << "Input enter the number of elements: ";
                std::cin >> n;
                int* a = new int[n];
                for (int i = 1; i < n + 1; ++i){
                    a[i - 1] = i;
                }
                tree.fill_arr(a, 0, n - 1);
                std::cout << "Tree completed successfully" << std::endl;
                break;
            }
            case 3: {
                srand(time(0));
                std::cout << "Input enter the number of elements: ";
                std::cin >> n;
                tree.fill_random(n);
                std::cout << "Tree completed successfully" << std::endl;
                break;
            }
            case 4: {
                std::cout << "The binary tree: " << std::endl;
                tree.out_queue();
                break;
            }
            case 5: {
                std::cout << "The binary tree: " << std::endl;
                tree.out_right_left(tree.height());
                break;
            }
            case 6: {
                std::cout << "Input enter the element: " << std::endl;
                std::cin >> n;
                tree.new_element(n);
                std::cout << "Item added successfully" << std::endl;
                break;
            }
            case 7: {
                tree.count_even();
                break;
            }
            case 8: {
                tree_1 = BinTree(tree);
                std::cout << "Tree copy create" << std::endl;
                break;
            }
            case 9: {
                std::cout << "Copy of the binary tree: " << std::endl;
                tree_1.out_queue();
                break;
            }
        }
        std::cout << "Would you like to continue? 1 --- yes, 0 --- no: ";
        std::cin >> reactor;
    }
    return 0;
}
