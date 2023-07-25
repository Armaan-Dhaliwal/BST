#include<iostream>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
};

int helper(TreeNode* root, int &k){
        if(root==NULL){
            return -1;
        }

        int left=helper(root->left,k);
        if(left!=-1){
            return left;
        }

        k--;
        if(k==0){
            return root->val;
        }
        return helper(root->right,k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int K=k;
        return helper(root,K);
    }