//
//  Header.h
//  Binary Search Tree
//
//  Created by abdullah on 28/10/2019.
//  Copyright © 2019 abdullah. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include<queue>
#include <cmath>
#define COUNT 10
using namespace std;
// Node Structure
struct Node {
    int data;
    Node* left, *right;
    Node(int a) {
        data = a;
        left = NULL;
        right = NULL;
    }
};
// Recursive Insert Function
Node* insert(Node* root, int data) {
    if(root == NULL) {
        return new Node(data);
    } else {
        Node* cur;
        if(data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
        } else {
            cur = insert(root->right, data);
            root->right = cur;
        }

       return root;
   }
}
// Pre Order Traversal
void preOrder(Node *root) {
    cout<<root->data<<" ";
    if(root->left != NULL){
        preOrder(root->left);
    }
    if(root->right != NULL){
        preOrder(root->right);
    }
}
//Post Order traversal
void postOrder(Node *root) {
    if(root->left != NULL){
        postOrder(root->left);
    }
    if(root->right != NULL){
        postOrder(root->right);
    }
    cout<<root->data<<" ";
}
// In Order Traversal
void inOrder(Node *root) {
    if(root->left != NULL){
        inOrder(root->left);
    }
    cout<<root->data<<" ";
    if(root->right != NULL){
        inOrder(root->right);
    }
}
// Height of Tree
int height(Node* root) {
    if(root == NULL){
        return -1;
    }
    else{
        int Left_Depth = height(root->left);
        int Rigth_Depth = height(root->right);

        if(Left_Depth > Rigth_Depth){
            return (Left_Depth + 1);
        }
        else
            return (Rigth_Depth + 1);
    }
}
// isEmpty fuction
bool isEmpty(Node *root){
    if(root){
        return false;
    }
    return true;
}
// Funtion to check if Given Data is Present in the tree
bool retrieve(Node *root,int key){
    if(root == nullptr){
        return false;
    }
    else if(root->data == key){
        return true;
    }
    else if(key > root->data){
        return retrieve(root->right, key);
    }
    else if(key < root->data){
        return retrieve(root->left, key);
    }
    return false;
}
// Count Number Of Nodes
int countNodes(struct Node* root)
{
    if (root == NULL)
        return (0);
    return (1 + countNodes(root->left) + countNodes(root->right));
}
// Full Binary Tree
bool isFullTree (struct Node* root)
{
    // If empty tree
    if (root == NULL)
        return true;
  
    // If leaf node
    if (root->left == NULL && root->right == NULL)
        return true;
  
    // If both left and right are not NULL
    // left & right subtrees are full
    if ((root->left) && (root->right))
        return (isFullTree(root->left) && isFullTree(root->right));
  
    // Default Condition
    return false;
}
// Complete Tree
bool isComplete (struct Node* root, unsigned int index,unsigned int number_nodes){
    // Empty Tree
    if (root == NULL)
        return (true);
  
    // If index assigned to current node is more than
    // number of nodes in tree, then tree is not complete
    if (index >= number_nodes)
        return (false);
  
    // Left andRight SubTree Recursion
    return (isComplete(root->left, (2*index) + 1, number_nodes) &&
            isComplete(root->right, (2*index) + 2, number_nodes));
}
// Depth of Left most Leaf
int findADepth(Node *node)
{
   int depth = 0;
   while (node != NULL)
   {
      depth++;
      node = node->left;
   }
   return depth;
}
// Perfect Tree
bool isPerfectRec(struct Node* root, int depth, int level = 0)
{
    // Empty Tree
    if (root == NULL)
        return true;
  
    // If leaf node, then its depth must be same as
    // depth of all other leaves.
    if (root->left == NULL && root->right == NULL)
        return (depth == level+1);
  
    // If internal node and one child is empty
    if (root->left == NULL || root->right == NULL)
        return false;
  
    // Left and right subtrees must be perfect.
    return isPerfectRec(root->left, depth, level+1) &&
           isPerfectRec(root->right, depth, level+1);
}
bool isPerfect(Node *root)
{
   int depth = findADepth(root);
   return isPerfectRec(root, depth);
}
// Balanced Tree
bool isBalanced(Node* root)
{
    int lh; /* for height of left subtree */
    int rh; /* for height of right subtree */
  
    /* If tree is empty then return true */
    if (root == NULL)
        return 1;
  
    /* Get the height of left and right sub trees */
    lh = height(root->left);
    rh = height(root->right);
  
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
  
    // Defaukt Condition
    return 0;
}
// Infinite Complete Binary Tree
bool InfiniteCompleteTree(Node *root){
    int d = findADepth(root);
    int numOfNodes = countNodes(root);
    if (pow(2, d) == numOfNodes) {
        return true;
    }
    else
        return false;
}
// Degenerate Tree
bool isDegenerate(Node* root){
    if(root->right == nullptr && root->left == nullptr){
        return true;
    }
    if(root->left == nullptr && root->right != nullptr){
        isDegenerate(root->right);
        
    }
    else if (root->right == nullptr && root->left != nullptr){
        isDegenerate(root->left);
        
    }
    else{
        return 0;
    }
    
    return true;
}
// Printing funtion to print the tree in 2D
void print2DUtil(Node *root, int space)
{
    if (root == NULL)
        return;
    space += COUNT;
    print2DUtil(root->right, space);
    cout<<endl;
    for (int i = COUNT; i < space; i++)
        cout<<" ";
    cout<<root->data<<"\n";
    print2DUtil(root->left, space);
}
void print2D(Node *root)
{
    // Pass initial space count as 0
    print2DUtil(root, 0);
}
Node * minValueNode(Node* node)
{
    Node* current = node;
  
//    Finding LeftMost Leaf
    while (current && current->left != NULL)
        current = current->left;
  
    return current;
}
Node* deleteNode(Node* root, int key)
{
//    Base Case
    if (root == NULL)
        return root;
  
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else
    {
//        Leaf Node or Node with one child
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
//      Node with two children , Find smallest right subtree
        Node* temp = minValueNode(root->right);
//        Copy Content to node
        root->data = temp->data;
//        Deleting Succesor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
void breadthFirst(Node *root){
    queue<Node*> queue;
    Node *traverse;
    queue.push(root);
    while(!queue.empty()) {
        traverse = queue.front();
        cout<<"Node "<<traverse->data<<"Traversed"<<endl;
        queue.pop();
        if (traverse->left != nullptr) {
            queue.push(traverse->left);
        }
        if (traverse->right != nullptr) {
            queue.push(traverse->right);
        }
    }
}
#endif /* Header_h */
