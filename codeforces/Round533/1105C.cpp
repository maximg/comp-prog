
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int main(int argc, char* argv[]) {
    int n, l, r;
    scanf("%d %d %d", &n, &l, &r);


    // Going backwards from r:
    // for r:
    // count(r-1, n-1, 3 - r % 3) + count(r-1, n, 0)
    //
    // This is O(n * (l-r)) = O (10^5 * 10^9) too much

    /*
        Items with the same remainder of 3 are equivalent,
        so we only need to check in how many ways we can
        populate 3 sets of items: ones with rem 0, ones with rem 1
        and ones with rem 2.

        So we can check how many candidates for each set we have,
        and then calculate how many ways we can pick them from each set.
        This involves calculating C(n,k) from 1 to 10000, only for
        combinations which produce a sum with required reminder.


        So we could do:
            N0 = how many numbers we have with rem 0
            N1 = same with rem 1
            N2 = same with rem 2

            for (i0 = 0 to n)
                for (i1 = 0 to n - i0)
                    i2 = n - i1 - i2
                        if ((i1 + i2 * 2) % 3 == 0)
                            sum += C(i0, N0) + C(i1, N1) + C(i2, N2)
    */
}
