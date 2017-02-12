#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <memory>
using namespace std;

struct Node {
    Node* parent = nullptr;
    int rank = 0;
    int count = 1;
};

using people_vec_t = vector<Node>;

Node* root(Node* node) {
    // path compression
    if (!node->parent)
        return node;

    node->parent = root(node->parent);
    return node->parent;
}

void merge(people_vec_t &people, int ii, int jj) {
    // rank-based merging
    Node* pi = root(&people[ii]);
    Node* pj = root(&people[jj]);
    if (pi == pj) {
        return;
    }
    if (pi->rank < pj->rank) {
        pi->parent = pj;
        pj->count += pi->count;
    }
    else if (pi->rank > pj->rank) {
        pj->parent = pi;
        pi->count += pj->count;
    }
    else {
        pj->parent = pi;
        pi->count += pj->count;
        pi->rank += 1;        
    }
}

int main() {
    int n{0}, q{0};
    cin >> n >> q;

    people_vec_t people(n);

    for (int i = 0; i < q; ++i) {
        char cmd;
        cin >> cmd;
        if (cmd == 'M') {
            int ii{0}, jj{0};
            cin >> ii >> jj;
            merge(people, ii - 1, jj - 1);
        } else if (cmd == 'Q') {
            int ii{0};
            cin >> ii;
            cout << root(&people[ii - 1])->count << endl;
        }
    }

    return 0;
}
