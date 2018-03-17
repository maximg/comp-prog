
// https://www.hackerrank.com/challenges/find-the-median/problem

#include <bits/stdc++.h>

using namespace std;

int findMedian(vector <int> &arr) {
    sort(arr.begin(), arr.end());
    return arr[arr.size()/2];
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = findMedian(arr);
    cout << result << endl;
    return 0;
}
