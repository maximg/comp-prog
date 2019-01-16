// https://www.hackerrank.com/challenges/equal/problem

#include <iostream>
#include <vector>

using namespace std;

vector<int> splits(1010, -1);

int split(int delta) {
    if (splits[delta] < 0) {
        if (delta >= 5)
            splits[delta] = 1+split(delta-5);
        else
            // no need to check for delta >= 2, guaranteed by prefilled splits
            splits[delta] = 1+split(delta-2);
    }
    return splits[delta];
}
int main(int argc, char* argv[]) {
    splits[0] = 0;
    splits[1] = 1;
    splits[2] = 1;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int v_min = 1000;
        vector<int> v(n, 0);
        for (int i=0; i<n; ++i) {
            cin >> v[i];
            v_min = min(v_min, v[i]);
        }

        int min_count = 10000 * 1000;
        for (int comp=0; comp < 3; comp++) {
            int count=0;
            for (int i=0; i<n; ++i)
                count += split(v[i] - v_min);
            min_count = min(min_count, count);
            --v_min;
        }

        cout << min_count << "\n";
    }
}