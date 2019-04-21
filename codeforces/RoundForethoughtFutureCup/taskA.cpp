// https://codeforces.com/contest/1146/problem/0


#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]) {
    char a[1010];
    scanf("%s\n", a);

    int count = 0;
    for (char* p = a; *p; ++p)
        if (*p == 'a')
            ++count;

    cout << min((int)strlen(a), 2*count-1) << endl;
    return 0;    
}
