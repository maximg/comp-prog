// https://uva.onlinejudge.org/external/100/10039.pdf

#include <iostream>
#include <unordered_map>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

struct Edge {
    int to;     // arrival city, index in G
    int depart; // departure time
    int arrive; // arrival time 
};

using Graph = vector<vector<Edge>>;

// return arrival time to goal or -1 if no route
int dijkstra(const Graph& G, int start, int goal, int earliest) {
    int N = G.size();
    vector<bool> seen(N);
    vector<int> arrTime(N, std::numeric_limits<int>::max());

    int v = start;
    arrTime[v] = earliest;
    while (!seen[v]) {
        seen[v] = true;
        for (const auto& conn: G[v]) {
            if (!seen[conn.to] 
                && conn.depart >= arrTime[v]
                && arrTime[conn.to] > conn.arrive) {

                arrTime[conn.to] = conn.arrive;
            }
        }

        v = 1;
        int currEarliest = std::numeric_limits<int>::max();
        for (int i=0; i < N; ++i) {
            if (!seen[i] && currEarliest > arrTime[i]) {
                currEarliest = arrTime[i];
                v = i;
            }
        }
    }
    return arrTime[goal] == std::numeric_limits<int>::max() ? -1 : arrTime[goal];
}

void runCase() {

    // number of nodes
    int N; cin >> N;

    // Read cities
    string name, name1;
    unordered_map<string, int> cities;  // name, index in G
    getline(cin, name); // swallow endl
    for (int i = 0; i < N; ++i) {
        getline(cin, name);
        //cout << name << endl;
        cities.emplace(name, i);
    }

    // Read graph
    Graph G(N);
    int T; cin >> T;
    for (int i = 0; i < T; ++i) {
        int S, t, t1; cin >> S;
        cin >> t >> name;
        for (int j = 1; j < S; ++j) {
            cin >> t1 >> name1;
            //cout << name << " " << t << " " << name1 << " " << t1 << endl;
            int idx = cities[name], idx1 = cities[name1];
            G[idx].emplace_back(Edge{idx1, t, t1});
            t = t1; name = name1;
        }
    }

    // Read departure and arrival
    int depTime; cin >> depTime;
    string from, to;
    cin >> from >> to;
    int origin = cities[from];
    int goal = cities[to];

    //cout << from << " " << to << " " << dep << endl;

    // Run Dijkstra for each possible train from the origin separately   
    int bestDeparture = -1;
    int bestArrival = std::numeric_limits<int>::max();
    for (const auto& conn: G[origin]) {
        if (conn.depart < depTime) continue;
        int arrival = dijkstra(G, conn.to, goal, conn.arrive);
        //cout << conn.to << " " << conn.arrive << " " << arrival << endl;
        if (arrival >= 0 && 
                (arrival < bestArrival || 
                (arrival == bestArrival && conn.depart > bestDeparture))) {
            bestDeparture = conn.depart;
            bestArrival = arrival;
        }
    }
    if (bestDeparture < 0) {
        cout << "No connection" << endl;
    }
    else {
        cout << "Departure " << setfill('0') << setw(4)
             << bestDeparture << " " << from << endl;
        cout << "Arrival   " << setfill('0') << setw(4)
             << bestArrival   << " " << to << endl;
    }
}

int main() {
    int T; cin >> T;
    for (int i = 0; i < T; ++i) {
        cout << "Scenario " << i+1 << endl;
        runCase();
        cout << endl;
    }
    return 0;
}