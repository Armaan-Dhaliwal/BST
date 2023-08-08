#include <iostream>
#include<stack>
#include<limits.h>
using namespace std;



typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

// // A Stack has array of Nodes, capacity, and top
// typedef struct Stack
// {
//     int top;
//     int capacity;
//     Node* *array;
// } Stack;

// A utility function to create a new tree node
Node* newNode( int data )
{
    Node* temp = (Node *)malloc( sizeof( Node ) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// // A utility function to create a stack of given capacity
// Stack* createStack( int capacity )
// {
//     Stack* stack = (Stack *)malloc( sizeof( Stack ) );
//     stack->top = -1;
//     stack->capacity = capacity;
//     stack->array = (Node **)malloc( stack->capacity * sizeof( Node* ) );
//     return stack;
// }

// // A utility function to check if stack is full
// int isFull( Stack* stack )
// {
//     return stack->top == stack->capacity - 1;
// }

// // A utility function to check if stack is empty
// int isEmpty( Stack* stack )
// {
//     return stack->top == -1;
// }

// // A utility function to push an item to stack
// void push( Stack* stack, Node* item )
// {
//     if( isFull( stack ) )
//         return;
//     stack->array[ ++stack->top ] = item;
// }

// // A utility function to remove an item from stack
// Node* pop( Stack* stack )
// {
//     if( isEmpty( stack ) )
//         return NULL;
//     return stack->array[ stack->top-- ];
// }

// // A utility function to get top node of stack
// Node* peek( Stack* stack )
// {
//     return stack->array[ stack->top ];
// }

// bool canRepresentBST(int pre[], int n)
// {
//     stack<int> s;
//     int root = INT_MIN;

//     for (int i=0; i<n; i++)
//     {
//         if (pre[i] < root)
//             return false;
//         while (!s.empty() && s.top()<pre[i])
//         {
//             root = s.top();
//             s.pop();
//         }
//         s.push(pre[i]);
//     }
//     return true;
// }


// void printPostorder (Node* node)
// {
//     if (node == NULL)
//         return;
//     printPostorder(node->left);
//     printPostorder(node->right);
//     printf("%d ", node->data);
// }

class Solution{
public:

    Node* helper(int pre[], int size, int &index, int min_val, int max_val){
        if(index>=size){
            return NULL;
        }
        
        if(pre[index]<min_val || pre[index]>max_val){
            return NULL;
        }
            Node* root = newNode(pre[index]);
            index++;
        
        root->left = helper(pre,size,index,min_val,root->data);
        root->right = helper(pre,size,index,root->data,max_val);
        return root;
    }
    //Function that constructs BST from its preorder traversal.
    Node* post_order(int pre[], int size)
    {
       int index=0;
       Node* root = helper(pre,size,index,INT_MIN,INT_MAX);
       return root;
    }
};

//{ Driver Code Starts.


// int main()
// {
//     // Note that size of arr[] is considered 100 according to
//     // the constraints mentioned in problem statement.
//     int arr[1000], x, t, n;

//         // Input the size of the array
//         cin >> n;

//         // Input the array
//         for (int i=0; i<n; i++)
//             cin >> arr[i];
        
//         Solution ob;
//         printPostorder(ob.post_order(arr, n));
//         cout << endl;
//     return 0;
// }

// } Driver Code Ends