
// https://www.hackerrank.com/challenges/torque-and-development/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int node;
    Edge *next;
};

void dfs(int idx, const vector<Edge*> &graph, vector<int> &comp, int n_comp) {
    if (comp[idx] > 0) return;
    comp[idx] = n_comp;
    Edge *e = graph[idx];
    while (e) {
        dfs(e->node, graph, comp, n_comp);
        e = e->next;
    }
}

int main() {
    int q; cin >> q;
    while (q-- > 0) {
        int n, m;
        int64_t c_lib, c_road;
        cin >> n >> m >> c_lib >> c_road;
        vector<Edge*> graph(n);
        for (int i = 0; i < m; ++i) {
            int from, to;
            cin >> from >> to;
            if (c_road < c_lib) {
                graph[from-1] = new Edge{ to-1, graph[from-1] };
                graph[to-1] = new Edge{ from-1, graph[to-1] };
            }
        }
        
        if (c_road >= c_lib) {
            cout << n * c_lib << endl;
            continue;
        }
        
        // find connected components
        int64_t n_comp{0};
        vector<int> comp(n);
        for (int i = 0; i < n; ++i) {
            if (comp[i] == 0) {
                ++n_comp;
                dfs(i, graph, comp, n_comp);
            }
        }
        cout << "n_comp: " << n_comp << endl;
        // Build one library for each connected component
        // and one road for each non-library node
        cout << n_comp * c_lib + (n - n_comp) * c_road << endl;
    }
    return 0;
}

