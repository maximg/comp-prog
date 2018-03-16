
// https://www.hackerrank.com/challenges/crush/problem

#include <cmath>
#include <cstdio>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    size_t n; cin >> n;
    int m; cin >> m;

    map<size_t, int64_t> ops;
    for (int i = 0; i < m; ++i) {
        size_t a, b; int k; cin >> a >> b >> k;
        ops[a] += k; ops[b+1] -= k;
    }
    int64_t max_s{0}, v{0};
    for (const auto op: ops) {
        v += op.second;
        max_s = max(max_s, v);
    }
    
    cout << max_s << endl;
    
    return 0;
}
