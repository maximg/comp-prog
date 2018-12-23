
// https://www.hackerrank.com/challenges/non-divisible-subset/problem

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
        size_t n, k;
        cin >> n >> k;
        vector<size_t> bins(k, 0);

        // Map all input numbers to range 0..k
        // as (a+b) % k == ((a % k) + (b % k)) % k
        for (size_t i = 0; i < n; ++i) {
            int m;
            cin >> m;
            ++bins[m % k];
        }

        size_t ans = 0;

        // Only a single multiple of k, not more
        if (bins[0] > 0)
            ans += 1;

        // Any other bin except for k / 2 when k is even will only match
        // with the bin[k - i]. We will throw away the smaller of these 
        // bins, which is the same as taking the max.
        // Conviniently, if the other bin is 0 we can still take the max
        for (size_t i = 1; i < (k+1)/2; ++i) {
            ans += max(bins[i], bins[k-i]);
        }

        // Same as with a multiple of k, for an even k allow a single k/2
        if ((k % 2) == 0 && bins[k/2] > 0)
            ans += 1;

        cout << ans << endl;
}
