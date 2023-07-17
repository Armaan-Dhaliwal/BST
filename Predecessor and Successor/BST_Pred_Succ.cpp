//{ Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include "bits/stdc++.h"
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    
    void GetPre(Node* root,Node* &pre){
        
        if(root==NULL){
            return;
        }
        if(root->right==NULL){
            pre=root;
            //cout<<"pre returned as: "<<pre->key<<endl;
            return;
        }

        GetPre(root->right,pre);
    }
    
    void GetSuc(Node* root,Node* &suc){
        
        if(root==NULL){
            return;
        }
        if(root->left==NULL){
            suc=root;
            return;
        }

        GetSuc(root->left,suc);
    }
    
  void helper_no_key(Node* root, Node*& pre, Node*& suc, int val){
        if(root==NULL){
            return;
        }
        
        if(root->left!=NULL && root->right!=NULL){
            if(root->right->key>val && root->left->key<val){
                if(root->key>val){
                    suc=root;
                }
                else{
                    GetSuc(root->right,suc);
                }
                
                if(root->key<val){
                    pre=root;
                }
                else{
                    GetPre(root->left,pre);
                }
                return;
            }
        }
        
        else if(root->right==NULL && root->left!=NULL && root->left->key<val && root->key>val ){
            suc=root;
            GetPre(root->left,pre);
            return;
        }
        
        else if(root->left==NULL && root->right!=NULL && root->right->key>val && root->key<val){
            pre=root;
            GetSuc(root->right,suc);
            return;
        }
        
        if(root->key>val){
            suc=root;
            helper_no_key(root->left,pre,suc,val);
        }
        else if(root->key<val){
            pre=root;
           helper_no_key(root->right,pre,suc,val); 
        }
        
    }
    
    bool KeyExists(Node* root, int val){
        if(root==NULL){
            return false;
        }
        
        if(root->key==val){
            return true;
        }
        return KeyExists(root->left,val) || KeyExists(root->right,val);
    }
    
    void helper_key(Node* root, Node*& pre, Node*& suc, int val){
        if(root==NULL){
            return ;
        }
        
        if(root->key==val){
            GetPre(root->left,pre);
            GetSuc(root->right,suc);
            return;
        }
        
        if(root->key>val){
            suc=root;
            helper_key(root->left,pre,suc,val);
        }
        else if(root->key<val){
            pre=root;
            helper_key(root->right,pre,suc,val);
        }
    }
    
    //void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    // {   
    //     if(root==NULL){
    //         return;
    //     }
    //     pre=NULL;
    //     suc=NULL;
    //     if(KeyExists(root,key)){
    //      helper_key(root,pre,suc,key);
    //     }
    //     else{
    //         if(root->right==NULL && root->key<key){
    //             pre=root;
    //             suc=NULL;
    //             return;
    //         }
    //         else if(root->left==NULL && root->key>key){
    //             pre=NULL;
    //             suc=root;
    //             return;
    //         }
    //         else if(root->left==NULL && root->right==NULL){
    //                 if(root->key>key){
    //                     suc=root;
    //                     pre=NULL;
    //                 }
    //                 else if(root->key<key){
    //                     suc=NULL;
    //                     pre=root;
    //                 }
    //                 return;
    //             } 
    //         helper_no_key(root,pre,suc,key);   
    //     }
        
    // }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    // Base case
    if (root == NULL)  return ;
 
    // If key is present at root
    if (root->key == key)
    {
        // the maximum value in left subtree is predecessor
        if (root->left != NULL)
        {
            Node* tmp = root->left;
            while (tmp->right)
                tmp = tmp->right;
            pre = tmp ;
        }
 
        // the minimum value in right subtree is successor
        if (root->right != NULL)
        {
            Node* tmp = root->right ;
            while (tmp->left)
                tmp = tmp->left ;
            suc = tmp ;
        }
        return ;
    }
 
    // If key is smaller than root's key, go to left subtree
    if (root->key > key)
    {
        suc = root ;
        findPreSuc(root->left, pre, suc, key) ;
    }
    else // go to right subtree
    {
        pre = root ;
        findPreSuc(root->right, pre, suc, key) ;
    }
}
};

//{ Driver Code Starts.

Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}
// Driver program to test above functions
int main() {
   
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, s);
        int k = stoi(s);
        Node *pre=NULL,*succ=NULL;
        Solution ob;
        ob.findPreSuc(root,pre,succ,k);
        (pre!=NULL)?cout<<pre->key:cout<<-1;
        cout<<" ";
        (succ!=NULL)?cout<<succ->key:cout<<-1;
        cout<<endl;
        // inOrderTraversal(root);
   }
   return 0;
}
// } Driver Code Ends