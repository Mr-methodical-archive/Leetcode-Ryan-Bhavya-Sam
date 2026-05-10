class MinStack {
public:
    struct Node {
        int min;
        int val;
    };

    Node *arr;
    int size = 1;
    int len = 0;
    int min = 0;
    MinStack() {
        arr = new Node[size];
    }
    
    void push(int val) {
        if (len == 0 || val < min) min = val;

        if (len == size) {
            size *= 2;
            Node *temp = arr;
            arr = new Node[size];
            for (int i = 0; i < len; ++i) {
                arr[i].min = temp[i].min;
                arr[i].val = temp[i].val;
            }
            delete[] temp;
        }
        arr[len].min = min;
        arr[len++].val = val;
    }
    
    void pop() {
        len--;
        if (len > 0) {
            min = arr[len - 1].min;
        }
    }
    
    int top() {
        return arr[len - 1].val;
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
