// https://practice.geeksforgeeks.org/problems/distinct-substrings/0

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    for (int tc=0; tc < T; ++tc) {
        char s[110];
        scanf("%s", s);

        // Build the suffix array
        char* sa[110];
        int n = 0;
        for (char *p = s; *p; ++p)
            sa[n++] = p;

        // drop the last suffix as it is too short for 2-char pattern
        --n;
        sort(sa, sa+n, [](char* a, char* b) { return strcmp(a,b) < 0; });

        int count = 1;  // the first substring is always unique
        for (int i = 0; i < n-1; ++i) {
            // Now every time we see a different substring count it
            char* p1 = sa[i], *p2 = sa[i+1];
            if (p1[0] != p2[0] || p1[1] != p2[1])
                count++;
            //printf("%s %s\n", p1, p2);
        }

        printf("%d\n", count);
    }
    return 0;
}