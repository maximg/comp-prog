/*
Node is defined as 

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/

// A crude recursive version with no rbalancing

node * insert(node * root, int value)
{
    if (!root) {
        root = new node {value, nullptr, nullptr};
    }
    else if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    } else {
        // root->data == value
        root->right = new node {value, nullptr, root->right};
    }
   return root;
}