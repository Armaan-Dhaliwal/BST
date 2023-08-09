#include<iostream>
#include<queue>
#include<limits.h>
#include<stack>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
};

Node* newNode(int val)
{
	Node* temp = new Node;
	temp->data = val;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

void helper(Node* root, int l, int h, int &count){
        if(!root){
            return ;
        }
        
        if(root->data>=l && root->data<=h){
            count++;
        }
        
        if(root->data>=h){
            helper(root->left,l,h,count);
        }
        
        else if(root->data<=l){
            helper(root->right,l,h,count);
        }
        
        else{
            helper(root->left,l,h,count);
            helper(root->right,l,h,count);
        }
    }
    
    int getCount(Node *root, int l, int h)
    {
        int count=0;
      helper(root,l,h,count);
      return count;
    }