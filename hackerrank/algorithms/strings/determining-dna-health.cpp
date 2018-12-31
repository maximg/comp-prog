// https://www.hackerrank.com/challenges/determining-dna-health/problem

// Useful: https://almondtools.github.io/stringbench/chart.html#latest

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <limits>
#include <unordered_map>
#include <queue>

using namespace std;


namespace aho_corasick {

// based on https://www.toptal.com/algorithms/aho-corasick-algorithm

constexpr size_t UNSET_ID = numeric_limits<size_t>::max();

struct node {
    unordered_map<char, node*> children;
    bool leaf = false;
    node* parent = nullptr;
    char parent_char;
    node* suffix = nullptr;
    node* end_word = nullptr;
    size_t word_id = UNSET_ID;
};

list<node> trie;
node* root = nullptr;
size_t next_word_id = 0;
vector<size_t> word_counts;

void init() {
    trie.clear();
    trie.push_back({});
    root = &trie.back();
    next_word_id = 0;
}

size_t add_string(const string& s) {
    node* cur_node = root;
    for (char c: s) {
        if (cur_node->children.find(c) == cur_node->children.end()) {
            trie.push_back({
                {},
                false,
                cur_node,
                c,
                nullptr,
                nullptr,
                UNSET_ID
            });
            cur_node->children[c] = &trie.back();
        }
        cur_node = cur_node->children[c];
    }
    cur_node->leaf = true;
    if (cur_node->word_id == UNSET_ID)
        cur_node->word_id = next_word_id++;
    return cur_node->word_id;
}

void update_links(node* nd) {
    if (nd == root) {
        nd->suffix = root;
        nd->end_word = root;
        return;
    }

    if (nd->parent == root) {
        nd->suffix = root;
        if (nd->leaf)
            nd->end_word = nd;
        else
            nd->end_word = nd->suffix->end_word;
        return;
    }

    node* cur_better_node = nd->parent->suffix;
    char ch_node = nd->parent_char;
    for (;;) {
        const auto it = cur_better_node->children.find(ch_node);
        if (it != cur_better_node->children.end())
        {
            nd->suffix = it->second;
            break;
        }
        if (cur_better_node == root)
        { 
            nd->suffix = root;
            break;
        }
        cur_better_node = cur_better_node->suffix;
    }

    if (nd->leaf)
        nd->end_word = nd;
    else
        nd->end_word = nd->suffix->end_word;
}

void prepare() {
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* cur_node = q.front();
        q.pop();
        update_links(cur_node);
        for (auto e: cur_node->children)
            q.push(e.second);
    }
}


void process(const string& text) {

    word_counts.clear();
    word_counts.resize(next_word_id);

    node* current_state = root;
    for (char c: text) {
        for (;;) {
            const auto it = current_state->children.find(c);
            if (it != current_state->children.end())
            {
                current_state = it->second;
                break;
            }

            if (current_state == root)
                break;

            current_state = current_state->suffix;
        }

        node* check_state = current_state;
        for (;;) { 
            check_state = check_state->end_word;

            if (check_state == root)
                break;
            
            //cout << "id: " << check_state->word_id << endl;
            ++word_counts[check_state->word_id];
    
            check_state = check_state->suffix;
        }
    }
}

} // aho_corasick

vector<string> genes;
vector<size_t> weights;
vector<size_t> word_ids;

int main(int argc, char* argv[])
{
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
    for (size_t i = 0; i < n; ++i) {
        word_ids.push_back(aho_corasick::add_string(genes[i]));
        //cout << "added " << genes[i] << endl;
    }
    aho_corasick::prepare();
    cout << "prepared" << endl;

    size_t minHealth = numeric_limits<size_t>::max();
    size_t maxHealth = 0;
    size_t cases;
    cin >> cases;
    for (int i = 0; i < cases; ++i) {
        size_t begin, end;
        string strand;
        size_t health = 0;
        cin >> begin >> end >> strand;

        aho_corasick::process(strand);
//        cout << "processed " << strand << endl;

        for (int j = begin; j <= end; ++j) {
            // cout << "j: " << j << endl;
            // cout << "word id " << word_ids[j] << endl;
            // cout << "counts " << counts[word_ids[j]] << endl;
            health += aho_corasick::word_counts[word_ids[j]] * weights[j];
        }
        minHealth = min(minHealth, health);
        maxHealth = max(maxHealth, health);
    }

    cout << minHealth << " " << maxHealth << endl;

    return 0;
}
