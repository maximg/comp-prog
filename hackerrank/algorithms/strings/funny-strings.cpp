#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isFunny(const string &s) {
    if (s.length() < 2) return false;

    size_t j = s.length() - 1;
    for (size_t i = 0; i < (s.length() / 2); ++i, --j ) {
        if (abs((int)s[i] - (int)s[i+1]) != abs((int)s[j] - (int)s[j-1])) {
            return false;
        }
    }
    return true;
}
            
int main() {
    int t{0};
    string s;
    cin >> t;
    getline(cin, s);
    for (int i = 0; i < t; ++i) {
        getline(cin, s);
        cout << (isFunny(s) ? "Funny" : "Not Funny") << endl;
    }
    return 0;
}
