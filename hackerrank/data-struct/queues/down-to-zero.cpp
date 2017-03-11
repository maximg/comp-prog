#include <cmath>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

void dump(vector<int> v) {
    for (auto k: v) cout << k << " ";
    cout << endl;
}

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
//    cout << "divs(" << n << "): ";
//    dump(ret);
    return divisors[n];
}

int trace (int n, int ret, char c, int current_best, int current_step) {
    //cout << n << ": " << ret << " " << c << " " << current_best << " " << current_step << "\n";
    return ret;
}

int current_best;

int solve(int n, int current_step) {
    //cout << "Solving: " << n << " " << current_best << " " << current_step << "\n";
    if (current_step >= current_best) {
        //cout << n << ": short-sircuit\n";
        return current_step + 33;
    }
    
    if (n == 1)
        return trace(1, 1, ' ', current_best, current_step);
    
    static unordered_map<int, int> steps; // from N
    int cached = steps[n];
    if (cached != 0)
        return trace(n, cached, ' ', current_best, current_step);

    const auto &divs = candidate_divisors(n);
    if (divs.empty()) {
        int cnt = solve(n-1, current_step+1);
        return trace(n-1, 1 + cnt, '#', current_best, current_step);
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
    //steps[n] = ret;
    return trace(n, ret, '*', current_best, current_step);
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
