#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n{0}, lonely{0};
    cin >> n;
    while (n-- > 0) {
        int k{0};
        cin >> k;
        lonely ^= k;
    }
    cout << lonely << endl;
    return 0;
}
