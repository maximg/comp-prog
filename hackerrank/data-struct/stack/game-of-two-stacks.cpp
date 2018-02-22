#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// This is an O(n * log(m)) solution; there is an O(n + m), 
// see the problem discussion

size_t solve() {
    size_t n, m;
    int64_t x, sum{0}, t;
    cin >> n >> m >> x;

    vector<int64_t> sums_a, sums_b;
    sums_a.push_back(0);
    for (size_t i=0; i < n; ++i) {
        cin >> t;
        sum += t;
        // optimization: do not store sums exceeding x
        if (sum <= x) {
            sums_a.push_back(sum);
        }
    }
    sum = 0;
    sums_b.push_back(0);
    for (size_t i=0; i < m; ++i) {
        cin >> t;
        sum += t;
        if (sum <= x) {
            sums_b.push_back(sum);
        }
    }

    int score = 0, last_score = 0;
    for (int i = 0; i < sums_a.size(); ++i) {
        // optimization: if the sum has not changed we already know the answer
        if (i > 0 && sums_a[i] == sums_a[i-1]) {
            last_score = last_score + 1;
        }
        else {
            // use binary search to find the max number of steps
            const auto it = upper_bound(sums_b.begin(), sums_b.end(), x - sums_a[i]);
            const int dist = distance(sums_b.begin(), it);
            last_score = i + dist;
        }
        score = max(score, last_score);
    }

    return score - 1;
}

int main() {
    size_t games; cin >> games;
    for(; games > 0; --games) {
        cout << solve() << endl;
    }
    return 0;
}
