#include <cmath>
#include <cstdio>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <memory>
using namespace std;

// https://www.hackerrank.com/challenges/merging-communities

using people_vec_t = vector<list<int>*>;

void merge(people_vec_t &people, int ii, int jj) {
    if (people[ii] == people[jj]) {
        return;
    }
    if (people[jj]->size() > people[ii]->size()) {
        swap(ii, jj);
    }

    const auto tmp = people[jj];
    for (const auto k: *tmp) {
        people[k] = people[ii];
    }
    people[ii]->splice(people[ii]->end(), *tmp);
    delete tmp;
}

int main() {
    int n{0}, q{0};
    cin >> n >> q;
    //cout << "N: " << n << " Q: " << q << endl;

    people_vec_t people;

    for (int i = 0; i < n; ++i) {
        people.push_back(new list<int>(1, i));
    }

    for (int i = 0; i < q; ++i) {
        char cmd;
        cin >> cmd;
        if (cmd == 'M') {
            int ii{0}, jj{0};
            cin >> ii >> jj;
            //cout << "Cmd M: " << ii << " " << jj << endl;
            merge(people, ii - 1, jj - 1);
            //cout << "Size ii: " << people[ii-1]->size() << " size jj: " << people[jj-1]->size() << endl;
        } else if (cmd == 'Q') {
            int ii{0};
            cin >> ii;
            //cout << "Cmd Q: " << ii << endl;
            cout << people[ii - 1]->size() << endl;
        }
    }

    return 0;
}
