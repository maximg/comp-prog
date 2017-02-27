#include <iostream>
#include <vector>
using i = int;

std::vector<std::vector<int>> vec(4);

void wr(i x, i y) {
//    std::cout << "(" << x << "," << y << ")";
    static int cnt = 0;
    vec[x][y] = cnt++;
}

// Does not handle the innermost row/column properly

void sol(i hor, i vert) {
    i x = 0; i y = 0;
    while ((hor > 0) || (vert > 0)) {
        for(i c = 0; c < hor; ++c, ++x) wr(x,y);
        --vert; --x; ++y;
        for(i c = 0; c < vert; ++c, ++y) wr(x,y);
        --hor; --x; --y;
        for(i c = 0; c < hor; ++c, --x) wr(x,y);
        --vert; ++x; --y; 
        for(i c = 0; c < vert; ++c, --y) wr(x,y);
        --hor; ++x; ++y;
    }
}

int main(int args, char**argv) {
  for (auto &v: vec) {
    v = std::vector<int>(3);
  }
  sol(4,3);
  for (auto v: vec) {
    for (auto val: v) {
    std::cout << val << " ";
    }
    std::cout << "\n";
  }
}

