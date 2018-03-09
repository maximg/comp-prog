
// https://www.hackerrank.com/challenges/no-prefix-set/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Character value of a node is determined by the position of the pointer to it
// in the children array of the parent

struct node {
    node *children[10] = {};
    int cnt;
};

bool is_leaf(const node *n) {
    for (const auto p: n->children) {
        if (p) return false;
    }
    return true;
}

// return false if there is a prefix conflict
bool add(node *root, const string &arg) {
    bool no_conflict = false;
    node *cur = root;
    for (auto c: arg) {
        const int idx = c - 'a';
        node *next = cur->children[idx];
        if (!next) {
            // there is no prefix conflict if we have inserted a node at a non-leaf node
            // or at the root
            no_conflict = no_conflict || (cur == root) || !is_leaf(cur);
            next = cur->children[idx] = new node;
        }
        cur = next;
    }
    return no_conflict;
}

int main() {
    size_t n; cin >> n;
    node root;
    for (size_t i = 0; i < n; ++i) {
        string input;
        cin >> input;
        if (!add(&root, input)) {
            cout << "BAD SET" << endl;
            cout << input << endl;
            return 0;
        }   
    }
    cout << "GOOD SET" << endl;
        
    return 0;
}
