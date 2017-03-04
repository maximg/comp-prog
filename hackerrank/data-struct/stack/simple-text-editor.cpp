#include <cmath>
#include <cstdio>
#include <cassert>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

enum class command_t {
    APPEND = 1,
    DELETE = 2,
    PRINT  = 3,
    UNDO   = 4
};

int main() {
    int q{0};
    cin >> q;
    
    string buffer;
    stack<function<void(string&)>> undo_stack;
    for (int i = 0; i < q; ++i) {
        int cmd{0};
        cin >> cmd;
        switch (static_cast<command_t>(cmd)) {
            case command_t::APPEND: {
                string str;
                cin >> str;
                buffer += str;
                size_t count = str.size();
                undo_stack.push([count](string &s){
                   s.resize(s.size() - count);
                });
                break;
            }
            case command_t::DELETE: {
                size_t count{0};
                cin >> count;
                string tail = buffer.substr(buffer.size() - count);
                undo_stack.push([tail](string &s){
                   s += tail;
                });
                buffer.resize(buffer.size() - count);
                break;
            }
            case command_t::PRINT: {
                size_t index{0};
                cin >> index;
                cout << buffer[index-1] << endl;
                break;
            }
            case command_t::UNDO: {
                assert(!undo_stack.empty());
                const auto action = undo_stack.top();
                undo_stack.pop();
                action(buffer);
                break;
            }
            default:
                assert(false);
        }
        //cout << "buffer: [" << buffer << "]\n"; 
    }
    return 0;
}
