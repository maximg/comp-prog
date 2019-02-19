#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<int> plusOne(vector<int> &A);
};

vector<int> Solution::plusOne(vector<int> &A) {

    vector<int> number(A.rbegin(), A.rend());

    int zeros = 0;
    int carry = 1;
    for (int& dig: number) {
        if (carry == 1) {
            if (dig < 9) {
                dig += 1; 
                carry = 0;
            }
            else {
                dig = 0;
                carry = 1;
            }
        }
        zeros = (dig == 0) ? (zeros + 1) : 0;
    }
    if (carry != 0)
        number.push_back(1);
    else
        number.resize(number.size() - zeros);

    return vector<int>(number.rbegin(), number.rend());
}

int main() {

    vector<int> vv{ 9, 9, 9};
    for (int v: Solution::plusOne(vv))
        cout << v << ", ";
    cout << endl;
}