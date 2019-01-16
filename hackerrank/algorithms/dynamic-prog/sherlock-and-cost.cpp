// https://www.hackerrank.com/challenges/sherlock-and-cost/problem

#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        int b_prev;
        cin >> b_prev;
        int sum0=0, sumM=0;

        for (int i=1; i<n; ++i) {
            int b; cin >> b;

            int sum0M = sum0 + (b - 1);
            int sumMM = sumM + abs(b - b_prev);

            sum0 = sumM + (b_prev - 1);
            sumM = max(sum0M, sumMM);
            b_prev = b;
        }
        cout << max(sum0, sumM) << "\n";
    }
}