
// https://www.hackerrank.com/challenges/qheap1/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using Heap = vector<int>;

void percUp(Heap &heap, size_t idx) {
    while (idx > 0) {
        size_t parent = (idx - 1) / 2;
        if (heap[parent] < heap[idx])
            return;
        swap(heap[parent], heap[idx]);
        idx = parent;
    }
}

// 0
// 1          2
// 3    4     5      6
// 7 8  9 10  11 12  13 14

size_t minChild(Heap &heap, size_t idx) {
    size_t child1 = idx * 2 + 1;
    if (child1 == heap.size() - 1) return child1;
    if (heap[child1] < heap[child1+1])
        return child1;
    return child1 + 1;
} 

void percDown(Heap &heap, size_t idx) {
    while (idx * 2 + 1 < heap.size() ) {
        size_t mc = minChild(heap, idx);
        if (heap[idx] <= heap[mc])
            return;
        swap(heap[idx], heap[mc]);
        idx = mc;
    }
}


void add(Heap &heap, int v) {
    heap.push_back(v);
    percUp(heap, heap.size() - 1);
}

void remove(Heap &heap, int v) {
    size_t idx = distance(heap.begin(), find(heap.begin(), heap.end(), v));
    if (idx == heap.size()-1) {
        heap.resize(heap.size() - 1);
        return;
    }
    heap[idx] = heap.back();
    heap.resize(heap.size() - 1);
    percUp(heap, idx);
    percDown(heap, idx);
}

int main() {
    size_t q; cin >> q;
    
    Heap heap;
    while (q--) {
        int cmd; cin >> cmd;
        switch (cmd) {
            case 1: {
                int x; cin >> x;
                add(heap, x);
                break;
            }
            case 2: {
                int x; cin >> x;
                remove(heap, x);
                break;
            }
            case 3: {
                cout << heap[0] << endl;
                break;
            }
        }
        cout << ">> ";
        for (auto x: heap) cout << x << " ";
        cout << endl;
    }
    return 0;
}
