#include<iostream>
#include<queue>
#include"BinaryTree_Node_Class.cpp"
using namespace std;

struct Node{
    int val;
    Node* next;
    
    Node(int n){
        val=n;
        next=NULL;
    }
};

struct returner{
    Node* head;
    Node* tail;

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

returner BST_LL(BinaryTree<int>* root){
    if(root==NULL){
        returner r;
        r.head=NULL;
        r.tail=NULL;
        return r;
    }

    returner left = BST_LL(root->left);
    returner right = BST_LL(root->right);
    if(root!=NULL){
        cout<<"root is currently: "<<root->data<<endl;
    }
    returner rfinal;
    if(left.head==NULL){
        int rd=root->data;
         Node* temp = new Node(rd);
         rfinal.head = temp;
         rfinal.tail=temp;
         //rfinal.tail=rfinal.head;
    }
    else{
        left.tail->next = new Node(root->data);
        left.tail=left.tail->next;
        rfinal.head=left.head;
        rfinal.tail=left.tail;
        //left.tail->next=right.head;
    }

    if(right.head!=NULL){
        rfinal.tail->next=right.head;
        rfinal.tail=right.tail;
    }
    
    return rfinal;
}

int main(){
    BinaryTree<int>* root = takeInput();
    returner res = BST_LL(root);
    if(res.head==NULL){
        cout<<"Null returned"<<endl;
    }
    while(res.head!=NULL){
        cout<<res.head->val<<" "; 
        res.head=res.head->next;
    }
}
