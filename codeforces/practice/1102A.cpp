// http://codeforces.com/problemset/problem/1102/A

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int n, m; cin >> n;

    // 4 items can be matched: a + d, b + c
    if ((n % 4) == 0) m = 0;

    // k*4 + 1 items: match 1
    if ((n % 4) == 1) m = 1;

    // k*4 + 2 items: match a + 1 = b
    if ((n % 4) == 2) m = 1;

    // k*4 + 3 items: match 1 + 2 = 3
    if ((n % 4) == 3) m = 0;
    
    cout << m << "\n";

    return 0;
}
