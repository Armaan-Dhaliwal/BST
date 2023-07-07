#include<iostream>
#include<queue>
#include"BinaryTree_Node_Class.cpp"
using namespace std;
 
  void helper(BinaryTree<int>* root, int low, int high,vector<int> &res){
        if(root==NULL){
            return ;
        }
        
        
        if(root->data>low){
            helper(root->left,low,high,res);
        }
        
        if(low<=root->data &&  root->data<=high){
            res.push_back(root->data);
        } 
        
        if(root->data<high){
            helper(root->right,low,high,res);
        }
        
    }
  
    vector<int> printNearNodes(BinaryTree<int>* root, int low, int high) {
        vector<int> res;
        if(root==NULL){
            return res;
        }
        helper(root,low,high,res);
        return res;
    }