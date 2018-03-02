
// https://www.hackerrank.com/challenges/swap-nodes-algo/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node {
    int data;
    node * left;
    node * right;
};

void swap(node * root, size_t k, size_t depth) {
    if ((depth % k) == 0) swap(root->left, root->right);
    if (root->left) swap(root->left, k, depth + 1);
    if (root->right) swap(root->right, k, depth + 1);
}

void in_order(node * root) {
    if (root->left) in_order(root->left);
    cout << root-> data << " ";
    if (root->right) in_order(root->right);    
}

int main() {
    size_t n; cin >> n;
    vector<node> nodes(n);
    for (int idx = 0; idx < n; ++idx) {
        int ll, rr; cin >> ll >> rr;
        nodes[idx].data = idx + 1;
        if (ll > 0) nodes[idx].left = &nodes[ll-1];
        if (rr > 0) nodes[idx].right = &nodes[rr-1];
    }

    size_t t; cin >> t;
    while (t-- > 0) {
        size_t k; cin >> k;
        swap(&nodes[0], k, 1);
        in_order(&nodes[0]);
        cout << endl;
    }
    return 0;
}
