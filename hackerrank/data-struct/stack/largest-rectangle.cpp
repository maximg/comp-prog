#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

struct Area {
    const int h, left;
    int64_t area_at(int right) const { return h * (right - left); }
};

int64_t max_area{0};
stack<Area> areas;

void add_building(int i, int h) {
    int left{i};
    while (!areas.empty() && (h < areas.top().h)) {
        max_area = max(areas.top().area_at(i), max_area);
        left = areas.top().left;
        areas.pop();
    }
    if (areas.empty() || h > areas.top().h) {
        areas.push({h, left});
    }
}

int main() {
    size_t n; cin >> n;
    for (size_t i = 0; i < n; ++i) {
        int h{0}; cin >> h;
        add_building(i, h);
    }
    add_building(n, 0);
    cout << max_area << endl;
    return 0;
}
