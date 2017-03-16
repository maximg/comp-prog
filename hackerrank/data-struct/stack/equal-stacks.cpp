#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/challenges/equal-stacks

int main() {
    int count[3];
    cin >> count[0] >> count[1] >> count[2];
    deque<int> stack[3];
    int sum[3] = {0};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < count[i]; ++j) {
            int x;
            cin >> x;
            stack[i].push_back(x);
            sum[i] += x;
        }
    }

    while (sum[0] != sum[1] || sum[1] != sum[2]) {
        int tallest = 0;
        if (sum[1] > sum[0]) {
            tallest = 1;
        }
        if (sum[2] > sum[1]) {
            tallest = 2;
        }
        sum[tallest] -= stack[tallest].front();
        stack[tallest].pop_front();
    }
    cout << sum[0] << endl;
    return 0;
}