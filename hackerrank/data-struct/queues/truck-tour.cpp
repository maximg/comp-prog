#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    size_t n{0};
    cin >> n;

    vector<int64_t> delta(2*n);

    for (size_t i = 0; i < n; ++i) {
        int64_t p{0}, d{0};
        cin >> p >> d;
        delta[i] = delta[n + i] = p - d;
    }

    int64_t fuel = 0;
    size_t start = 0;
    size_t i = 0;

    while (i < n && start < n) {
        fuel += delta[start + i];
        if (fuel < 0) {
            cout << "reset at " << start << "  " << i << " " << fuel << "\n";
            start += i + 1;
            fuel = 0;
            i = 0;
        }
        else {
            ++i;
        }
    }
    cout << start << endl;

    return 0;
}
