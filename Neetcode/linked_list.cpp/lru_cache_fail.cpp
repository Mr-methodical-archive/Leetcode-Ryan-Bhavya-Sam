class LRUCache {
public:
    // notes we need to know the least recently used key
    // we definitely need a hash map but maybe we need some way to know
    // least used element, what if we used a queue
    // let's use a dequeue
    // we need some way to access each node in O(1) time
    deque<int> d;
    int curr = 0;
    int cap = 0;
    unordered_map<int, int> um;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (um.contains(key)) {
            // oh but how would we change the priority actually
            // this could take O(n) actually 
            return um[key]; 
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (um.contains(key)) {
            um[key] = value;
            return;
            // we updated it
        }
        if (curr == cap) {
            // we need to delete the thing at the back of our deque
        }
        um[key] = value
    }
};

