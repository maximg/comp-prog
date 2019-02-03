// https://codeforces.com/contest/1111/problem/A


#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    char a[1010], b[1010];
    scanf("%s\n", a);
    scanf("%s\n", b);

    string vowels = "aoeui";
    for (int i=0; ; ++i) {
        if (!a[i] && !b[i]) {
            cout << "Yes" << endl;
            break;
        }
        bool isVowelA = vowels.find(a[i]) != string::npos;
        bool isVowelB = vowels.find(b[i]) != string::npos;
        if (!a[i] || !b[i] || isVowelA != isVowelB) {
            cout << "No" << endl;
            return 0;
        }
    }
    return 0;    
}
