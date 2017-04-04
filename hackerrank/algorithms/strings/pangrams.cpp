#include <cctype>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string s;
    getline(cin, s);
    bool chars[256] = {false};
    for (auto c: s) {
        chars[(unsigned char)c] = true;
    }
    const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
    for (auto c: alphabet) {
        if (c && !chars[(unsigned char)c] && !chars[(unsigned char)toupper(c)]) {
            cout << "not pangram" << endl;
            return 0;
        }
    }
    cout << "pangram" << endl;
    return 0;
}
