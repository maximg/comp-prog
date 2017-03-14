#include <iostream>
#include <cstddef>

using namespace std;    

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
        Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            }
            else {
                Node* cur;
                if(data <= root->data){
                    cur = insert(root->left, data);
                    root->left = cur;
                }
                else{
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/

    // recursive
    int height1(Node* root) {
        return max(root->left  ? (1 + height1(root->left)) : 0,
                   root->right ? (1 + height1(root->right)) : 0);
    }

    // Gosh I need a stack
    class stack {
      public:
        stack() : head(nodes) {}
        void push(Node* v) { *head++ = v; }
        Node* pop() { return *(--head); }
        bool empty() const { return head == nodes; }
      private:
        Node* nodes[10000];
        Node** head;
    };

    // iterative
    int height(Node* root) {
        if (!root) return 0;
        int depth = 0, max_depth = 0;
        
        Node* prev = root;
        Node* current = root;
        stack path;
        while (true) {
            bool from_left = prev == current->left;
            bool from_right = prev == current->right;
            bool from_top = !from_left && !from_right;
            bool go_left = from_top && current->left;
            bool go_right = (!go_left || from_left) && !from_right && current->right;
            bool go_up = !go_left && !go_right;
            prev = current;
            if (go_left) {
                path.push(current);
                ++depth;
                current = current->left;
            }
            if (go_right) {
                path.push(current);
                ++depth;
                current = current->right;
            }
            if (go_up) {
                if (!current->left && !current->right) {
                    max_depth = max(depth, max_depth);
                }
                if (path.empty()) {
                    return max_depth;
                }
                current = path.pop();
                --depth;
            }
        }
    }
}; //End of Solution

int main() {
    Solution myTree;
    Node* root = NULL;
    int t;
    int data;

    cin >> t;

    while(t-- > 0){
        cin >> data;
        root = myTree.insert(root, data);
    }
    int height = myTree.height(root);
    cout << height;

    return 0;
}
