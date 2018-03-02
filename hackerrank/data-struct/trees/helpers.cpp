
void dumpLevelOrder(node * root) {
    queue<node*> q;
    q.push(root); q.push(nullptr);
    while (!q.empty()) {
        node *n = q.front();
        q.pop();
        if (!n) {
            cout << endl;
            if (!q.empty()) q.push(nullptr);
        } else {
            if (n->left) q.push(n->left);
            if (n->right) q.push(n->right);
            cout << n->data << " ";   
        }
    }	
}
