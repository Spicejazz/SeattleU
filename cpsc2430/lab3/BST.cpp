#ifndef BST_CPP
#define BST_CPP

#include "BST.h"

BST::TreeNode* BST::insert(TreeNode* t, int x){
    if (t == nullptr){
        return new TreeNode(x);
    }
    
    if (x > t->val){
        t->right = insert(t->right, x);
    } else if(x < t->val){
        t->left = insert(t->left, x);
    }
    return t;
}

void BST::inorder(TreeNode* t){
    if(t == nullptr){
        return;
    }
    inorder(t->left);
    cout << t->val << " ";
    inorder(t->right);
}

void BST::preorder(TreeNode* t){
    if (t == nullptr){
        return;
    }
    cout << t->val << " ";
    preorder(t->left);
    preorder(t->right);
}

void BST::postorder(TreeNode* t){
    if (t == nullptr){
        return;
    }
    postorder(t->left);
    postorder(t->right);
    cout << t->val << " ";
}

#endif