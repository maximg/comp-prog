// http://dobrainlog.blogspot.com/p/mall-mania-11101.html

#include <iostream>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

using ii = int;

ii moves[] = { -1, 1, -10000, 10000};

int N = 2001; // board size

bool valid(ii loc) {
    return (loc >= 0) && (loc % 10000) < N && (loc / 10000) < N;
}

int mkloc(int x, int y) {
    return x * 10000 + y;
}


bool runOnce()
{
    unordered_map<ii, int> M;
    queue<ii> bfs;
    int K1, K2;

    cin >> K1;  // number of nodes in fig 1
    if (K1 == 0)
        return false;

    for (int i = 0; i < K1; ++i) {
        int x, y;
        cin >> x >> y;
        ii loc = mkloc(x,y);
        M[loc] = 0;
        bfs.push(loc);
    }
    cin >> K2;          // number of nodes in fig 2
    for (int i = 0; i < K2; ++i) {
        int x, y;
        cin >> x >> y;
        ii loc = mkloc(x,y);
        M[loc] = INT_MAX;
    }

    int minPath = INT_MAX;
    int count = 0;
    while (!bfs.empty()) {
        ii loc = bfs.front();
        bfs.pop();
        int cost = M[loc];
        //cout << loc.first << " " << loc.second << " (" << cost << ") " << endl;
        for (int i = 0; i < 4; ++i) {
            ii loc2 = loc + moves[i];
            if (!valid(loc2)) continue;
            auto it = M.find(loc2);
            if (it == M.end()) {
                M[loc2] = cost + 1;
                if (minPath > cost + 1) {
                    bfs.push(loc2);
                    // cout << "  add:" << loc2.first << " " << loc2.second << endl;
                }
            }
            else {
                int cost2 = it->second;
                if (cost2 == INT_MAX) { // found
                    minPath = min(minPath, cost + 1);
                }
                else {
                    if (cost2 > cost + 1) {
                        M[loc2] = cost + 1;
                        // Optimization: push cost as well,
                        // if cost has changed since it was pushed - ignore?
                        bfs.push(loc2);
                        // cout << "  add (cheaper):" << loc2.first << " " << loc2.second << endl;
                    }
                }
            }
        }
    }
    cout << minPath << endl;

    return true;
}

int main()
{
    while (runOnce())
        ;

    return 0;
}
