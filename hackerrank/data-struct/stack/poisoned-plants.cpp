#include <cmath>
#include <cstdio>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

https://www.hackerrank.com/challenges/poisonous-plants/forum

int max_days{0};
stack<pair<int, int> > st;

void add(int x) {
    if (!st.empty()) {
        if (x > st.top().first) {
            st.push({x, 1});
            max_days = max(max_days, 1);
            return;
        }
        int cmax{0};
        while (!st.empty() && st.top().first >= x) {
            cmax = max(cmax, st.top().second);
            st.pop();
        }
        if (!st.empty()) {
            st.push({x, cmax + 1});
            max_days = max(max_days, cmax + 1);
        }
    }
    if (st.empty()) {
        st.push({x, 0});
    }    
}

int main() {
    size_t n; cin >> n;
    for (size_t i=0; i < n; ++i) { int x; cin >> x; add(x); }

    cout << max_days << endl;
    return 0;
}
