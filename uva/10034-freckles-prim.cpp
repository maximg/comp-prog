// https://uva.onlinejudge.org/external/100/10034.pdf

#include <iostream>
#include <limits>
#include <vector>
#include <cmath>

using namespace std;

inline
double sq(double x) { return x*x; }

void runCase() {
    int N; cin >> N;
    vector<double> x(N), y(N);
    vector<vector<double>> dist(N, vector<double>(N, 0));    // dist between every 2 nodes

    for (int i=0; i < N; ++i) {
        cin >> x[i] >> y[i];
        for (int j=0; j < i; ++j) {
            dist[i][j] = dist[j][i] = sqrt(sq(x[i]-x[j]) + sq(y[i]-y[j]));
        }
    }

    double minDist = 0.0;
    vector<bool> seen(N);
    vector<double> primDist(N, std::numeric_limits<double>::max());
    int v = 0;  // starting point
    while (!seen[v]) {
        seen[v] = true;
        for (int i=0; i < N; ++i) {
            if (!seen[i] && primDist[i] > dist[v][i])
                primDist[i] = dist[v][i];
        }
        double minPrimDist = std::numeric_limits<double>::max();
        for (int i=0; i < N; ++i) {
            if (!seen[i] && minPrimDist > primDist[i]) {
                minPrimDist = primDist[i];
                v = i;
            }
        }
        if (!seen[v])
            minDist += minPrimDist;
    }
    cout << minDist << endl;
}

int main() {
    cout.setf(ios::fixed); cout.setf(ios::showpoint); cout.precision(2);
    int T;
    cin >> T;
    while (T--) {
        runCase();
        if (T)
            cout << endl;
    }
    return 0;
}
