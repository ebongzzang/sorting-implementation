#include <iostream>
#include "tree/RbTree.h"

using namespace std;

int main(void) {
    int data[10] = {1, 2, 5, 4, 3, 6, 9, 8, 7, 10};
    RbTree rbTree1;

    for (int i = 0; i < (sizeof(data) / sizeof(int)); i++) {
        rbTree1.insertValue(data[i]);
    }

    rbTree1.inorder();

    std::cout << "\n\n\n" << std::endl;

    rbTree1.deleteValue(7);

    rbTree1.inorder();

    return 0;


}