#include<iostream>
#include<queue>
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

void Summer(BinaryTree<int>* root, int &sum){
    if(root==NULL){
        return ;
    }

    if(root->right!=NULL){
        Summer(root->right,sum);
    }
    root->data+=sum;
    sum=root->data;
    Summer(root->left,sum);
    return;
}


void PrintLevel(BinaryTree<int>* root){
    queue<BinaryTree<int>*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        while(size>0){
            if(q.front()->left!=NULL){
                q.push(q.front()->left);
            }
            if(q.front()->right!=NULL){
                q.push(q.front()->right);
            }
            cout<<q.front()->data<<" ";
            q.pop();
            size--;
        }
        cout<<endl;
    }
}


int main(){
    BinaryTree<int>* root = takeInput();
    int sum=0;
    Summer(root,sum);
    PrintLevel(root);
    delete root;
}
