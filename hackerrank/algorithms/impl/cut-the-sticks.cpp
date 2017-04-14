#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n{0}, x{0};
    cin >> n;
    int remains = n;
    vector<int> xs;
    xs.reserve(n);
    while (n-- > 0) {
        cin >> x;
        xs.push_back(x);
    }
    sort(xs.begin(), xs.end());
    auto group_end = xs.begin();
    while (remains > 0) {
        cout << remains << endl;
        auto group_start = group_end;
        while ( group_end != xs.end() && *group_end == *group_start) {
            ++group_end;
            --remains;
        }
    }
    return 0;
}
