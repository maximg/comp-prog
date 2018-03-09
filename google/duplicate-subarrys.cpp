
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// print Yes if an array contains duplicate subarrays

int main() {
    size_t n; cin >> n;

    if (n < 2) {
        cout << "No" << endl;
        return 0;
    }

    vector<int> v(n);
    vector<size_t> suff(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> v[i];
        suff[i] = i;
    }
    sort(suff.begin(), suff.end(), [&v, n](const size_t x, const size_t y){
        size_t ix = x, iy = y;
        for ( ; ix < n && iy < n; ++ix, ++iy) {
            if (v[ix] < v[iy]) return true;
            if (v[ix] > v[iy]) return false;
        }
        return iy < n;
    });

    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; suff[i]+j < n && suff[i+1]+j < n; ++j) {
            if (v[suff[i]+j] == v[suff[i+1]+j]) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}