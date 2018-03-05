
// https://www.hackerrank.com/challenges/jim-and-the-skyscrapers/problem

#include <cmath>
#include <cstdio>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

size_t cnt{0};
stack<pair<int, size_t> > groups;

void add(int h) {
    while (!groups.empty() && h > groups.top().first) {
        if (groups.top().second > 1)
            cnt += (groups.top().second - 1) * groups.top().second / 2;
        groups.pop();
    }
    if (!groups.empty() && h == groups.top().first) ++groups.top().second;
    else groups.push({h, 1});
}

int main() {
    int n; cin >> n;

    while (n-- > 0) {
        int h; cin >> h;
        add(h);
    }
    add(10000000); // greater than any valid skyscraper
    
    cout << 2 * cnt << endl;
    return 0;
}
