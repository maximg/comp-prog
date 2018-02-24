#include <cmath>
#include <cstdio>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/challenges/maximum-element/problem

int main() {
    size_t n; cin >> n;
    stack<int> vals, maxs;
    while (n-- > 0) {
        int q; cin >> q;
        switch (q) {
            case 1: {
                int x; cin >> x;
                vals.push(x);
                if (maxs.empty() || x >= maxs.top()) maxs.push(x);
                break;
            }
            case 2: {
                if (maxs.top() == vals.top()) maxs.pop();
                vals.pop();
                break;
            }
            case 3: {
                cout << maxs.top() << endl;
                break;
            }
        }
    }
    return 0;
}
