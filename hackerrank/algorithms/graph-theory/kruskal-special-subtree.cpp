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
            ? ((a.from + a.to) < (b.from + b.to)) 
            : a.weight < b.weight;
    });

    int comp{1};
    int g_weight{0};
    vector<int> comps(g_nodes+1);
    
    for (int i = 0; i < g_edges; ++i) {
        auto &e = edges[i];
        //cout << e.from << " " << e.to << " " << e.weight << " ";
        bool new_comp = max(comps[e.from], comps[e.to]) == 0;
        bool loop = !new_comp && (comps[e.from] == comps[e.to]);
        bool attach = !loop && !new_comp && (min(comps[e.from], comps[e.to]) == 0);
        if (loop) {
            //cout << endl;
            continue;
        }
        if (new_comp) {
            comps[e.from] = comps[e.to] = ++comp;
            //cout << comps[e.from]<< " +"  << endl;
        } else if (attach) {
            comps[e.from] = comps[e.to] = max(comps[e.from], comps[e.to]);
            //cout << comps[e.from]<< " *"  << endl;
        } else {
            // join 2 subgraphs
            int from = comps[e.from];
            for (auto &n: comps) {
                if (n == from) n = comps[e.to];
            }
            //cout << from << " -> " << comps[e.to] << endl;
        }
        g_weight += e.weight;
    }

    cout << g_weight << endl;
    
    return 0;
}
