
// https://www.hackerrank.com/challenges/tree-top-view/problem
/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

vector<int> lefts, rights;
int max_left{0}, max_right{0};
queue<pair<node*, int> > bfs;

void topView(node * root) {
    /*
    This is a different way to do it, one that is in line with 
    https://www.geeksforgeeks.org/print-nodes-top-view-binary-tree/
    
    bfs.push({root, 0});
    while(!bfs.empty()) {
        auto entry = bfs.front();
        bfs.pop();
        if (entry.second > max_right) {
            rights.push_back(entry.first->data);
            max_right = entry.second;
            cout << "R: " << entry.first->data << " " << entry.second << endl;
        }   
        if (entry.second < max_left) {
            lefts.push_back(entry.first->data);
            max_left = entry.second;
            cout << "L: " << entry.first->data << " " << entry.second << endl;
        }      
        if (entry.first->left)
            bfs.push({entry.first->left, entry.second-1});
        if (entry.first->right)
            bfs.push({entry.first->right, entry.second+1});
    }
    */
    for (node *n = root->right; n; n = n->right)
        rights.push_back(n->data);
    for (node *n = root->left; n; n = n->left)
        lefts.push_back(n->data);
    
    for (auto it = lefts.rbegin(); it != lefts.rend(); ++it)
        cout << *it << " ";
    cout << root->data << " ";
    for (auto it = rights.begin(); it != rights.end(); ++it)
        cout << *it << " ";
    cout << endl;
}
