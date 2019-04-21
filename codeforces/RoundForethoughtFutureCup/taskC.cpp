
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

void runTest() {
    int n;
    scanf("%d\n", &n);

    int diameter = 0;

    for (int mask = 1; mask < 1000; mask = (mask << 1)) {
        vector<int> a, b;
        for (int i = 0; i < n; ++i) {
            if (i & mask)
                a.push_back(i+1);
            else
                b.push_back(i+1);
        }
        if (a.empty() || b.empty())
            break;

        cout << a.size() << " " << b.size() << " ";
        for (auto e: a)
            cout << e << " ";
        for (auto e: b)
            cout << e << " ";
        cout << endl;
        cout.flush();

        int dist;
        scanf("%d", &dist);
        if (dist < 0) exit(0);
        diameter = max(diameter, dist);
    }

    cout << "-1 " << diameter << endl;
    cout.flush();
}

int main() {
    int T;
    scanf("%d\n", &T);
    while (T--)
        runTest();
    return 0;
}