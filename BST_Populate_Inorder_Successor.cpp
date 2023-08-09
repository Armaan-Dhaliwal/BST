#include<iostream>
#include<queue>
using namespace std;

 struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
 
 void inTransversal(Node* root, queue<Node*> &q){
        if(root==NULL){
            return;
        }
        
        inTransversal(root->left,q);
        q.push(root);
        inTransversal(root->right,q);
    }

    void populateNext(Node *root)
    {   
        queue<Node*> q;
        inTransversal(root,q); 
        int size=q.size();
        while(size!=1){
            Node* temp = q.front();
            q.pop();
            size--;
            temp->next=q.front();
        }
        
        q.front()->next=NULL;
    }