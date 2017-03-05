// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=788

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace::std;

template<typename T>
bool is_even(T value) {
    return (value & 1) == 0;
}

int main() {
    vector<uint64_t> numbers;
    uint64_t k = 9;
    numbers.push_back(k);
    while (k <= UINT32_MAX) {
        k *= 2;
        numbers.push_back(k);
        k *= 9;
        numbers.push_back(k);
    }
    assert(numbers.back() > UINT32_MAX);
    while (true) {
        uint32_t n{ 0 };
        cin >> n;
        if (!cin) {
            break;
        }
        const auto it = find_if(numbers.begin(), numbers.end(), [n](uint64_t m) {
            return n <= m;
        });
        assert(it != numbers.end());
        cout << (is_even(distance(numbers.begin(), it)) ? "Stan" : "Ollie" ) << " wins.\n";
    }
	exit(EXIT_SUCCESS);
}
