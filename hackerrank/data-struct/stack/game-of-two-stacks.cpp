#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

size_t solve() {
    size_t n, m;
    int x, sum{0}, t;
    cin >> n >> m >> x;
    vector<int> sums_a, sums_b;
    sums_a.push_back(0);
    for (size_t i=0; i < n; ++i) {
        cin >> t;
        sum += t;
        if (sum <= x) {
            sums_a.push_back(sum);
            // cout << sum << " ";
        }
    }
    // cout << "\n";
    sum = 0;
    sums_b.push_back(0);
    for (size_t i=0; i < m; ++i) {
        cin >> t;
        sum += t;
        if (sum <= x) {
            sums_b.push_back(sum);
            // cout << sum << " ";
        }
    }
    // cout << "\n";

    size_t nn = sums_a.size() - 1;
    size_t mm = sums_b.size() - 1;
    size_t score{nn + mm};
    size_t p = min(nn, mm);
    size_t q = max(nn, mm);
    for (; score > p; --score) {
        for (size_t i = score - mm; i <= nn; ++i) {
            size_t j = score - i;
            //cout << score << ":" << i << " " << j << "\n";
            //continue;
            if (sums_a[i] + sums_b[j] <= x)
                return score;
        }
    }

    for (; score > p; --score) {
        for (int i = score - mm; i <= nn; ++i) {
            int j = score - i;
            if (i >= 0 && j >= 0 && i <= nn && j <= mm) {
            //cout << score << ":" << i << " " << j << "\n";
            //continue;

    //            cout << i << " " << j << " " << sums_a[i-1] + sums_b[j-1] << "\n";
                if (sums_a[i] + sums_b[j] <= x)
                    return score;
            }
        }
    }


    for (; score > 0; --score) {
        for (size_t i = 0; i <= score; ++i) {
            size_t j = score - i;
            //cout << i << " " << j << " " << sums_a[i] + sums_b[j] << "\n";
            //cout << score << ":" << i << " " << j << "\n";
            //continue;

            if (sums_a[i] + sums_b[j] <= x)
                return score;
        }
    }
    return 0;
}

int main() {
    size_t games; cin >> games;
    for(; games > 0; --games) {
        cout << solve() << endl;
    }
    return 0;
}
