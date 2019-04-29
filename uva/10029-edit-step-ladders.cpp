
// https://uva.onlinejudge.org/external/100/10029.pdf

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

bool is_edit_step(const string& a, const string& b) {
    if (a.size() - b.size() > 1 && b.size() - a.size() > 1)
        return false;

    int lenA = a.size();
    int lenB = b.size();
    int iA = 0, iB = 0;
    int diff_count = 0;
    while (iA < lenA && iB < lenB) {
        if (a[iA] == b[iB]) {
            ++iA; ++iB;
        }
        else {
            if (lenA > lenB)
                ++iA;
            else if (lenB > lenA)
                ++iB;
            else {
                ++iA; ++iB;
            }
            if (++diff_count > 1)
                return false;
        }
    }
    if (iA < lenA || iB < lenB)
        return diff_count == 0;
    else
        return diff_count == 1;
}

vector<string> words;
vector<int> dp;

int dfs(int i) {
    if (dp[i] > 0)
        return dp[i];

    dp[i] = 1;
    for (int j = i+1; j < words.size(); ++j) {
        if (is_edit_step(words[i], words[j])) {
            int longest = 1 + dfs(j);
            //cout << words[i] << ": " << longest << endl;
            dp[i] = max(dp[i], longest);
        }
    }
    return dp[i];
}

int main() {

    while (cin) {
        string str;
        getline(cin, str);
        if (!str.empty())
            words.emplace_back(str);
    }

    dp.resize(words.size(), -1);
    int max_ladder = 0;
    for (int i = 0; i < words.size(); ++i)
        max_ladder = max(max_ladder, dfs(i));

    cout << max_ladder << endl;

    return 0;
}