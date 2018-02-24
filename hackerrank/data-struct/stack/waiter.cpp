#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/challenges/waiter/problem

void calc_primes(vector<int> &primes, size_t q) {
    primes.reserve(q);    
    primes[0] = 2;
    size_t idx = 1;
    for (int cand = 3; idx < q; ++cand) {
        for (size_t j = 0; j < idx && primes[j] * primes[j] <= cand; ++j ) {
            if ((cand % primes[j]) == 0)
                goto next_cand;
        }
        primes[idx++] = cand;
    next_cand:
        ;
    }
}

int main() {
    size_t n, q;
    cin >> n >> q;

    vector<int> primes;
    calc_primes(primes, q);
    
    stack<int> a, a0;
    while (n-- > 0) {
        int t; cin >> t;
        a.push(t);
    }
    
    stack<int> *pa = &a, *pa0 = &a0;
    vector<stack<int> > bs(q);
    for (size_t idx = 0; idx < q; ++idx) {
        int prime = primes[idx];
        while (!pa->empty()) {
            if ((pa->top() % prime) == 0) {
                bs[idx].push(pa->top());
            } else {
                pa0->push(pa->top());
            }
            pa->pop();
        }
        swap(pa, pa0);
    }
    
    for (size_t idx = 0; idx < q; ++idx) {
        while (!bs[idx].empty()) {
            cout << bs[idx].top() << endl;
            bs[idx].pop();
        }
    }    
    while (!pa->empty()) {
        cout << pa->top() << endl;
        pa->pop();
    }
    
    return 0;
}
