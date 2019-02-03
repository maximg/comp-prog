// https://codeforces.com/contest/1111/problem/B


#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

uint32_t a[100010];

int main(int argc, char* argv[]) {
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);

    uint64_t sum = 0;
    for(int i=0; i<n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    sort(a, a+n);

    // For each point we calculate what is the average reached if
    // all points before that were dropped and all remaining points
    // were maximized. The max value reached this way is the answer. 
    uint64_t cur_sum = sum;
    uint64_t n_rem = n;
    uint64_t to_give = min( uint64_t(k) * n_rem, uint64_t(m));    
    double max_avg = double(cur_sum + to_give) / n_rem;

    for (int i=0; (i < n-1) && m; ++i) {

        // Drop this item
        cur_sum -= a[i];
        --n_rem;
        --m;

        // final average obtained by distributing remaining tokens
        uint64_t to_give = min( uint64_t(k) * n_rem, uint64_t(m));    
        double final_avg = double(cur_sum + to_give) / n_rem;

        if (final_avg > max_avg)
            max_avg = final_avg;
    }

    printf("%.12f\n", max_avg);

    return 0;    
}
