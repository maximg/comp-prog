
// https://www.hackerrank.com/challenges/castle-on-the-grid/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

using point = pair<int, int>; // x, y

class route {
public:
    explicit route(point p) : m_tail(p) {}
    void append(point p) { m_tail = p; ++m_length; }
    const point &last() const { return m_tail; }
    size_t length() const { return m_length; }
private:
    point m_tail;
    size_t m_length{1};    
};

size_t n; // grid size
vector<string> grid;
queue<route> bfs;

void mark(point p) {
    grid[p.second][p.first] = 's';
}

bool is_marked(point p) {
    return grid[p.second][p.first] == 's';
}

bool is_blocked(point p) {
    return grid[p.second][p.first] == 'X';
}

void add(route r, const point &p) {
    if (is_marked(p)) return;
    r.append(p);
    mark(p);
    bfs.push(r);
}

size_t find_route(const point &start, const point &goal) {
    if (start == goal) return 0;
    
    bfs.push(route(start));
    mark(start);
    while (!bfs.empty()) {
        const route &r = bfs.front();
        point p = r.last();
        if (p == goal) return r.length() - 1;
        for (int i = p.first - 1;  i >= 0 && !is_blocked({i, p.second}); --i) add(r, {i, p.second});
        for (int i = p.first + 1;  i < n  && !is_blocked({i, p.second}); ++i) add(r, {i, p.second});
        for (int i = p.second - 1; i >= 0 && !is_blocked({p.first, i});  --i) add(r, {p.first, i});
        for (int i = p.second + 1; i < n  && !is_blocked({p.first, i});  ++i) add(r, {p.first, i});
        bfs.pop();
    }
    
    return 0;
}

int main() {
    cin >> n; grid.resize(n);
    for (size_t i = 0; i < n; ++i) cin >> grid[i];
    
    int x, y;
    cin >> y >> x; point start{x, y}; 
    cin >> y >> x; point goal{x, y};
    
    cout << find_route(start, goal) << endl;
    return 0;
}
