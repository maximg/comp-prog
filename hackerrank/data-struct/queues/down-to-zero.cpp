#include <cmath>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// all divisors which are >= sqrt(n)
vector<int>& candidate_divisors(int n) {
    static unordered_map<int, vector<int>> divisors; // from N
    
    auto divsIt = divisors.find(n);
    if (divsIt != divisors.end()) {
        return divsIt->second;
    }

    vector<int> ret;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0)
            ret.push_back(n / i);
    }
    divisors[n] = ret;
    return divisors[n];
}

int current_best;
static unordered_map<int, int> steps; // from N

void cache(int n, int cnt) {
    if (cnt < 1000000) {
        steps[n] = cnt;
    }    
}

int solve(int n, int current_step) {
    auto adjust = [&](int k) {
        return (k + current_step > current_best) ? 1000000 : k;
    };
    
    if (n < 4)
        return adjust(n);
    
    if (current_step >= current_best) {
        return 1000000;
    }

    int cached = steps[n];
    if (cached != 0)
        return adjust(cached);
    
    int min_steps = INT_MAX;
    auto solve1 = [&](int k) {
        int cnt = solve(k, current_step+1);
        min_steps = min(min_steps, cnt);
        current_best = min(current_best, min_steps + current_step);
    };
    
    for (auto k: candidate_divisors(n))
        solve1(k);
    solve1(n-1);

    int ret = min_steps + 1;
    cache(n, ret);
    return min(ret, 1000000);
}

int main() {
    int q{0};
    cin >> q;
    for (int i = 0; i < q; ++i) {
        current_best = INT_MAX;
        int n {0};
        cin >> n;
        cout << solve(n, 1) << "\n";
    }
    return 0;
}