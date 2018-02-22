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

using dsj_set_t = vector<Node>;

Node* root(Node* node) {
    // path compression
    if (!node->parent)
        return node;

    node->parent = root(node->parent);
    return node->parent;
}

void merge(dsj_set_t &nodes, int ii, int jj) {
    // rank-based merging
    Node* pi = root(&nodes[ii]);
    Node* pj = root(&nodes[jj]);
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
    int n{0}, m{0}, k{0};
    cin >> n >> m >> k;

    dsj_set_t nodes(n);
	vector<int> centers(k);

    for (int i = 0; i < k; ++i) {
		int x{0};
		cin >> x;
		centers.push_back(x);
	}
	

	return 0;
}