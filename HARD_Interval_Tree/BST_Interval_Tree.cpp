#include<iostream>
#include<vector>
#include<climits>
using namespace std;

struct TreeNode{
    int l;
    int h;
    int max;
    TreeNode* left;
    TreeNode* right;


    TreeNode(int l,int h){
        this->l = l;
        this->h = h;
        max=h;
        left=NULL;
        right=NULL;
    }
};

void printTree(TreeNode* root){
    if(root==NULL){
        return;
    }

    printTree(root->left);
    cout<<"["<<root->l<<","<<root->h<<"]"<<" max :"<<root->max<<endl;
    printTree(root->right);
}

TreeNode* insert(TreeNode* root, int l ,int h){
    if(root==NULL){
        TreeNode* temp = new TreeNode(l,h);
        return temp;
    }

    if(l<root->l){
        if(h>root->max){
            root->max=h;
        }
        root->left = insert(root->left,l,h);
    }
    else if(l>root->l){
        if(h>root->max){
            root->max=h;
        }
        root->right=insert(root->right,l,h);
    }

    return root;
}

pair<int,int> coincides(TreeNode* root, int l, int h){
    if(root==NULL){
        return {-1,-1};
    }

    if(l<root->h && h>root->l){
        return {root->l,root->h};
    }

    if (root->left && l<root->left->max)
    {
        return coincides(root->left,l,h);
    }

    return coincides(root->right,l,h);
    
}

int main(){
    vector<vector<int>> vec;
    cout<<"Enter your queries with l and h: "<<endl;
    int l,h;
    cin>>l>>h;
    TreeNode* root = new TreeNode(l,h);
    cin>>l>>h;
    while( l!=-1 && h!=-1){
        pair<int,int> p=coincides(root,l,h);
        if(p.first!=-1){
            cout<<l<<","<<h<<" coincides with: ";
            cout<<p.first<<","<<p.second<<endl;
        }
        root = insert(root,l,h);
        cin>>l>>h;
    }

    //printTree(root);

    // cout<<"Enter coincidence test: "<<endl;
    // cin>>l>>h;
    // pair<int,int> p=coincides(root,l,h);
    // cout<<l<<","<<h<<"coincides with: ";
    // cout<<p.first<<" "<<p.second<<endl;
}

/*
    15 20 10 30 17 19 5 20 12 15 30 40 -1 -1 
*/

/*
    1 5 3 7 2 6 10 15 5 6 4 100 -1 -1 
*/