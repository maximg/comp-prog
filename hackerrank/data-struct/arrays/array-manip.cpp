#include <cmath>
#include <cassert>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    Node *l, *r; // left, right
    size_t low, high;
    int64_t max;
    
    Node(size_t low_, size_t high_, size_t m_) : l(nullptr), r(nullptr), low(low_), high(high_), max(m_) {}
    bool is_leaf() const { return l == nullptr && r == nullptr; }
    int64_t get_max() const {
        assert( is_leaf() || (l && r));
        return is_leaf() ? max : std::max(l->get_max(), r->get_max()); 
    }
};

size_t nodes{0};

void add(Node &n, size_t low, size_t high, int k) {
    assert( n.is_leaf() || (n.l && n.r));
    
    if (n.low == low && n.high == high) { // shall we check for <= and >= ?
        // we have a perfect match
        if (n.is_leaf()) n.max += k;
        else {
            add(*n.l, n.l->low, n.l->high, k);
            add(*n.r, n.r->low, n.r->high, k);
        }
        return;
    }
    if (n.is_leaf()) {
        // convert it to a non-leaf node
        assert(n.low - n.high > 1);
        size_t mid = (n.low + n.high) / 2;
        n.l = new Node(n.low, mid, n.max);
        n.r = new Node(mid, n.high, n.max);
        nodes += 2;      
    }
    // not a leaf
    if (low < n.l->high) add(*n.l, low, min(high, n.l->high), k);
    if (high > n.r->low) add(*n.r, max(low, n.r->low), high, k);
}
    
struct Manip {
    size_t a, b;
    int k;
    size_t s;
};

bool comp(const Manip &a, const Manip &b) { return b.s < a.s; }

int main() {
    size_t n; cin >> n;
    int m; cin >> m;
    
    Node root(1, n+1, 0);
    
    vector<Manip> v(m);
    for (int i = 0; i < m; ++i) {
        size_t a, b; int k; cin >> a >> b >> k;
        v[i] = Manip{a, b, k, b - a + 1};
    }
    sort(v.begin(), v.end(), comp);
    cout << "start" << endl;
    for (int i = 0; i < m; ++i) {
        add(root, v[i].a, v[i].b+1, v[i].k);
        if ((i % 1000) == 0) cout << v[i].s << " " << nodes << endl; //cout << "." << flush ;
    }
    cout << endl;
    cout << root.get_max() << endl;
    return 0;
}
