#include <stack>

class MinStack{
    long long min;
    stack<long long>l;
public:
    MinStack() { 
        min = INT_MIN; 
    }
    
    void push(int x) { 
        if (l.empty()) {
            l.push(0); min = x; 
        } else {
            l.push(x - min); 
            if (x < min) {
                min = x; 
            } 
        } 
    };
    
    void pop() {
        if (!l.empty()) {
            long long t = l.top(); l.pop();
            if (t < 0) {
                min -= t; 
            } 
        } 
    };
    
    int top() const {
        if (l.empty()) {
            return INT_MIN; 
        } 
        long long t = l.top();
        return (int) (t < 0 ? min : min + t); };
    
    int getMin() const {
        return (int)min; 
    };
};