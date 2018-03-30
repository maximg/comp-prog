
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=970

#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

struct Vertex;

struct Edge {
    Vertex *target;
    Edge *next;
};

struct Vertex {
    string word;
    Edge *edges;
    int rank;
};

using Graph = unordered_map<string, Vertex>;

bool one_letter_diff(const string &a, const string &b) {
    if (a.length() != b.length()) return false;
    int cnt{0};
    const char *pa{a.c_str()}, *pb{b.c_str()};
    for (int i = 0; i < a.length(); ++i) {
        if (*pa++ != *pb++) {
            if (cnt++ > 0) return false;
        }
    }
    return true;
}

void link(Graph &graph, const string &word, Vertex &vertex) {
    const auto it = graph.find(word);
    if (it != graph.end()) {
        if (vertex.word > word) {
            it->second.edges = new Edge{ &vertex, it->second.edges};
            //cout << word << " -> " << vertex.word << endl;
        }
        else {
            vertex.edges = new Edge{ &(it->second), vertex.edges};
            //cout << vertex.word << " -> " << word << endl;
        }
    }
}

int dfs(Graph &graph, Vertex &vertex) {
    int rank{0};
    Edge *e = vertex.edges;
    while (e) {
        if (e->target->rank < 0) {
            e->target->rank = dfs(graph, *(e->target));
        }
        rank = max(rank, e->target->rank + 1);
        e = e->next;
    }
    return rank;
}

int main() {
    Graph graph;
    vector<string> words;
    while (!cin.eof()) {
        string word; cin >> word;
        graph.insert({word, {word, nullptr, -1}});
        words.push_back(word);
    }

    // find all one-letter removals / insertions
    // we are only looking for lexicographically ordered pairs
    for (auto &entry: graph) {
        auto &word = entry.second.word;
        for (int i = 0; i < word.length(); ++i) {
            string modified = word;
            modified.erase(i, 1);
            link(graph, modified, entry.second);
        }
    }

    // find all 1-letter replacements
    for (int i = 0; i < words.size() - 1; ++i) {
        for (int j = i + 1; j < words.size(); ++j) {
            if (one_letter_diff(words[i], words[j])) {
                const auto it = graph.find(words[i]);
                link(graph, words[j], it->second);
            }
        }
    }

    // use DFS to find the longest ladder
    int max_rank{0};
    for (auto &entry: graph) {
        auto &vertex = entry.second;
        if (vertex.rank >= 0) continue;
        vertex.rank = dfs(graph, vertex);
        max_rank = max(max_rank, vertex.rank);
        //cout << vertex.word << " " << vertex.rank << endl;
    }

    cout << max_rank + 1 << endl;
}
