// C++ implementation of the 
// above approach
#include <bits/stdc++.h>
using namespace std;
 
// Node of the binary tree
struct node {
    int data;
    node* left;
    node* right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
 
// Function to print flattened
// binary tree
void print(node* parent)
{
    node* curr = parent;
    while (curr != NULL)
        cout << curr->data << " ", curr = curr->right;
}
 
// Function to perform reverse in-order traversal
void revInorder(node* curr, node*& prev)
{
    // Base case
    if (curr == NULL)
        return;
    revInorder(curr->right, prev);
    prev->left = NULL;
    prev->right = curr;
    prev = curr;
    revInorder(curr->left, prev);
}
 
// Function to flatten binary tree using
// level order traversal
node* flatten(node* parent)
{
 
    // Dummy node
    node* dummy = new node(-1);
 
    // Pointer to previous element
    node* prev = dummy;
 
    // Calling in-order traversal
    revInorder(parent, prev);
 
    prev->left = NULL;
    prev->right = NULL;
    node* ret = dummy->right;
 
    // Delete dummy node
    delete dummy;
    return ret;
}
 
// Driver code
int main()
{
    node* root = new node(5);
    root->left = new node(3);
    root->right = new node(7);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(8);
 
    // Calling required function
    print(flatten(root));
 
    return 0;
}