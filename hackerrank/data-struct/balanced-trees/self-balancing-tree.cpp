/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */


node * insert(node * root, int val)
{
    auto height = [](node *n) { return n ? n->ht : -1; };
    auto bf = [&height](node *n) { return height(n->left) - height(n->right); };

    if (val < root->val) {
        root->left = root->left ? insert(root->left, val)
                                : new node{val, nullptr, nullptr, 0};
    }
    else if (val > root->val) {
        root->right = root->right ? insert(root->right, val)
                                  : new node{val, nullptr, nullptr, 0};
    }
    // val == root->val never happens

    root->ht = max(height(root->left), height(root->right)) + 1;
    
    // rebalance nodes as needed

    if (bf(root) > 1) { // rebalance left
        node *n5 = root;
        node *n3 = root->left;
        node *n4 = n3->right;
        if (bf(n3) < 0) { // step 1
            node *treeB = n4->left;
            n5->left = n4;
            n3->right = treeB;
            n4->left = n3;
        } else {
            n4 = n3;
            n3 = n4->left;
        }
        node *treeC = n4->right;
        root = n4;
        n4->right = n5;
        n5->left = treeC;
        n3->ht = max(height(n3->left), height(n3->right)) + 1;
        n5->ht = max(height(n5->left), height(n5->right)) + 1;
        n4->ht = max(n3->ht, n5->ht) + 1;
    } else if (bf(root) < -1) { // rebalance right
        node *n3 = root;
        node *n5 = n3->right;
        node *n4 = n5->left;
        if (bf(n5) > 0) { // step 1
            node *treeC = n4->right;
            n3->right = n4;
            n5->left = treeC;
            n4->right = n5;
        } else {
            n4 = n5;
            n5 = n4->right;
        }
        node *treeB = n4->left;
        root = n4;
        n4->left = n3;
        n3->right = treeB;
        n3->ht = max(height(n3->left), height(n3->right)) + 1;
        n5->ht = max(height(n5->left), height(n5->right)) + 1;
        n4->ht = max(n3->ht, n5->ht) + 1;
    }

    return root;
}
