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
    cout << "divs(" << n << "): ";
    dump(ret);
    return divisors[n];
}

int trace (int n, int ret, char c, int current_best, int current_step) {
    cout << n << ": " << ret << " " << c << " " << current_best << " " << current_step << "\n";
    return ret;
}

// FIXME: need to finish short-circuiting when the search is not useful anymore
int current_best;

int solve(int n, int current_step, bool allow_sc) {
    if (allow_sc && current_step >= current_best) {
        cout << "short-sircuit\n";
        return INT_MAX;
    }
    
    if (n == 1)
        return trace(1, 1, ' ', current_best, current_step);
    
    static unordered_map<int, int> steps; // from N
    int cached = steps[n];
    if (cached != 0 && cached != INT_MAX)
        return trace(n, cached, ' ', current_best, current_step);

    const auto &divs = candidate_divisors(n);
    if (divs.empty())
        return trace(n-1, 1 + solve(n-1, current_step+1, false), '#', current_best, current_step);

    int min_steps = INT_MAX;
    for (auto k: divs) {
        min_steps = min(min_steps, solve(k, current_step+1, true));
        if (current_step + min_steps < current_best)
            current_best = current_step + min_steps;
    }
    min_steps = min(min_steps, solve(n-1, current_step+1, true));
    if (current_step + min_steps < current_best)
        current_best = current_step + min_steps;
    steps[n] = min_steps + 1;
    return trace(n, min_steps + 1, '*', current_best, current_step);
}

int main() {
    int q{0};
    cin >> q;
    for (int i = 0; i < q; ++i) {
        current_best = INT_MAX;
        int n {0};
        cin >> n;
        cout << solve(n, 1, true) << "\n";
    }
    return 0;
}
