// https://www.hackerrank.com/challenges/binary-search-tree-lowest-common-ancestor/problem

// This solution is for a binary tree, not a binary search tree

/*
Node is defined as 

typedef struct node
{
   int data;
   node *left;
   node *right;
}node;

*/

pair<node*, int> lca_helper(node *n, int v1, int v2) {
    int matches = (n->data == v1 || n->data == v2) ? 1 : 0;

    const auto ll = n->left ? lca_helper(n->left, v1, v2) : pair<node*, int>{nullptr, 0};
    if (ll.first) return ll;
    matches += ll.second;
    if (matches > 1) return {n, 2};
    
    const auto rr = n->right ? lca_helper(n->right, v1, v2) : pair<node*, int>{nullptr, 0};
    if (rr.first) return rr;
    matches += rr.second;
    if (matches > 1) return {n, 2};
    
    return {nullptr, matches};
}

node *lca(node *root, int v1, int v2)
{
    if (root->left) {
        const auto ll = lca_helper(root->left, v1, v2);
        if (ll.first) return ll.first;
    }
    if (root->right) {
        const auto rr = lca_helper(root->right, v1, v2);
        if (rr.first) return rr.first;
    }
    return root;
}

