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
    }
    void preorderDisplay(){
        preorder(root);
    }
    void postorderDisplay(){
        postorder(root);
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
};

#endif