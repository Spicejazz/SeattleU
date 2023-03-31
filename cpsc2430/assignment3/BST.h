#ifndef BST_H
#define BST_H

#include <iostream>

using namespace std;

class BST{
public:
    BST(){
        root = nullptr;
    }
    void insertNode(int x){
        root = insert(root, x);
    }
    void inorderDisplay(){
        inorder(root);
        cout << endl;
    }
    void preorderDisplay(){
        preorder(root);
        cout << endl;
    }
    void postorderDisplay(){
        postorder(root);
        cout << endl;
    }
    void searchDisplay(int x){
        if(search(x, root)){
            cout << "true" << endl;
        } else{
            cout << "false" << endl;
        }
    }
    void displayAncestor(int x){
       findAncestor(x, root, root);
    }
    void displayPredecessor(int x){
        int temp = findPredecessor(x, root,root);
        cout << temp << endl;
    }
    void displayHeight(){
        cout << height(root) << endl;
    }
    void displayTotalNodes(){
        cout << numNodes(root) << endl;
    }
    void destroyNode(int x){
        deleteNode(x, root);
    }
    void balanceCheck(){
        if(balanced(root)){
            cout << "true" << endl;
        } else{
            cout << "false" << endl;
        }
    }
    void destroyTree(){
        deleteTree(root);
        cout << "Tree has been deleted" << endl;
    }
private:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x){
            val = x;
            left = nullptr;
            right = nullptr;
        }
    };
    TreeNode* root;
    
    TreeNode* insert(TreeNode*, int);
    void inorder(TreeNode*);
    void preorder(TreeNode*);
    void postorder(TreeNode*);
    bool search(int, TreeNode*);
    void findAncestor(int, TreeNode*,TreeNode*);
    int findPredecessor(int, TreeNode*,TreeNode*);
    int height(TreeNode*);
    int numNodes(TreeNode*);
    TreeNode* deleteNode(int, TreeNode*);
    bool balanced(TreeNode*);
    void deleteTree(TreeNode*&);
};

#endif