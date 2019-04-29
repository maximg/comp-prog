
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

struct Vertex {
    vector<int> edges;
};

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

int main() {

    vector<string> words;
    while (cin) {
        string str;
        getline(cin, str);
        if (!str.empty())
            words.emplace_back(str);
    }

    vector<Vertex> g;
    g.reserve(words.size());
    for (int i = 0; i < words.size(); ++i) {
        g.emplace_back(Vertex{{}});
        for (int j = i + 1; j < words.size(); ++j) {
            if (is_edit_step(words[i], words[j]))
                g.back().edges.emplace_back(j);
        }
    }

    for (int i = 0; i < words.size(); ++i) {
        cout << words[i] << ":";
        for (const auto& idx: g[i].edges)
            cout << " " << words[idx];
        cout << endl;
    }

    // find connected components and for each find the longest step ladder

    return 0;
}