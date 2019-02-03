// https://codeforces.com/problemset/problem/1108/C

// In string of chars RGB find minimum number of changes
// to make the string 'nice' - distances between all same letters 
// are divisible by 3. Like RGBRGBRGB

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    int n;
    scanf("%d", &n);
    char s[200010];
    scanf("%s", s);

    // Brute force: each letter sequence can start at offset 0, 1 or 2
    // Calculate the number of mismatches for each case.
    // O(9 * n)

    int R[3], G[3], B[3];
    for (int i = 0; i < 3; i++) {
        R[i] = G[i] = B[i] = 0;
        for (int j = i; j < n; j += 3) {
            R[i]++;
            G[i]++;
            B[i]++;
            if (s[j] == 'R') R[i]--;
            if (s[j] == 'G') G[i]--;
            if (s[j] == 'B') B[i]--;
        }
    }

    // Now find the minimum of possible 6 ways to change the string.
    // Use a helper array to capture the best sequence.

    int perms[3] = {0, 1, 2};
    char seq[3];
    int min_changes = n+1;
    do {
        int changes = R[perms[0]] + G[perms[1]] + B[perms[2]];
        if (changes < min_changes) {
            min_changes = changes;
            seq[perms[0]]='R';
            seq[perms[1]]='G';
            seq[perms[2]]='B';
        }
    }
    while (next_permutation(perms, perms+3));

    // Generate the result string using a helper array

    cout << min_changes << endl;
    for (int i = 0, j=0; i < n; ++i) {
        s[i] = seq[j];
        j = ++j % 3;
    }
    cout << s << endl;
}