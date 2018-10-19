// Get Median: O(1), Add Number: O(log n)

class MedianFinder{
public:
    /** initialize your data structure here. **/
    MedianFinder(){}
    
    void addNum(int num){
        if(l_.empty() || num < l_.top()) l_.push(num);
        else r_.push(num);
        
        if(l_.size() < r_size()){
            l_.push(r_.top());
            r_.pop();
        }else if(l_.size() - r_.size() == 2){
            r_.push(l_.top());
            l_.pop();
        }
    }
    
    double findMedian(){
        if(l_.size() > r_.size()) return static_cast<double>(l_.top());
        else return static_cast<double> return (static_cast<double>(l_.top()) + r.top())/2;
    }
    
private:
    priority_queue<int, vector<int>, less<int>> l_;
    priority_queue<int, vector<int>, greater<int>> r_;
};
