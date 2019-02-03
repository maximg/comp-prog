// https://codeforces.com/contest/1111/problem/C

// Fails on test 5


#include <iostream>
#include <cstdio>
#include <cassert>

using namespace std;

struct node {
    node* left = nullptr;
    node* right = nullptr;
    uint32_t size = 0;
    uint32_t count = 0;
};

int n, k, A, B;
node root;

// Build binary tree by using the bits of the input
// to navigate intermediate nodes.

void insert(uint32_t v) {
    //cout << "v: " << v <<endl;
    node* nd = &root;
    ++root.count;
    for (uint32_t m = root.size / 2; m; m >>= 1) {
        if (m & v) {
            if (!nd->right) nd->right = new node;
            nd = nd->right;
        }
        else {
            if (!nd->left) nd->left = new node;
            nd = nd->left;
        }
        ++nd->count;
        nd->size = m;
    }
}

// Just carefully calculate the cost for each node

uint64_t solve(node* nd, string indent) {
    //cout << indent << " size: " << nd->size << endl;
    uint64_t cost = nd->count ? uint64_t(nd->count) * nd->size * B : A;
    uint64_t costLR =
        (nd->left ? solve(nd->left, indent + "  ") : A) + 
        (nd->right ? solve(nd->right, indent + "  ") : A);
    return min(cost, costLR);
}

int main(int argc, char* argv[]) {
    scanf("%d %d %d %d", &n, &k, &A, &B);
    root.size = 1 << n;

    uint32_t v;
    for (int i=0; i < k; ++i) {
        scanf("%d", &v);
        insert(v-1);
    }
    assert(root.count == k);

    cout << solve(&root, "") << endl;
}
