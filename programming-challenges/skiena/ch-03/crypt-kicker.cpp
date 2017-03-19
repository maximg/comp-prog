// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=submit_problem&problemid=784&category=

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <array>
#include <iterator>
#include <cassert>
using namespace std;

using iterator_t = vector<string>::const_iterator;

class Mapping {
    static constexpr size_t N_CHAR = 26;
    array<char, 26> forward_ = {0}; // to clear
    array<char, 26> back_    = {0}; // to cypher
    size_t count = 0;

    size_t idx(char c) { return c - 'a'; }
public:
    bool empty() const { return count == 0; }
    bool add(char from, char to) {
        if (forward_[idx(from)] == 0 && back_[idx(to)] == 0) {
            forward_[idx(from)] = to;
            back_[idx(to)]      = from;
            ++count;
            return true;
        }
        return forward_[idx(from)] == to;
    }
    char operator[](char c) {
        assert(forward_[idx(c)]);
        return forward_[idx(c)];
    }
};

bool map_word(const string &word, const string &dword, Mapping &m)
{
    assert (word.size() == dword.size());
    const char *pF = word.c_str();
    const char *pT = dword.c_str();
    while (*pF) {
        if (!m.add(*pF++, *pT++))
            return false;
    }
    return true;
}    

// DFS with recursion
Mapping find_mapping(iterator_t word, const iterator_t &w_end,
                       const vector<string> &dict,
                       const Mapping &mapping)
{
    if (word == w_end) return mapping;
    for (const auto &dword: dict) {
        if (dword.size() > word->size()) continue;
        if (dword.size() < word->size()) break;
        Mapping m(mapping);
        if (map_word(*word, dword, m)) {
            
            Mapping mret = find_mapping(word+1, w_end, dict, m);
            if (!mret.empty()) return mret;
        }
    }
    return Mapping();
}

void sortDescending(vector<string> &v) {
    sort(begin(v), end(v), [](const string &a, const string &b){
        return a.size() > b.size();
    });    
}

int main() {
    string str;
    int dict_size{0};
    cin >> dict_size;
    getline(cin, str); // consume endl
    
    vector<string> dict;
    dict.reserve(dict_size);
    for (int i = 0; i < dict_size; ++i) {
        getline(cin, str);
        dict.push_back(str);
    }
    // Sort dictionary and input sentence in size descending order,
    // betting on the fact that longer words are less requent and
    // have a better chance of having repeating letters
    sortDescending(dict);

    while (true) {
        getline(cin, str);
        if (!cin) break;

        istringstream iss(str);
        vector<string> words{istream_iterator<string>{iss},
                             istream_iterator<string>{}};
        sortDescending(words);
        
        auto mapping = find_mapping(words.begin(), words.end(), dict, Mapping());
        bool is_found = !mapping.empty();
        for (const auto c: str) {
            if (c == ' ') cout << c;
            else if (is_found) cout << mapping[c];
            else cout << '*';
        }
        cout << endl;
    }
    return 0;
}
