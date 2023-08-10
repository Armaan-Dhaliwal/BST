#include<iostream>
#include<vector>
using namespace std;

struct Node{
        int data;
        Node* left;
        Node* right;
        
        Node(int data){
            this->data = data;
            left=right=NULL;
        }
    };
    
    Node* insert(Node* root, int data, int &suc){
        if(!root){
            Node* newNode = new Node(data);
            return newNode;
        }
        
        if(data<root->data){
            suc=root->data;
            root->left = insert(root->left, data,suc);
        }
        
        else{
            root->right = insert(root->right,data,suc);
        }
        return root;
    }
    
    vector<int> findLeastGreater(vector<int>& arr, int n) {
    Node* root = NULL;
    for(int i=arr.size()-1;i>=0;i--){
        int suc=-1;
        root = insert(root,arr[i],suc);
        arr[i]=suc;
    }
        return arr;
    }