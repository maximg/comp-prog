// https://practice.geeksforgeeks.org/problems/lcs-of-three-strings/0

#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>

using namespace std;

int L[105][105][105];
char s1[105], s2[105], s3[105];

int lcs(int n, int k, int m)
{
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int l = 0; l <= m; ++l) {

                if (i == 0 || j == 0 || l == 0)
                    L[i][j][l] = 0;
                else
                if (s1[i-1] == s2[j-1] && s1[i-1] == s3[l-1]) {
                    L[i][j][l] = 1 + L[i-1][j-1][l-1];
                    //printf("%d %d %d -- %c %c %c -- %d\n", i, j, l, s1[i-1], s2[j-1], s3[l-1], L[i][j][l]);
                }
                else
                    L[i][j][l] = max(L[i-1][j][l], 
                                 max(L[i][j-1][l], L[i][j][l-1]));
            }
        }
    }
    return L[n][k][m];
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k, m;
        scanf("%d %d %d\n", &n, &k, &m);
        scanf("%[a-z] %[a-z] %[a-z]\n", s1, s2, s3);

        assert(strlen(s1) == n);
        assert(strlen(s2) == k);
        assert(strlen(s3) == m);

        printf("%d\n", lcs(n, k, m));
    }
    return 0;
}