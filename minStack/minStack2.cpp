class MinStack {
public:
    /** initialize your data structure here. */
    multiset<int> mst;
    stack<int> stk;
    
    MinStack() {
        
    }
    
    void push(int x) {
        mst.insert(x);
        stk.push(x);
    }
    
    void pop() {
        int x = stk.top();
        mst.erase(mst.find(x));
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return *mst.begin();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */