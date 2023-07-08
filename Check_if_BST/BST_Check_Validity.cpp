#include<iostream>
#include<queue>
#include<limits.h>
#include"BinaryTree_Node_Class.cpp"
using namespace std;
 
class returner{
    public:
    int min;
    int max;
    bool isBST;
};

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

returner CheckBST(BinaryTree<int>* root){
    if(root==NULL){
        returner r;
        r.isBST=true;
        r.max=INT_MIN;
        r.min=INT_MAX;
        return r;
    }
    returner rl=CheckBST(root->left);
    returner rr=CheckBST(root->right);
    returner rfinal;
    if(rl.isBST && rr.isBST &&  root->data<rr.min && root->data>rl.max){
        rfinal.isBST= true;
        rfinal.min = min(rl.min,min(root->data,rr.min));
        rfinal.max = max(rl.max,max(root->data,rr.max));
    }
    else{
        rfinal.isBST=false;
    }
    return rfinal;
}

int main(){
    BinaryTree<int>* root = takeInput();
    returner res= CheckBST(root);
    cout<<res.isBST<<endl;
}
