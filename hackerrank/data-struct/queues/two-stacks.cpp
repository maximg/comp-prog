// https://www.hackerrank.com/challenges/queue-using-two-stacks

#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

stack<int> head;
stack<int> tail;

void enqueue(int v) {
    tail.push(v);
}

int peek() {
    if (head.empty()) {
        while (!tail.empty()) {
            head.push(tail.top());
            tail.pop();
        }
    }
    return head.top();
}

int dequeue() {
    int v = peek();
    head.pop();
    return v;
}

int main() {
    int q{0};
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int cmd{0};
        cin >> cmd;
        switch(cmd) {
            case 1: {
                int v{0};
                cin >> v;
                enqueue(v);
                break;
            }
            case 2: {
                dequeue();
                break;
            }
            case 3: {
                cout << peek() << endl;
                break;
            }
        } 
    }
    return 0;
}
