// https://leetcode.com/problems/longest-word-in-dictionary/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution {
    struct Node {
        char c;
        unordered_map<char, Node*> children;
        bool isWord = false;
    };

    string longest;
    Node root;
public:
    string longestWord(vector<string>& words) {
        root.isWord = true;

        sort(words.begin(), words.end(), [](const string& a, const string& b){
            return a.length() < b.length() || 
                (a.length() == b.length() && a < b);
        });
        for (auto w: words)
            check(w);

        return longest;
    }

    void check(const string& s) {
        Node *curP = &root;
        bool canMake = true;
        for (size_t i = 0; i < s.length(); ++i ) {
            Node& cur = *curP;
            const auto it = cur.children.find(s[i]);
            if (it == cur.children.end()) {
                Node* nn = new Node;
                nn->c = s[i];
                nn->isWord = i+1 == s.length();
                curP = cur.children[s[i]] = nn;
            }
            else
                curP = it->second;
            canMake = canMake && curP->isWord;
        }
        if (canMake && longest.length() < s.length())
            longest = s;
    }
};

int main()
{
    vector<string> words = { "d","do","dog","p","pe","pen","peng","pengu","pengui","penguin","e","el","ele","elep","eleph","elepha","elephan","elephant" };
    cout << Solution().longestWord(words) << endl;
    return 0;
}
