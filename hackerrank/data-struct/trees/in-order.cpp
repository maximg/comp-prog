
// https://www.hackerrank.com/challenges/tree-inorder-traversal

/* you only have to complete the function given below.  
Node is defined as  

struct node
{
    int data;
    node* left;
    node* right;
};

*/
#include <stack>
using namespace std;

// recursive
void inOrder1(node *root) {
    if (!root) return;
    inOrder1(root->left);
    cout << root->data << " ";
    inOrder1(root->right);
}

// iterative
void inOrder(node *root) {
    if (!root) return;
    stack<node*> work;
    node* current = root;
    bool down = true;
    while (true) {
        if (current->left && down) {
            work.push(current);
            current = current->left;
        } else if (current->right) {
            cout << current->data << " ";
            current = current->right;
            down = true;
        } else {
            cout << current->data << " ";
            if (work.empty())
                break;
            current = work.top();
            work.pop();
            down = false;
        }
    }
}