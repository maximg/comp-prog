
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=970

#include <cmath>
#include <vector>
#include <set>
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

struct Dumper {
    int indent{0};
    void enter(const Vertex &v) {
        cout << string(indent, ' ') << v.word << endl;
        indent += 2;        
    }
    void trace_child(const Vertex &v) {
        cout << string(indent, ' ') << v.word << " " << v.rank << endl;
    }
    void leave(const Vertex &v, int rank) {
        cout << string(indent, ' ') << "=> " << v.word << " " << rank << endl;
        indent -= 2;
    }
} dumper;


int dfs(Graph &graph, Vertex &vertex) {
    int rank{0};
    Edge *e = vertex.edges;
    //dumper.enter(vertex);
    while (e) {
        if (e->target->rank < 0) {
            e->target->rank = dfs(graph, *(e->target));
        } else {
            //dumper.trace_child(*e->target);
        }
        rank = max(rank, e->target->rank + 1);
        e = e->next;
    }
    //dumper.leave(vertex, rank);
    return rank;
}

int main() {
    Graph graph;
    vector<string> words;
    while (!cin.eof()) {
        string word; cin >> word;
        if (word.empty()) continue;
        graph.insert({word, {word, nullptr, -1}});
        words.push_back(word);
    }

    // link together all words which reduce to the same word by
    // dropping a letter
    unordered_map<string, set<string> > reduced;
    for (auto &entry: graph) {
        auto &word = entry.second.word;
        for (int i = 0; i < word.length(); ++i) {
            string replaced{word};
            replaced[i] = '-';
            reduced[replaced].insert(word);
            string removed{word};
            removed.erase(i, 1);
            if (graph.find(removed) != graph.end())
                reduced[replaced].insert(removed);
        }
    }

    // now words in all non-trivial groups should be linked in
    // lexicographical order
    for (auto &entry: reduced) {
        if (entry.second.size() < 2) continue;
        auto w1 = entry.second.begin();
        auto w2 = entry.second.begin(); ++w2;
        while (w2 != entry.second.end()) {
            const auto it1 = graph.find(*w1);
            const auto it2 = graph.find(*w2);
            it1->second.edges = new Edge{ &(it2->second), it1->second.edges};
            ++w1;
            ++w2;
        }
    }

    // use DFS to find the longest ladder
    int max_rank{0};
    for (auto &entry: graph) {
        auto &vertex = entry.second;
        if (vertex.rank >= 0) continue;
        vertex.rank = dfs(graph, vertex);
        max_rank = max(max_rank, vertex.rank);
    }

    cout << max_rank + 1 << endl;
}
