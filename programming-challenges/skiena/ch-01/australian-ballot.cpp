
// http://www.programming-challenges.com/pg.php?page=downloadproblem&probid=110108&format=html

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <memory>
#include <cctype>
using namespace::std;

using ballot_t = vector<int>;

struct candidate_t {
    int id;
    string name;
    vector<const ballot_t*> votes;
};

void process_case() {

    vector<candidate_t> cands;
    vector<ballot_t> ballots;
    set<int> eliminated;

    int n_cand{0};
    cin >> n_cand;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // skip 1 line
    for (int i = 0; i < n_cand; ++i) {
        string name;
        getline(cin, name);
        cands.push_back(candidate_t{i+1, name, vector<const ballot_t*>()});
        //cout << "cand: " << name << "\n";
    }

    while (true) {
        string str;
        getline(cin, str);
        if (str.empty()) break;

        stringstream ss(str);
        vector<int> ballot;
        for (int i = 0; i < n_cand; ++i) {
            int idx{0};
            ss >> idx;
            ballot.push_back(idx);
        }
        ballots.push_back(ballot);
    }

    for (const auto &b: ballots) {
        cands[b[0]-1].votes.push_back(&b);
    }

    // ones that got no top votes are eliminated automatically (not in the rules!)
    for (const auto c: cands) {
        if (c.votes.empty()) {
            eliminated.insert(c.id);
        }
    }

    while (true) {
        vector<const candidate_t*> ranking;
        for (const auto &c: cands) {
            //cout << "Cand: " << c.name << ", votes: " << c.votes.size() << "\n";
            if (!c.votes.empty()) {
                ranking.push_back(&c);
            }
        }

        sort(ranking.begin(), ranking.end(), [](const candidate_t* &a, const candidate_t* &b) {
            return a->votes.size() > b->votes.size();
        });

        //cout << "Best cand: " << ranking[0]->name << ", votes: " << ranking[0]->votes.size() << "\n";
        if (ranking[0]->votes.size() > ballots.size() / 2) {
            cout << ranking[0]->name << "\n";
            return;
        }
        if (ranking.front()->votes.size() == ranking.back()->votes.size()) {
            for (const auto c: ranking) {
                cout << c->name << "\n";
            }
            return;
        }

        size_t lowest_votes = ranking.back()->votes.size();
        for (auto it = ranking.rbegin(); it != ranking.rend(); ++it) {
            if ((*it)->votes.size() > lowest_votes) break;
            eliminated.insert((*it)->id);
            //cout << "Removed " << (*it)->id << "\n";
        }

        // redistribute votes for eliminated candidates
        // do not worry about ones eliminated in previous rounds, they have no votes
        for (const auto idx: eliminated) {
            //cout << "Removing cand " << idx << "\n"; 
            for (const auto &ballot: cands[idx-1].votes) {
                // FIXME: probably removing the eliminated candidates from the ballot
                // would be faster (could reverse the ballot and chop off the tail)
                //for (auto v : *ballot) cout << v << " ";
                //cout << "\n";
                const auto it = find_if(ballot->begin(), ballot->end(), [&eliminated](int v){
                    //cout << "Check " << v << "\n";
                    return eliminated.find(v) == eliminated.end();
                });
                //cout << "Giving votes to " << (*it) << "\n";
                cands[(*it)-1].votes.push_back(ballot);
            }
            cands[idx-1].votes.clear();
        }
    }
}

int main() {
    int n_cases{0};
    cin >> n_cases;
    for (int i = 0; i < n_cases; ++i) {
        if (i > 0) cout << "\n";
        process_case();
    }
    exit(EXIT_SUCCESS);
}
