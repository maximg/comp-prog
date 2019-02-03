// http://codeforces.com/problemset/problem/1102/B

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int n, k, t;

    cin >> n >> k;

    pair<int,int> a[5010];
    int colors[5010];

    for (int i=0; i<n; ++i) {
        cin >> t;
        a[i] = make_pair(t, i);
    }

    sort(a, a+n);

    int last_a = -1;
    int run_start = -1;
    int color = 0;      // will add 1 on output
    for (int i=0; i<n; ++i) {
        if (a[i].first != last_a) {
            last_a = a[i].first;
            run_start = i;
        }
        if (i - run_start >= k) {
            cout << "NO\n";
            return 0;
        }

        colors[a[i].second] = color;
        color = (color + 1) % k;
    }

    cout << "YES\n";
    for (int i=0; i<n; ++i)
        cout << colors[i] + 1 << " ";
    cout << "\n";
}
