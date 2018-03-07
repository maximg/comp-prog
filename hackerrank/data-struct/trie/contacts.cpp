
// https://www.hackerrank.com/challenges/contacts/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node {
    node *next;
    node *children;
    char data;
    size_t count;
};

node *find_child(node *n, char c) {
    node *cur = n->children;
    while (cur) {
        if (cur->data == c) return cur;
        cur = cur->next;
    }
    return nullptr;    
}

void add(node *root, const string &arg) {
    node *cur = root;
    ++(root->count);
    for (auto c: arg) {
        node *next = find_child(cur, c);
        if (!next) {
            node *tmp = cur->children;
            cur->children = new node{cur->children, nullptr, c, 0};
            next = cur->children;
        }
        cur = next;
        ++(cur->count);
    }
}

size_t get_count(node *root, const string &arg) {
    node *cur = root;
    size_t cnt{0};
    for (auto c: arg) {
        cur = find_child(cur, c);
        if (!cur) return 0;
        cnt = cur->count;
    }
    return cnt;
}

int main() {
    size_t n; cin >> n;
    string tmp; getline(cin, tmp);
    
    node root{ nullptr, nullptr, ' ', 0};
    while (n-- > 0) {
        string op, arg;
        getline(cin, op, ' ');
        getline(cin, arg);
        if (op == "add") add(&root, arg);
        if (op == "find") cout << get_count(&root, arg) << endl;
    }
        
    return 0;
}
