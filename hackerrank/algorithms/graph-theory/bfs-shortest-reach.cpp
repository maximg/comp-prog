#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
using namespace std;

void bfs_distance() {
    int n{0}, m{0};
    cin >> n >> m;
    using adj_list = list<int>;
    vector<adj_list> nodes(n + 1, adj_list());
    for (int i = 0; i < m; ++i) {
        int a{0}, b{0};
        cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    int s{0};
    cin >> s;
    
    constexpr int LINK_COST = 6;
    vector<bool> seen(n + 1, false);
    vector<int> distance(n + 1, -1);
    queue<int> work;
    seen[s] = true;
    distance[s] = 0;
    work.push(s);
    while (!work.empty()) {
        int curr = work.front();
        work.pop();
        int curr_dist = distance[curr];
        for (const auto adj : nodes[curr]) {
            if (!seen[adj]) {
                distance[adj] = curr_dist + LINK_COST;
                seen[adj] = true;
                work.push(adj);
            }
        }
    }
    
    for (int i = 1; i < distance.size(); ++i) {
        if (i != s) {
            cout << distance[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    int q{0};
    cin >> q;
    while (q-- > 0) {
        bfs_distance();
    }
    return 0;
}
