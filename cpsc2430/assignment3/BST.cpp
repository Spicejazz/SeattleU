#ifndef BST_CPP
#define BST_CPP

#include "BST.h"

BST::TreeNode* BST::insert(TreeNode* t, int x){ //done
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

void BST::inorder(TreeNode* t){ //done
    if(t == nullptr){
        return;
    }
    inorder(t->left);
    cout << t->val << " ";
    inorder(t->right);
}

void BST::preorder(TreeNode* t){ //done
    if (t == nullptr){
        return;
    }
    cout << t->val << " ";
    preorder(t->left);
    preorder(t->right);
}

void BST::postorder(TreeNode* t){ //done
    if (t == nullptr){
        return;
    }
    postorder(t->left);
    postorder(t->right);
    cout << t->val << " ";
}

bool BST::search(int x, TreeNode* t){ //done 
    if (t == nullptr){ //base case
        return false;
    } else if (t->val == x){ //case for when val is found
        return true;
    }
    if (x > t->val){ //searches to the right if greater
        return search(x, t->right);
    } else{ //searches to the left if less
        return search(x, t->left);
    }
}

void BST::findAncestor(int x, TreeNode* ancestor, TreeNode* t){ //done
    if (t == nullptr){ //base case
        return;
    }
    if (t->val == x){ //find val, use "slow" value as that is always t's parent node
        cout << ancestor->val << endl;
    }
    if (x > t->val) //search for node with val x, keeping ancestor as the last touched node
    {
        ancestor = t;
        return findAncestor(x, ancestor, t->right);
    } else{
        ancestor = t;
        return findAncestor(x, ancestor, t->left);
    }
}

int BST::findPredecessor(int x, TreeNode* pre, TreeNode* t){ //needs work
    if (t == nullptr)
    {
        return -1;
    }
    if (t->val == x)
    {
        //tries to traverse left subtree's right edges. Does not work
        pre = pre->left;
        while (pre->right)
        {
            pre = pre->right;
        }
        cout << pre->val;
    }
    if (x > t->val){
        pre = t;
        return findPredecessor(x, pre, t->right);
    } else {
        pre = t;
        return findPredecessor(x, pre, t->left);
    }
    //tried to apply same logic as findAncestor, but it doesn't seem to be working
}

int BST::height(TreeNode* t){ //done
    if (t == nullptr){
        return 0;
    }
    else{
        //adds up height of both left and right subtrees
        int lHeight = height(t->left);
        int rHeight = height(t->right);

        if (lHeight > rHeight){ //compares height and adds 1
            return (lHeight + 1);
        } else{
            return (rHeight + 1);
        }
    }
    
}

int BST::numNodes(TreeNode* t){ //done
    if(t == nullptr){
        return 0;
    }
    //traverse tree, traverses all subtrees and adds 1 until hitting leaf nodes
    return 1 + numNodes(t->left) + numNodes(t->right);
}

BST::TreeNode* BST::deleteNode(int x, TreeNode* t){ //done
    if (t == nullptr){ //base case
        return nullptr;
    }

    if (x < t->val){//find node to be deleted
        t->left = deleteNode(x, t->left);
    } else if (x > t->val){
        t->right = deleteNode(x, t->right);
    } else{ //t->val == x
        if (t->left == nullptr && t->right == nullptr){ //check for no children
            return nullptr;
        } else if (t->left == nullptr){ //1 right child case
            TreeNode* temp = t->right;
            delete t;
            return temp;
        } else if (t->right == nullptr){
            TreeNode* temp = t->left;
            delete t;
            return temp;
        }
        //node with 2 children, get successor
        TreeNode* temp = t;
        while (temp && temp->left != nullptr){
            temp = temp->left;
        }
        
        //copy successor's val
        t->val = temp->val;

        //delete the successor after switching
        t->right = deleteNode(temp->val, t->right);
    }
    return t;   
}

bool BST::balanced(TreeNode* t){ //done
    int lHeight;
    int rHeight;

    if (t == nullptr){
        return true;
    }
    lHeight = height(t->left);
    rHeight = height(t->right);
    //compares heights of both trees, as long as it isn't greater than 1 it's balanced
    if(abs(lHeight - rHeight) <= 1){
        return true;
    }
    return false;
}

void BST::deleteTree(TreeNode*& t){ //needs work
    if (t)
    {
        deleteTree(t->left);
        deleteTree(t->right);
        delete t; //currently leaves garbage left over values, not sure why
    }
}

#endif