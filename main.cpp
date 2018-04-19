#include <iostream>
#include "tree/RbTree.h"

using namespace std;

int main(void) {
    int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    RbTree rbTree1;

    for (int i = 0; i < (sizeof(data) / sizeof(int)); i++) {
        rbTree1.insertValue(data[i]);
    }

    rbTree1.inorder();


    return 0;


}