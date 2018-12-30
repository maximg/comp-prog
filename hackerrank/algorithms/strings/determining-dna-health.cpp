// https://www.hackerrank.com/challenges/determining-dna-health/problem

// Useful: https://almondtools.github.io/stringbench/chart.html#latest

#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <unordered_map>
#include <queue>

using namespace std;


vector<string> genes;
vector<size_t> weights;

namespace aho_corasick {

// based on https://www.toptal.com/algorithms/aho-corasick-algorithm

using node_id = size_t;
constexpr size_t UNSET_ID = numeric_limits<size_t>::max();

struct node {
    unordered_map<char, node_id> children;
    bool leaf = false;
    node_id parent = UNSET_ID;
    char parent_char;
    node_id suffix_link = UNSET_ID;
    node_id end_word_link = UNSET_ID;
    vector<size_t> gene_ids;
    size_t single_id = UNSET_ID;
};

vector<node> trie;
size_t size = 0;
node_id root = 0;

void init() {
    trie.clear();
    size = 0;
    root = 0;

    trie.push_back({});
    ++size;
}

void add_string(const string& s, size_t gene_id) {
    node_id cur_node = root;
    for (char c: s) {
        if (trie[cur_node].children.find(c) == trie[cur_node].children.end()) {
            trie.push_back({
                {},
                false,
                cur_node,
                c,
                UNSET_ID,
                UNSET_ID,
                {},
                UNSET_ID
            });
            trie[cur_node].children[c] = size;
            size++;
        }
        cur_node = trie[cur_node].children[c];
    }
    trie[cur_node].leaf = true;
    trie[cur_node].gene_ids.push_back(gene_id);
}

void calc_suff_link(node_id nd) {
    if (nd == root) {
        trie[nd].suffix_link = root;
        trie[nd].end_word_link = root;
        return;
    }

    if (trie[nd].parent == root) {
        trie[nd].suffix_link = root;
        if (trie[nd].leaf)
            trie[nd].end_word_link = nd;
        else
            trie[nd].end_word_link = trie[trie[nd].suffix_link].end_word_link;
        return;
    }

    node_id cur_better_node = trie[trie[nd].parent].suffix_link;
    char ch_node = trie[nd].parent_char;
    for (;;) {
        const auto it = trie[cur_better_node].children.find(ch_node);
        if (it != trie[cur_better_node].children.end())
        {
            trie[nd].suffix_link = it->second;
            break;
        }
        if (cur_better_node == root)
        { 
            trie[nd].suffix_link = root;
            break;
        }
        cur_better_node = trie[cur_better_node].suffix_link;
    }

    if (trie[nd].leaf)
        trie[nd].end_word_link = nd;
    else
        trie[nd].end_word_link = trie[trie[nd].suffix_link].end_word_link;
}

void prepare() {
    queue<node_id> q;
    q.push(root);
    while (!q.empty()) {
        node_id cur_node = q.front();
        q.pop();
        calc_suff_link(cur_node);
        for (auto e: trie[cur_node].children)
            q.push(e.second);
    }

    //size_t count_one = 0;
    // for (auto nd: trie) {
    //     if (nd.gene_ids.size() == 1) {
    //         //count_one++;
    //         nd.single_id = nd.gene_ids[0];
    //     }
    // }
    //cout << "Unique genes: " << count_one << endl;
}

size_t get_health(node_id nd, size_t begin, size_t end) {
    // if (trie[nd].single_id <= end && trie[nd].single_id >= begin)
    //     return weights[trie[nd].single_id];

    size_t health = 0;
    for (auto id: trie[nd].gene_ids)
        if (id >= begin && id <= end)
            health += weights[id];
    return health;
}

size_t process(size_t begin, size_t end, const string& text) {

    node_id current_state = root;
    size_t health = 0;
    for (char c: text) {
        for (;;) {
            const auto it = trie[current_state].children.find(c);
            if (it != trie[current_state].children.end())
            {
                current_state = it->second;
                break;
            }

            if (current_state == root)
                break;

            current_state = trie[current_state].suffix_link;
        }

        node_id check_state = current_state;
        for (;;) { 
            check_state = trie[check_state].end_word_link;

            if (check_state == root)
                break;
            
            health += get_health(check_state, begin, end);
    
            check_state = trie[check_state].suffix_link;
        }
    }

    return health;
}

} // aho_corasick

/*
size_t calcHealth(size_t begin, size_t end, const string& strand)
{
    aho_corasick::init();
    for (int i = begin; i <= end; i++)
        aho_corasick::add_string(genes[i], weights[i]);
    aho_corasick::prepare();
    return aho_corasick::process(strand);
;
}
*/

int main(int argc, char* argv[])
{
    /*
    aho_corasick::init();
    aho_corasick::add_string("a", 1);
    aho_corasick::add_string("ab", 1);
    aho_corasick::add_string("bab", 1);
    aho_corasick::add_string("bc", 1);
    aho_corasick::add_string("bca", 1);
    aho_corasick::add_string("c", 1);
    aho_corasick::add_string("caa", 1);
    aho_corasick::prepare();
    auto count = aho_corasick::process("abccab");
    cout << count << endl;
    return 0;
    */

    size_t n;
    cin >> n;

    string s;
    for (size_t i = 0; i < n; ++i) {
        cin >> s;
        genes.push_back(s);
    }
    size_t w;
    for (size_t i = 0; i < n; ++i) {
        cin >> w;
        weights.push_back(w);
    }
    
    aho_corasick::init();
    for (size_t i = 0; i < n; ++i)
        aho_corasick::add_string(genes[i], i);
    aho_corasick::prepare();

    size_t minHealth = numeric_limits<size_t>::max();
    size_t maxHealth = 0;
    size_t cases;
    cin >> cases;
    for (int i = 0; i < cases; ++i) {
        size_t begin, end;
        string strand;
        size_t health;
        cin >> begin >> end >> strand;
        //for (int j = 0; j < 20; ++j)
            health = aho_corasick::process(begin, end, strand);
        minHealth = min(minHealth, health);
        maxHealth = max(maxHealth, health);
    }

    cout << minHealth << " " << maxHealth << endl;

    return 0;
}
