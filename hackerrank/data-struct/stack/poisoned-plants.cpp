#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Incorrect solution
// Does not pass this TC:

//17
//20 5 6 15 2 2 17 2 11 5 14 5 10 9 19 12 5

int max_days{0};
int days{0};
int tail{0};
int group_tail{0};

void add(int x) {
    cout << x << ": ";
    if (x <= tail) {
        tail = x;
        group_tail = x;
        max_days = max(max_days, days);
        days = 0;
        cout << "reset\n";
        return;
    }
    if (days == 0) ++days;
    if (x > group_tail) {
        group_tail = x;
    } else {
        group_tail = tail;
        ++days;
    }
    cout << days << " " << group_tail << endl;
}

int main() {
    size_t n{0};
    cin >> n;
    int x{0};
    cin >> tail;
    for (size_t i=1; i < n; ++i) { cin >> x; add(x); }
    
    max_days = max(max_days, days);
    cout << max_days << endl;
    return 0;
}

