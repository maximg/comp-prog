// http://dobrainlog.blogspot.com/p/mall-mania-11101.html

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

using ii = pair<int, int>;

ii moves[] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int N; // board size

bool valid(ii loc) {
    return (loc.first >= 0) && (loc.first < N) && 
           (loc.second >= 0) && (loc.second < N);
}

struct pairhash {
public:
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U> &x) const
  {
    return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
  }
};

int main()
{
    unordered_map<ii, int, pairhash> M;
    queue<ii> bfs;
    int K1, K2;

    cin >> N;    
    cin >> K1;  // number of nodes in fig 1
    for (int i = 0; i < K1; ++i) {
        int x, y;
        cin >> x >> y;
        M[{x,y}] = 0;
        bfs.push({x,y});
    }
    cin >> K2;          // number of nodes in fig 2
    for (int i = 0; i < K2; ++i) {
        int x, y;
        cin >> x >> y;
        M[{x,y}] = INT_MAX;
    }

    int minPath = INT_MAX;
    while (!bfs.empty()) {
        ii loc = bfs.front();
        bfs.pop();
        int cost = M[loc];
        //cout << loc.first << " " << loc.second << " (" << cost << ") " << endl;
        for (int i = 0; i < 4; ++i) {
            ii loc2 = { loc.first + moves[i].first,
                        loc.second + moves[i].second };
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

    return 0;
}
