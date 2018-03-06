// http://www.spoj.com/problems/ANARC09A

#include <iostream>
#include <string>
using namespace std;

int main() {
    for (size_t tc = 1;; ++tc) {
        string s; cin >> s;
        if (s[0] == '-') break;

        size_t lefts{0};
        size_t flips{0};
        for (char c: s) {
            if (c == '{') {
                ++lefts;
            }
            else if (c == '}') {
                if (lefts > 0) {
                    --lefts;
                } else {
                    ++flips;
                    ++lefts;
                }
            }
        }
        flips += lefts / 2;
        cout << tc << ". " << flips << endl;
    }
    return 0;
}
