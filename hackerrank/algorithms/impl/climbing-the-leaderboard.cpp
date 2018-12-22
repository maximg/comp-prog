// https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(int argc, char* argv[]) {

    int n;
    cin >> n;
    vector<int> scores;
    scores.reserve(n);

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (scores.empty() || x != scores.back())
            scores.push_back(x);
    }

    int m;
    cin >> m;
    auto end = scores.end();
    for (int i = 0; i < m; ++i) {
        int score;
        cin >> score;
        const auto pos = upper_bound(scores.begin(), end, score, greater_equal());
        cout << distance(scores.begin(), pos) + 1 << endl;
        end = pos;
    }
}