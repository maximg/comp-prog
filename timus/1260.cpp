// http://acm.timus.ru/problem.aspx?space=1&num=1260

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

size_t sol(size_t n)
{
    static std::vector<int> sols(n + 1);

    auto sol_mem = [](auto n_){
        return sols[n_] ? sols[n_] : sols[n_] = sol(n_);
    };

    return (n == 0) ? 0ul
         : (n < 3) ? 1ul
         : sol_mem(n - 1) + sol_mem(n - 3) + 1;
}

int main()
{
    int n; cin >> n;
    cout << sol(n) << endl;
}
