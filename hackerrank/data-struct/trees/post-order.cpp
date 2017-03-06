
// https://www.hackerrank.com/challenges/tree-postorder-traversal

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

// Recursive
void postOrder1(node *root) {
    if (!root) return;
    postOrder1(root->left);
    postOrder1(root->right);
    cout << root->data << " ";
}

// Iterative
void postOrder(node *root) {
    if (!root) return;

    stack<const node*> work;
    const node* curr = root;
    const node* prev = nullptr;
    while (true) {
        const node* new_prev = curr;
        if (curr->left && prev != curr->left && prev != curr->right) {
            // go left
            work.push(curr);
            curr = curr->left;
        }
        else if (curr->right && prev != curr->right) {
            // go right
            work.push(curr);
            curr = curr->right;
        } else {
            // go up
            cout << curr->data << " ";
            if (work.empty())
                break;
            curr = work.top();
            work.pop();
        }
        prev = new_prev;
    }
}
