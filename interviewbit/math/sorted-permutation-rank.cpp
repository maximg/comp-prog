// https://www.interviewbit.com/problems/sorted-permutation-rank/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static
    int findRank(string A);
};

int countPredc(int val, vector<int>& vals) {
    vals.push_back(val);
    sort(vals.begin(), vals.end());
    auto it = lower_bound(vals.begin(), vals.end(), val);
    return distance(vals.begin(), it);
}

// for 1st letter, there will be K1 * (n-1)! variants,
// where K1is the number of letters preceding the first
// for 2nd letter, there will be k2 * (n-2)! variants
// and so on

int Solution::findRank(string A) {
    int n = A.length();
    constexpr int MOD = 1000003;

    vector<int> facts(n, 1);
    int fact = 1;
    for (int i = 1; i < n; ++i) {
        facts[i] = fact = (fact * i) % MOD;
        cout << i << " " << facts[i] << endl;
    }

    int preds = 0;
    for (int i = 0; i < n-1; ++i) {
        int predch = 0;
        for (int j=i+1; j < n; ++j)
            predch += (A[i] > A[j] ? 1 : 0);

        preds = (preds % MOD + (predch * facts[n - i - 1]) % MOD) % MOD;
        cout << i << " " << preds << endl;
    }

    return preds % 1000003 + 1;
}


int main() {
    cout << Solution::findRank("GXPLN") << endl;
}