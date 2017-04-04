#include <cmath>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string chars(string s) {
    set<char> ch;
    for (char c: s) {
        if (c) { ch.insert(c); }
    }
    return string(ch.begin(), ch.end());
}

size_t check(char a, char b, string s) {
    const char *p = s.c_str();
    size_t cnt = 0;
    while (*p) {
        while (*p) {
            if (*p == b) { return 0; }
            if (*p++ == a) { ++cnt; break; }
        }
        while (*p) {
            if (*p == a) { return 0; }
            if (*p++ == b) { ++cnt; break; }
        }
    }
    return cnt;
}

int main() {
    int length{0};
    string s;
    cin >> length >> s;
    getline(cin, s);
    s = s.substr(0, length);
    
    string alphabet = chars(s);
  
    if (alphabet.size() < 2) {
        cout << 0 << endl;
        return 0;
    }

    size_t max_len = 0;
    for (int i = 0; i < alphabet.size() - 1; ++i) {
        for (int j = i + 1; j < alphabet.size(); ++j) {
            max_len = max(max_len, check(alphabet[i], alphabet[j], s));
            max_len = max(max_len, check(alphabet[j], alphabet[i], s));
        }
    }
    cout << max_len << endl;
    return 0;
}
