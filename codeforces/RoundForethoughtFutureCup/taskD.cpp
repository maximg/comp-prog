// https://codeforces.com/contest/1146/problem/D


#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int m, a, b;
vector<bool> reached;

uint64_t mark(int pos, int k) {
    assert (!reached[pos]);
    uint64_t count = 1;
    reached[pos] = 1;
    int pos1 = pos + a;
    if (pos1 <= k && !reached[pos1])
        count += mark(pos1, k);
    pos1 = pos - b;
    if (pos1 >= 0 && !reached[pos1])
        count += mark(pos1, k);
    return count;
};

int main(int argc, char* argv[]) {
    scanf("%d %d %d", &m, &a, &b);

    reached.resize(m+1);
    reached[0] = 1;

    uint64_t sum = 1;
    uint64_t lastSum = 1;
    for (int k = 1; k <= m; ++k) {
        if (k >= a && reached[k-a]) {
            lastSum += mark(k, k);
        }
        sum += lastSum;
        //if ((k % 1000) == 0)
            cout << k << " " << sum << " " << lastSum << endl;
        if (k > 10000)
            break;
    }

    cout << sum << endl;

    return 0;    
}
