// https://www.hackerrank.com/challenges/police-operation/problem

#include <iostream>
#include <vector>

using namespace std;

long long h; 

uint64_t min_f(int low, int high, std::function<uint64_t(int)> cost_f)
{
    if (high - low < 50) {
        uint64_t min_cost = cost_f(high);
        uint64_t max_cost = min_cost + h;
        for (int j=high-1; j >= low; --j) {
            uint64_t cost_j = cost_f(j);
            if (cost_j < min_cost)
                min_cost = cost_j;
            if (cost_j > max_cost)
                break;
        }
        return min_cost;
    }
    else {
        uint64_t cost_l = cost_f(low);
        uint64_t cost_h = cost_f(high);
        if (high - low == 1)
            return min(cost_l, cost_h);

        int m = low + (high-low) / 2;
        uint64_t cost_m = cost_f(m);
        if (cost_l < cost_m)
            return min_f(low, m, cost_f);
        else if (cost_h < cost_m)
            return min_f(m, high, cost_f);
        else
            return min(min_f(low, m, cost_f), min_f(m, high, cost_f));
    }
};


int main(int argc, char* argv[]) {

    int n; cin >> n;
    cin >> h;

    vector<int> pos(n+1, 0);
    for (int i=1; i <= n; ++i)
        cin >> pos[i];

    vector<uint64_t> costs(n+1, 0);
    costs[0] = 0;
    for (int i=1; i <= n; ++i) {
        costs[i] = min_f(1, i, [&](int k){
            uint64_t dist = pos[i] - pos[k];
            return costs[k-1] + h + dist*dist;
        });
    }

    cout << costs[n] << endl;
}
