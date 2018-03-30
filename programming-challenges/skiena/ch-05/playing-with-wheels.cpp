
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using namespace std;

int read4() {
    int n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;
    return ((n1 * 10 + n2) * 10 + n3) * 10 + n4;
}

int next_val(int val, int move) {
    if (move == 1) { if ((val % 10) == 9) return val - 9; else return val + 1; }
    if (move == -1) { if ((val % 10) == 0) return val + 9; else return val - 1; }
    if (move == 10) { if ((val % 100) >= 90) return val - 90; else return val + 10; }
    if (move == -10) { if ((val % 100) < 10) return val + 90; else return val - 10; }
    if (move == 100) { if ((val % 1000) >= 900) return val - 900; else return val + 100; }
    if (move == -100) { if ((val % 1000) < 100) return val + 900; else return val - 100; }
    if (move == 1000) { if ((val % 10000) >= 9000) return val - 9000; else return val + 1000; }
    if (move == -1000) { if ((val % 10000) < 1000) return val + 9000; else return val - 1000; }
    return -1;
}

int solve_one() {
    int moves[] = {-1, 1, -10, 10, -100, 100, -1000, 1000};
    unordered_set<int> blocked;
    int start = read4();
    int goal = read4();
    //cout << start << " " << goal << endl;
    int count_x; cin >> count_x;
    while (count_x-- > 0) {
        blocked.insert(read4());
    }
    int cnt{0};
    queue<pair<int, int>> bfs; //number, move count
    bfs.push({start, 0});
    blocked.insert(start);
    while (!bfs.empty()) {
        auto current = bfs.front();
        bfs.pop();
        blocked.insert(current.first);
        //cout << current.first << endl;
        //if ((++cnt %100) == 0) cout << cnt << endl;

        if (current.first == goal) {
            return current.second;
        }

        for (auto move: moves) {
            int val = next_val(current.first, move);
            //cout << val << endl;
            if (blocked.find(val) == blocked.end()) {
                bfs.push({val, current.second+1});
                blocked.insert(val);
            }
        }
    }
    return -1;
}

int main() {
    int n; cin >> n;
    while (n-- > 0) {
        cout << solve_one() << endl;
    }
}