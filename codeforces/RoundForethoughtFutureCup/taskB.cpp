// https://codeforces.com/contest/1146/problem/B


#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]) {
    char t[100010];
    scanf("%s\n", t);

    int lenT = strlen(t);

    char *pt = t + lenT;
    for (; pt != t; --pt)
        if (*(pt-1) == 'a')
            break;

    char s[100010];
    char *ps = s;
    for (char *p = t; p != pt && *p; ++p)
        if (*p != 'a')
            *ps++ = *p;
    *ps = '\0';

    int lenS = distance(s, ps);
    int k = distance(t, pt);
    int tail2 = lenT - lenS - k;
    if (tail2 < 0 || (tail2 & 1)) {
        cout << ":(" << endl;
        return 0;
    }

    for (int i = 0; (i < tail2 / 2) && *pt; ++i)
        *ps++ = *pt++;
    *ps = '\0';

    if (0 != strcmp(s, pt))
        cout << ":(" << endl;
    else {
        *pt = '\0';
        cout << t << endl;
    }

    return 0;    
}
