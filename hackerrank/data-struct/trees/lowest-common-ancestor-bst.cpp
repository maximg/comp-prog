
//

/*
Node is defined as 

typedef struct node
{
   int data;
   node *left;
   node *right;
}node;

*/

node *lca(node *root, int v1, int v2)
{
    if (min(v1, v2) <= root->data) {
        return (max(v1, v2) >= root->data) ? root : lca(root->left, v1, v2);
    }
    return lca(root->right, v1, v2);
}
