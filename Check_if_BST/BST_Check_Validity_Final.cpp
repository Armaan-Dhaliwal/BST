#include<iostream>
#include<queue>
#include<limits.h>
#include"BinaryTree_Node_Class.cpp"
using namespace std;
    
bool CheckBST(BinaryTree<int>* root,BinaryTree<int>* max=NULL,BinaryTree<int>* min=NULL){
    if(root==NULL){
        return true;
    }

    if(min!=NULL && root->data<=min->data){
        return false;
    }
    if(max!=NULL && root->data>=max->data){
        return false;
    }

    
        bool res1= CheckBST(root->left,root,min);
        bool res2= CheckBST(root->right,max,root);
        return res1&&res2;
}


    bool isValidBST(BinaryTree<int>* root) {
        if(root==NULL){
            return true;
        }

        return CheckBST(root);
    }