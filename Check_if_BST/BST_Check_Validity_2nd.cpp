#include<iostream>
#include<queue>
#include<limits.h>
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

bool CheckBST(BinaryTree<int>* root, int max, int min){
    if(root==NULL){
        return true;
    }

    if(root->data>max || root->data<min){
        return false;
    }
        int minimum=root->data+1;
        int maximum=root->data-1;
        return CheckBST(root->left,maximum,min) && CheckBST(root->right,max,minimum);
}

int main(){
    BinaryTree<int>* root = takeInput();
    bool res = CheckBST(root,INT_MAX,INT_MIN);
    cout<<res<<endl;
}
