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

BinaryTree<int>* LCAfinder(BinaryTree<int>* root,int n1, int n2){
    if(root==NULL){
        return NULL;
    }

    if(n2<=root->data && root->data<=n1){
        return root;
    }

    BinaryTree<int>* temp = new BinaryTree<int>(-1);
    if(root->data>n1){
        temp=LCAfinder(root->left,n1,n2);
    }
    if(temp!=NULL && root->data<n2){
        temp=LCAfinder(root->right,n1,n2); 
    }
    return temp;

}

bool hasX(BinaryTree<int>* root,int x){
    if(root==NULL){
        return false;
    }

    if(root->data==x){
        return true;
    }

    return hasX(root->left,x)||hasX(root->right,x);
}

int main(){
    BinaryTree<int>* root = takeInput();
    cout<<"Enter your nodes: "<<endl;
    int node1,node2;
    cin>>node1>>node2;
    BinaryTree<int>* LCA;
    if(hasX(root, node1) && !hasX(root,node2)){
        LCA = new BinaryTree<int>(node1);
    }
    if(!hasX(root,node1) && hasX(root,node2)){
         LCA = new BinaryTree<int>(node2);
    }
    if(!hasX(root,node1) && !hasX(root,node2)){
         LCA = new BinaryTree<int>(-1);
    }
    
    int n1,n2;
    n1 =max(node1,node2);
    n2=min(node1,node2);
    if(hasX(root,node1) && hasX(root,node2)){
        LCA=LCAfinder(root,n1,n2);
    }

    cout<<LCA->data<<endl;
    
    delete root;
}

//6 5 8 2 -1 7 10 -1 -1 -1 -1 -1 -1