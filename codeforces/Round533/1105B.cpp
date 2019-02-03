
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int main(int argc, char* argv[]) {
    int n, k;
    scanf("%d %d\n", &n, &k);
    char s[200010];
    scanf("%[a-z]\n", s);

    vector<int> ranks(30, 0);

    int max_rank = 0;
    char last=' ';
    int run_len=0;
    for (int i=0; i<n; ++i) {
        if (s[i] != last) {
            last=s[i];
            run_len = 1;
        }
        else
            ++run_len;

        if (run_len == k) {
            ++ranks[last-'a'];
            run_len = 0;
            max_rank = max(max_rank, ranks[last-'a']);
        }
        //cout << last << " " << run_len << "\n";
    }

    cout << max_rank << "\n";

    return 0;
}