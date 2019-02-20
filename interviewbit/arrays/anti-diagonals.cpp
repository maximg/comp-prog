
// https://www.interviewbit.com/problems/anti-diagonals/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<vector<int> > diagonal(vector<vector<int> > &A);
};

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int N = A.size();
    vector<vector<int> > out;
    // top part
    for (int r = 0; r < N; ++r) {
        out.push_back({});
        for (int el = 0; el <= r; ++el) {
            //cerr << r << " " << el << " " << A[el][r-el] <<endl;
            out.back().push_back(A[el][r-el]);

        }
    }
    // bottom part
    for (int r = 1; r < N; ++r) {
        out.push_back({});
        for (int el = N-1; el >= r; --el) {
            //cerr << r << " " << el << " " << A[N + r - 1 - el][el] <<endl;
            out.back().push_back(A[N + r - 1 - el][el]);
        }
    }
    return out;
}

int main() {

    vector<vector<int>> vvv{ {1, 2, 3},{4, 5, 6}, {7,8,9}};
    for (auto& vv: Solution::diagonal(vvv)) {
        for (int v: vv )
            cout << v << ", ";
        cout << endl;
    }
    cout << endl;
    return 0;
}
