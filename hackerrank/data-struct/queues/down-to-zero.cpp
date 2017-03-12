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
    static unordered_map<int, int> check_steps; // from N

bool check_step(int n, int cnt) {
    return (check_steps[n] == 0 || check_steps[n] == cnt);
}

int trace (int n, int ret, char c, int current_best, int current_step) {
//    cout << n << ": " << ret << " " << c << " " << current_best << " " << current_step << "\n";
    return ret;
}

void cache(int n, int cnt) {
    if (cnt < 1000000) {
        steps[n] = cnt;
        if (!check_step(n, cnt)) {
            cout << "PROBLEM: " << n << " " << cnt << " " << check_steps[n] << "\n";
        }
    }    
}

int solve(int n, int current_step) {
    if (n < 4)
        return trace(n, n, ' ', current_best, current_step);
    
//    static unordered_map<int, int> steps; // from N
    int cached = steps[n];
    if (cached != 0)
        return trace(n, cached, 'C', current_best, current_step);

    if (current_step >= current_best) {
        return trace(n, 1000000, ' ', current_best, current_step);
        //return 1000000;
    }
    
    const auto &divs = candidate_divisors(n);
    if (divs.empty()) {
        int cnt = solve(n-1, current_step+1);
        cache(n, cnt);
        return trace(n-1, 1 + cnt, '#', current_best, current_step);
//        return 1 + solve(n-1, current_step+1);
    }

    int min_steps = INT_MAX;
    auto solve1 = [&](int k) {
        int cnt = solve(k, current_step+1);
        min_steps = min(min_steps, cnt);
        current_best = min(current_best, min_steps + current_step);
    };
    
    for (auto k: divs)
        solve1(k);
    solve1(n-1);

    int ret = min_steps + 1;
    cache(n, ret);
    return trace(n, ret, '*', current_best, current_step);
//    return ret;
}

int main() {
        current_best = INT_MAX;
        solve(7267, 1);
        check_steps = steps;
        steps.clear();
    
    int q{0};
    cin >> q;
    for (int i = 0; i < q; ++i) {
        steps.clear();
        current_best = INT_MAX;
        int n {0};
        cin >> n;
        cout << solve(n, 1) << "\n";
    }
    return 0;
}
