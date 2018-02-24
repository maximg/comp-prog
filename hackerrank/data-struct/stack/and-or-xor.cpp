#include <cmath>
#include <cstdio>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/challenges/and-xor-or/problem

int main() {
    size_t n; cin >> n;
    
    int max_s{0};
    stack<int> ranges;
    for (size_t i = 0; i < n; ++i) {
        int x; cin >> x;
        
        while (!ranges.empty() && x <= ranges.top()) {
            max_s = max(max_s, x ^ ranges.top());
            ranges.pop();
        }
        if (!ranges.empty()) {
            max_s = max(max_s, x ^ ranges.top());
        }
        ranges.push(x);
    }
    cout << max_s << endl;
    return 0;
}
