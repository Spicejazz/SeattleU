#ifndef MAIN_CPP
#define MAIN_CPP

#include "BST.h"

int main(){
    BST test;
    test.insertNode(20);
    test.insertNode(21);
    test.insertNode(16);
    test.insertNode(25);
    test.insertNode(29);
    test.insertNode(15);
    test.insertNode(17);
    test.insertNode(12);
    test.insertNode(14);
    test.insertNode(101);

    test.inorderDisplay();
    cout << endl;
    test.preorderDisplay();
    cout << endl;
    test.postorderDisplay();
    cout << endl;

    return EXIT_SUCCESS;
}

#endif