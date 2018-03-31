
// https://www.hackerrank.com/challenges/even-tree/problem

#include <vector>
#include <iostream>

using namespace std;

struct Node {
    vector<int> edges;  
};

// return max number of removed and the count of nodes
pair<int, int> analyze_tree(vector<Node> &tree, int idx) {
    int nnodes{1}, nremoved{0};
    for (int node: tree[idx].edges) {
        auto ret = analyze_tree(tree, node);
        nnodes += ret.second;
        nremoved += ret.first + (((ret.second % 2) == 0) ? 1 : 0);
    }
    // cout << idx + 1 << " " << nremoved << " " << nnodes << endl;
    return {nremoved, nnodes};
}

int main()
{
    int nnodes, nedges; cin >> nnodes >> nedges;
    
    vector<Node> tree(nnodes);
    while (nedges--) {
        int from, to; cin >> from >> to;
        tree[to-1].edges.push_back(from-1);
    }
    
    cout << analyze_tree(tree, 0).first << endl;
    
    return 0;
}
