// https://www.hackerrank.com/challenges/determining-dna-health/problem

#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

vector<string> genes;
vector<size_t> weights;

size_t calcHealth(size_t begin, size_t end, const string& strand)
{
    size_t health = 0;
    for (int i = begin; i <= end; i++) {
        auto& gene = genes[i];
        string::size_type pos = 0;
        while ((pos = strand.find(gene, pos)) != string::npos) {
            health += weights[i];
            ++pos;
        }
    }
    return health;
}

int main(int argc, char* argv[])
{
    size_t n;
    cin >> n;

    string s;
    for (size_t i = 0; i < n; ++i) {
        cin >> s;
        genes.push_back(s);
    }
    size_t w;
    for (size_t i = 0; i < n; ++i) {
        cin >> w;
        weights.push_back(w);
    }
    
    size_t minHealth = numeric_limits<size_t>::max();
    size_t maxHealth = 0;
    size_t cases;
    cin >> cases;
    for (int i = 0; i < cases; ++i) {
        size_t begin, end;
        string strand;
        cin >> begin >> end >> strand;
        size_t health = calcHealth(begin, end, strand);
        minHealth = min(minHealth, health);
        maxHealth = max(maxHealth, health);
    }

    cout << minHealth << " " << maxHealth << endl;

    return 0;
}
