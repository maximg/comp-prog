// https://www.hackerrank.com/challenges/coin-change/problem

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
    int n, m, c;
    cin >> n >> m;
    vector<long long> ways(n+1, 0);
    ways[0] = 1;
    for (int i=0; i < m; ++i) {
        cin >> c;
        //cout << c << ": ";
        vector<long long> new_ways(n+1, 0);
        for (int j=0; j <= n; ++j) {
            new_ways[j] = ways[j];
            if (j >=c)
                new_ways[j] += new_ways[j-c];

            //cout << new_ways[j] << " ";
        }
        //cout << "\n";
        ways = new_ways;
    }
    cout << ways[n] << "\n";
}
