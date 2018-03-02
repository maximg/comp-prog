
// https://www.hackerrank.com/challenges/is-binary-search-tree/problem

/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/

bool checkLeft(Node* root, int v) {
    if (!root) return true;
    if (root->data >= v) return false;
    return checkLeft(root->left, root->data) && checkRange(root->right, root->data, v);
}

bool checkRange(Node* root, int v1, int v2) {
    if (!root) return true;
    if (root->data <= v1 || root->data >= v2) return false;
    return checkRange(root->left, v1, root->data) && checkRange(root->right, root->data, v2);
}

bool checkRight(Node* root, int v) {
    if (!root) return true;
    if (root->data <= v) return false;
    return checkRange(root->left, v, root->data) && checkRight(root->right, root->data);
}

bool checkBST(Node* root) {
    return checkLeft(root->left, root->data) && checkRight(root->right, root->data);
}
