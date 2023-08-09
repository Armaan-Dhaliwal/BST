#include<iostream>
#include<vector>
using namespace std;

struct Node
{
	int data;
	Node* left, *right;

    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

void inTransversal(Node* root, vector<int> &inorder){
    if(root==NULL){
        return;
    }
    
    inTransversal(root->left,inorder);
    inorder.push_back(root->data);
    inTransversal(root->right,inorder);
}

Node* helper(vector<int> inorder, int si, int ei){
    if(si>ei){
        return NULL;
    }
    int mid = (si+ei)/2;
    Node* root = new Node(inorder[mid]);
    root->left = helper(inorder,si,mid-1);
    root->right = helper(inorder,mid+1,ei);
    return root;
}

Node* buildBalancedTree(Node* root)
{
    vector<int> inorder;
    inTransversal(root,inorder);
    Node* newRoot = helper(inorder,0,inorder.size()-1);
    return newRoot;
}