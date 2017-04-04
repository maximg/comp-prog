/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/

// https://www.hackerrank.com/challenges/tree-huffman-decoding

void decode_huff(node * root,string s)
{
    const char* p = s.c_str();
    node* current = root;
    while (*p) {
        if (*p == '0') {
            current = current->left;
        } else if (*p == '1') {
            current = current->right;
        }
        if (!current->left && !current->right) {
            cout << current->data;
            current = root;
        }
        ++p;
    }
    cout << endl;
}
