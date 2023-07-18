#include<iostream>
#include<queue>
#include<limits.h>
#include<stack>
#include"BinaryTree_Node_Class.cpp"
using namespace std;


int kLargest(BinaryTree<int> *root, int k, int &i){
        if(root==NULL){
            return -1;
        }
        
        int right = kLargest(root->right,k,i);
        if(right!=-1){
            return right;
        }
        
        i++;
        if(i==k){
            return root->data;
        }
        
        return kLargest(root->left,k,i);
    }
    
    int kthLargest(BinaryTree<int> *root, int K)
    {   

        int i=0;
        int ans=kLargest(root,K,i);
        return ans;
    }