
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int n; cin >> n;

    int v[1010];

    int vmin=100, vmax=1;
    for (int i=0; i<n; ++i) {
        cin >> v[i];
        vmin = min(vmin,v[i]);
        vmax = max(vmax,v[i]);
    }

    if (vmin == vmax) {
        cout << vmin << " " << 0 << "\n";
        return 0;
    }

    int min_t = 0;
    int min_cut = 110*1000;
    for (int t=vmin; t<vmax; ++t) {
        int cut = 0;
        for (int j=0; j<n; ++j)
            cut += max(0, abs(v[j] - t) - 1);
        if (cut < min_cut) {
            min_cut = cut;
            min_t = t;
        }
    }

    cout << min_t << " " << min_cut << "\n";

    return 0;
}
