#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int from;
    int to;
    int weight;
};

int main()
{
    int g_nodes;
    int g_edges;

    cin >> g_nodes >> g_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<Edge> edges;
    edges.reserve(g_edges);

    for (int g_itr = 0; g_itr < g_edges; g_itr++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        edges.push_back({from, to, weight});
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return (a.weight == b.weight)
            ? ((a.from + a.weight + a.to) < (b.from + b.weight + b.to)) 
            : a.weight < b.weight;
    });

    vector<int> comps(g_nodes+1);
    for (int i = 0; i <= g_nodes; ++i)
        comps[i] = i;
    
    int g_weight{0};
    for (int i = 0; i < g_edges; ++i) {
        auto &e = edges[i];
        //cout << e.from << " " << e.to << " " << e.weight << " ";
        if (comps[e.from] != comps[e.to]) {
            g_weight += e.weight;
            int from = comps[e.from];
            for (auto &n: comps) {
                if (n == from) n = comps[e.to];
            }
        }
    }

    cout << g_weight << endl;
    
    return 0;
}
