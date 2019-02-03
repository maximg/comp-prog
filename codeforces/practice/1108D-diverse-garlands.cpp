// https://codeforces.com/problemset/problem/1108/D

// In string of chars RGB find minimum number of changes
// to make the string 'diverse' - no 2 sequential chars are the same.

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    int n;
    scanf("%d", &n);
    char s[200010];
    scanf("%s", s);

    // Just go through the string and when seeing a duplicate
    // choose the color which does not match either of the neighbors.

    int min_changes = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i-1]) {
            ++min_changes;
            for (int j=0; j < 3; ++j) {
                static char patt[4] = "RGB";
                if (patt[j] != s[i-1] && (i == n-1 || patt[j] != s[i+1])) {
                    s[i] = patt[j];
                    break;
                }
            }
        }
    }

    cout << min_changes << endl;
    cout << s << endl;
}