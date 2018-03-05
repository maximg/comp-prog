
// https://www.hackerrank.com/challenges/direct-connections/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t; cin >> t;
    while (t-- > 0) {
        int n; cin >> n;
        vector<pair<int, int> > cities(n); // coord, pop
        for (int i = 0; i < n; ++i) cin >> cities[i].first;
        for (int i = 0; i < n; ++i) cin >> cities[i].second;
        /*
        sort(cities.begin(), cities.end(), [](const pair<int, int> &l, const pair<int, int> &r) {
            return l.first < r.first;
        });
        */
        int64_t cnt{0};
        for (int i = 0; i < n-1; ++i) {
            for (int j = i+1; j < n; ++j) {
                cnt += max(cities[i].second, cities[j].second) * (abs(cities[i].first - cities[j].first));
            }
        }
        cout << cnt % 1000000007 << endl;
    }
    
    return 0;
}
