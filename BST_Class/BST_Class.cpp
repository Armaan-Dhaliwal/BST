#include<iostream>
#include<queue>
#include<climits>
#include"BinaryTree_Node_Class.cpp"
using namespace std;
 
class BST{

    private:
    
    bool hasElement_helper(BinaryTree<int>* root, int x){
        if(root==NULL){
            return false;
        }  

        if(root->data==x){
            return true;
        }

        return hasElement_helper(root->left,x)||hasElement_helper(root->right,x);
    }

    BinaryTree<int>* Insert_helper(BinaryTree<int>* root,int x){
        if(root==NULL){
            BinaryTree<int>* temp= new BinaryTree<int>(x);
            return temp;
        }

        if(root->data<x){
            root->right=Insert_helper(root->right,x);
        }
        if(root->data>x){
            root->left=Insert_helper(root->left,x);
        }
        return root;
    }

    int MaxLeft(BinaryTree<int>* root){
        if(root==NULL){
            return INT_MIN;
        }

        return max(max(MaxLeft(root->left),MaxLeft(root->right)),root->data);
    }

    BinaryTree<int>* Delete(BinaryTree<int>* root, int x){
        if(root==NULL){
            return NULL;
        }

        if(root->data==x){
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            else if(root->left==NULL){
                BinaryTree<int>* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right==NULL){
                BinaryTree<int>* temp = root->left;
                delete root;
                return temp;
            }
            else{
                int maxLeft=MaxLeft(root->left);
                BinaryTree<int>* temp= new BinaryTree<int>(maxLeft);
                temp->right=root->right;
                Delete(maxLeft);
                delete root;
                return temp;
            }
        }

        if(root->data<x){
            root->right=Delete(root->right,x);
        }
        if(root->data>x){
            root->left=Delete(root->left,x);
        }
        return root;               

    }

    public:
    BinaryTree<int>* root;

    BST(){
        root=NULL;
    }
    ~BST(){
        delete root;
    }

    bool hasElement(int x){
    return hasElement_helper(root,x);
    }

    void Insert(int x){
        root = Insert_helper(root,x);
    }

    void Delete(int x){
        root = Delete(root,x);
    }
};
