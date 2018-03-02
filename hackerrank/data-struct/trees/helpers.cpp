
template<typename T>
class queue {
public:
    bool empty() const { return head == tail; }
    void push(const T& v) {
        tail = (tail + 1) % MAX_ELEMS;
        assert(!empty());
        elems[tail] = v;
    }
    void pop() { assert(!empty()); head = (head + 1) % MAX_ELEMS; }
    T& front() { return elems[head]; }
private:
    void assert(bool cond) {
        if (!cond) { cerr << "assert failed"; exit(-1); }
    }

    static constexpr size_t MAX_ELEMS = 10000;
    T elems[MAX_ELEMS];
    size_t head, tail;
};


void dumpLevelOrder(node * root) {
    queue<node*> q;
    q.push(root); q.push(nullptr);
    while (!q.empty()) {
        node *n = q.front();
        q.pop();
        if (!n) {
            cout << endl;
            if (!q.empty()) q.push(nullptr);
        } else {
            if (n->left) q.push(n->left);
            if (n->right) q.push(n->right);
            cout << n->data << " ";   
        }
    }
}
