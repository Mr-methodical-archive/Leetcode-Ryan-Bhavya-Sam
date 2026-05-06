class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    MedianFinder() {
        max_heap.push(INT_MIN);
        max_heap.push(INT_MAX);
    }
    
    void addNum(int num) {
        // our max_heap is like the lower half and the min heap is like upper half
        // we just need to make sure they are balanced each time, this will end up being logn complexity
        // if they are the same size we can just put the element into whichever one
        // we will put it in:
        if (max_heap.top() >= num) {
            max_heap.push(num);
        } else {
            min_heap.push(num);
        }
        if (max_heap.size() < min_heap.size()) {
            int temp = min_heap.top();
            min_heap.pop();
            max_heap.push(temp);
        } else if (max_heap.size() > min_heap.size()) {
            int temp = max_heap.top();
            max_heap.pop();
            min_heap.push(temp);
        }
    }
    
    double findMedian() {
        // this will be O(1)
        if (max_heap.size() > min_heap.size()) {
            return max_heap.top();
        } else if (max_heap.size() < min_heap.size()) {
            return min_heap.top();
        } else {
            // they are equal in size so we take the average
            return (min_heap.top() + max_heap.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
