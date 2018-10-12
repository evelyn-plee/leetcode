class MovingAverage {
private:    
     int n;
     queue<int> q;
     double runningSum=0;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        n = size;
    }
    double next(int val) {
        // Queue has no more space to accomodate new int
        if(q.size() >= n){
            runningSum -= q.front();
            q.pop();
        }    
        runningSum += val; 
        q.push(val);
        return runningSum/q.size();
    }
};
/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
