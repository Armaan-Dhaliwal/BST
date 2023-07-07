#include<iostream>
#include<queue>
#include"BinaryTree_Node_Class.cpp"
using namespace std;
 

BinaryTree<int> * searchBST(BinaryTree<int> * root, int val) {
        if(root==NULL){
            return NULL;
        }

        if(root->data==val){
            return root;
        }
        if(root->data<val){
            root=searchBST(root->right,val);
        }
        else{
            root=searchBST(root->left,val);
        }
        return root;
    }