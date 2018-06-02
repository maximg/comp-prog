
// https://codejam.withgoogle.com/2018/challenges/0000000000000130/dashboard

#include <iostream>

using namespace std;

int guess(int lower, int upper) {
    return (lower + upper + 1) / 2;
}

int main(int argc, char *argv[]) {
    int T; cin >> T;

    while (T-- > 0) {
        int A, B; cin >> A >> B;
        int N; cin  >> N;

        while (N-- > 0) {
            int g = guess(A, B);
            cout << g << endl;
            string w; cin >> w;
            if (w.find("TOO_SMALL") != string::npos) { A = g; continue; }
            if (w.find("TOO_BIG") != string::npos) { B = g - 1; continue; }
            if (w.find("CORRECT") != string::npos) break;
            if (w.find("WRONG_ANSWER")) return 1;
        }
    }
}