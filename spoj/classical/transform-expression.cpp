// http://www.spoj.com/submit/ONP/

#include <iostream>
#include <string>
#include <stack>
#include <cassert>
using namespace std;

int prio(char c) {
    switch (c) {
        case '(': return -1;
        case '+': return 0;
        case '-': return 1;
        case '*': return 2;
        case '/': return 3;
        case '^': return 4;
        default: assert(false);
    }
    return 999; // never reached
}

int main() {
    int t; cin >> t;
    while (t-- > 0) {
        stack<char> ops;
        string s; cin >> s;
        for (const auto c: s) {
            switch (c) {
                case '(': {
                    ops.push(c);
                    break;
                }
                case ')': {
                    cout << ops.top();
                    ops.pop();
                    ops.pop();
                    break;
                }
                case '+':
                case '-':
                case '/':
                case '*':
                case '^': {
                    if (!ops.empty() && prio(c) < prio(ops.top())) {
                        cout << ops.top();
                        ops.pop();
                    }
                    ops.push(c);
                    break;
                }
                default: {
                    cout << c;
                    break;
                }
            }
        }
        while (!ops.empty()) {
            cout << ops.top();
            ops.pop();
        }
        cout << endl;
    }
    return 0;
}