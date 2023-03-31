#ifndef ASSIGNMENT3_CPP
#define ASSIGNMENT3_CPP

#include "BST.h"

void switchHandler(int x, BST& t){
    int userChoice;
    switch (x){
    case 1:
        cout << "Please enter desired value" << endl;
        cin >> userChoice;
        t.insertNode(userChoice);
        break;
    case 2:
        cout << "Please enter desired value" << endl;
        cin >> userChoice;
        t.searchDisplay(userChoice);
        break;
    case 3:
        cout << "Please enter desired value" << endl;
        cin >> userChoice;
        t.displayAncestor(userChoice);
        break;
    case 4:
        cout << "Please enter desired value" << endl;
        cin >> userChoice;
        t.displayPredecessor(userChoice);
        break;
    case 5:
        t.displayHeight();
        break;
    case 6:
        t.displayTotalNodes();
        break;
    case 7:
        cout << "Please enter desired value" << endl;
        cin >> userChoice;
        t.destroyNode(userChoice);
        break;
    case 8:
        t.inorderDisplay();
        break;
    case 9:
        t.preorderDisplay();
        break;
    case 10:
        t.postorderDisplay();
        break;
    case 11:
        t.balanceCheck();
        break;
    case 12:
        t.destroyTree();
        break;
    default:
        return;
        break;
    }
}

int main(){
    int userChoice = 1;
    BST t;
    while(userChoice != 0){
        cout << "Welcome to my implementation of BST" << endl;
        cout << "Please choose the operation you want:" << endl;
        cout << "1. Insert a node" << endl;
        cout << "2. Search for a node" << endl;
        cout << "3. Find ancestor node" << endl;
        cout << "4. Find predecessor node" << endl;
        cout << "5. Find height of tree" << endl;
        cout << "6. Find num nodes in tree" << endl;
        cout << "7. Delete a node" << endl;
        cout << "8. Inorder Traversal" << endl;
        cout << "9. Preorder Traversal" << endl;
        cout << "10. Postorder Traversal" << endl;
        cout << "11. Balance Check" << endl;
        cout << "12. Destroy Tree" << endl;
        cout << "0. Exit" << endl;

        cin >> userChoice;

        switchHandler(userChoice, t);
    }
    return EXIT_SUCCESS;
}

#endif