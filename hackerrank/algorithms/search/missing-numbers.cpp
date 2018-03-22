
// https://www.hackerrank.com/challenges/missing-numbers/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector <int> missingNumbers(vector <int> arr, vector <int> brr) {
    vector<int> missing(100);
    int bmin{brr[0]};
    for (auto x: brr) {
        ++missing[x % 100];
        bmin = min(bmin, x);
    }
    for (auto x: arr)
        --missing[x % 100];
    
    vector<int> result;
    for (int x = bmin; x < bmin + 100; ++x) {
        if (missing[x % 100] > 0) result.push_back(x);
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int m;
    cin >> m;
    vector<int> brr(m);
    for(int brr_i = 0; brr_i < m; brr_i++){
       cin >> brr[brr_i];
    }
    vector <int> result = missingNumbers(arr, brr);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;

    return 0;
}
