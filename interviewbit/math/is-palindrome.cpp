// https://www.interviewbit.com/problems/palindrome-integer/

#include <iostream>

using namespace std;

class Solution {
public:
    static
	int isPalindrome(int A);
};

int Solution::isPalindrome(int A) {
    if (A < 0)
        return 0;
    
    int reverse = 0;
    for (int tA = A; tA; tA /= 10) {
    	// failed to check for int overflow here
    	// Still works correctly and does not report int overflow.. why?
        reverse = reverse * 10 + tA % 10;
    }
    if (reverse == A) return 1;
    return 0;
}

int main() {
    cout << Solution::isPalindrome(INT_MAX) << endl;
}