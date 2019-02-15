// https://leetcode.com/problems/find-median-from-data-stream/submissions/

class MedianFinder {
public:
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> upper;
    
    void addNum(int num) {
        if (lower.size() == upper.size()) {
            if (upper.empty() || num >= upper.top()) {
                upper.push(num);
                return;
            }
            lower.push(num);
            upper.push(lower.top());
            lower.pop();
        }
        else {
            if (num < upper.top()) {
                lower.push(num);
                return;
            }
            upper.push(num);
            lower.push(upper.top());
            upper.pop();
        }
    }
    
    double findMedian() {
        if (lower.size() == upper.size())
            return (lower.top() + upper.top()) / 2.0;
        return upper.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */