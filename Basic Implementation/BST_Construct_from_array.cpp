#include<iostream>
#include<queue>
#include"BinaryTree_Node_Class.cpp"
using namespace std;
 
BinaryTree<int>* BSTmaker(vector<int> arr,int si, int ei){
    if(si>ei){
        return NULL;
    }

    int mid = (si+ei)/2;
    BinaryTree<int>* root= new BinaryTree<int>(arr[mid]);
    root->left=BSTmaker(arr,si,mid-1);
    root->right=BSTmaker(arr,mid+1,ei);
    return root;
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
    vector<int> arr;
    int ele;
    cout<<"Enter your array: "<<endl;
    cin>>ele;
    while(ele!=-1){
        arr.push_back(ele);
        cin>>ele;
    }
    int size=arr.size();
    BinaryTree<int>* root= BSTmaker(arr,0,size-1);
    cout<<"Your Tree:"<<endl;
    PrintLevel(root);
}