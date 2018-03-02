
// https://www.hackerrank.com/challenges/tree-level-order-traversal/problem

/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

void levelOrder(node * root) {
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node *n = q.front();
        q.pop();
        if (n->left) q.push(n->left);
        if (n->right) q.push(n->right);
        cout << n->data << " ";
    }
}
