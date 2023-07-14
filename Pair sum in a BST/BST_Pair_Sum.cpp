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

int Number_of_Nodes(BinaryTree<int>* root){
    if(root==NULL){
        return 0;
    }

    return 1+Number_of_Nodes(root->left)+Number_of_Nodes(root->right);
}

void Just_Greater(BinaryTree<int>* root, stack<BinaryTree<int>*> &s1){
    if(root->left==NULL){
        s1.push(root);
        return;
    }
    s1.push(root);
    Just_Greater(root->left,s1);
    return;
}

void Just_Smaller(BinaryTree<int>* root, stack<BinaryTree<int>*> &s2){
    if(root->right==NULL){
        s2.push(root);
        return;
    }
    s2.push(root);
    Just_Smaller(root->right,s2);
    return;
}

int main(){
    BinaryTree<int>* root = takeInput();
    cout<<"Enter your sum: "<<endl;
    int sum;
    cin>>sum;
    stack<BinaryTree<int>*> s1;
    stack<BinaryTree<int>*> s2;
    int n=Number_of_Nodes(root);

    Just_Greater(root,s1);
    Just_Smaller(root,s2);
    while(n>0){
        int tempsum=s1.top()->data + s2.top()->data;
        if(tempsum>sum){
            if(s2.top()->left!=NULL){
                BinaryTree<int>* temp = s2.top();
                s2.pop();
                Just_Smaller(temp->left,s2);
            }
            else{
                s2.pop();
            }
            n--;
        }
        else if(tempsum<sum){
            if(s1.top()->right!=NULL){
                BinaryTree<int>* temp = s1.top();
                s1.pop();
                Just_Greater(temp->right,s1);
            }
            else{
                s1.pop();
            }
            n--;
        }
        else if(tempsum==sum ){
            if(s1.top()->data != s2.top()->data){
                cout<<s1.top()->data<<" "<<s2.top()->data<<endl;
            } 
            if(s2.top()->left!=NULL){
                BinaryTree<int>* temp = s2.top();
                s2.pop();
                Just_Smaller(temp->left,s2);
            }
            else{
                s2.pop();
            }

            if(s1.top()->right!=NULL){
                BinaryTree<int>* temp = s1.top();
                s1.pop();
                Just_Greater(temp->right,s1);
            }
            else{
                s1.pop();
            }
            n--;
            n--;
        }
    } 
}

// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1