#include<iostream>
#include<queue>
#include<limits.h>
#include<stack>
#include"BinaryTree_Node_Class.cpp"
using namespace std;

BinaryTree<int>* takeInput(){
    cout<<"enter root data "<<endl;
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    queue<BinaryTree<int>*> q;
    BinaryTree<int>* root=new BinaryTree<int>(data);
     q.push(root);

    while(!q.empty()){
        cout<<"Enter left data for "<<q.front()->data<<endl;
        int data;
        cin>>data;
        if(data!=-1){
             BinaryTree<int>* node1 = new BinaryTree<int>(data);
            q.front()->left=node1;
            q.push(q.front()->left);
        }

        cout<<"Enter right data for "<<q.front()->data<<endl;
        cin>>data;
        if(data!=-1){
            BinaryTree<int>* node2 = new BinaryTree<int>(data);
            q.front()->right=node2;
            q.push(q.front()->right);
        }
        q.pop();
    }
    
    return root;
}



bool Limit_Checker(BinaryTree<int>* root,int Min=1, int Max=INT_MAX){
        
        if(root==NULL){
            return false;
        }
        
        if(Min==Max){
            return true;
        }

        return Limit_Checker(root->left,Min,root->data-1) || Limit_Checker(root->right,root->data+1,Max);
}

bool isDeadEnd(BinaryTree<int> *root)
{   

    if(root==NULL){
        return false;
    }
    return Limit_Checker(root);
}

int main(){
    BinaryTree<int>* root=takeInput();
    cout<<isDeadEnd(root)<<endl;
}

//74 17 92 -1 70 83 94 22 -1 -1 -1 -1 120 -1 -1 -1 -1