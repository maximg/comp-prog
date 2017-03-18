// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=submit_problem&problemid=784&category=

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <iterator>
using namespace std;

using mapping_t = unordered_map<char, char>;
using mapped_t = unordered_set<char>;
using iterator_t = vector<string>::const_iterator;

mapping_t find_mapping(iterator_t word, const iterator_t &w_end,
                       const vector<string> &dict,
                       const mapping_t &mapping, const mapped_t &mapped)
{
    iterator_t dword = dict.begin();

    // Skip all longer words
    while (word->size() < dword->size()) {
        ++dword;
        if (dword == dict.end()) return mapping_t();
    }

    while (dword != dict.end()) {
        // Do we have a matching word in the dictionary?
        if (word->size() > dword->size()) return mapping_t();

        mapping_t ret(mapping);
        mapped_t upd_mapped(mapped);
        const char* pd = dword->c_str();
        for (const auto c: *word) {
            const auto it = ret.find(c);
            const auto it2 = mapped.find(*pd);
            if (it == ret.end() && it2 == upd_mapped.end()) {
                ret[c] = *pd;
                upd_mapped.insert(*pd);
            }
            else if (it == ret.end() || it->second != *pd) {
                ++dword;
                ret.clear();
                break;
            }
            ++pd;
        }
        if (!ret.empty()) {
            if (++word == w_end) return ret;
            // mapping ok, try next word
            else return find_mapping(word, w_end, dict, ret, upd_mapped);
        };
    }

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
    sort(dict.begin(), dict.end(), [](const string &a, const string &b){
        return a.size() > b.size();
    });
    //cout << dict[0] << endl;
    while (true) {
        getline(cin, str);
        if (!cin) break;

        istringstream iss(str);
        vector<string> words{istream_iterator<string>{iss},
                             istream_iterator<string>{}};
        sort(words.begin(), words.end(), [](const string &a, string auto &b){
            return a.size() > b.size();
        });
        
        auto mapping = find_mapping(words.begin(), words.end(), dict, mapping_t(), mapped_t());
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