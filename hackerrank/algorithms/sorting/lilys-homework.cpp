// https://www.hackerrank.com/challenges/lilys-homework/problem

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

size_t countSwaps(vector<int> orig,
                  const vector<int> sorted,
                  const map<int, size_t> order)
{
    size_t count = 0;
    for (size_t idx = 0; idx < orig.size(); ++idx) {
        if (orig[idx] == sorted[idx]) continue;
        size_t iWrong = idx;                    // index of value out of place
        size_t iRight = order.at(sorted[iWrong]);  // index of value to be put here
        while (iRight != idx) {
            swap(orig[iWrong], orig[iRight]);
            iWrong = iRight;                    // wrong value is where the right was
            iRight = order.at(sorted[iWrong]);
            ++count;
        }
    }
    return count;
}

int main(int argc, char* argv[])
{
    size_t n;
    cin >> n;
    vector<int> orig;
    map<int, size_t> order;
    orig.reserve(n);

    int t;
    for (size_t pos = 0; pos < n; ++pos) {
        cin >> t;
        orig.push_back(t);
        order[t] = pos;
    }
    vector<int> sorted = orig;
    sort(sorted.begin(), sorted.end());

    size_t countAsc = countSwaps(orig, sorted, order);

    sort(sorted.begin(), sorted.end(), greater<int>());
    size_t countDesc = countSwaps(orig, sorted, order);

    cout << min(countAsc, countDesc) << endl;

    return 0;
}