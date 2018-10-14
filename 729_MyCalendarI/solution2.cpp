/** Binary Search O(nlogn), O(n) **/


class MyCalendar {
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto it = booked_.lower_bound(start);
        if(it != booked_.end() && it->first < end) return false;
        if(it != booked_.begin() && (--it)->second > start) return false;
        booked_[start] = end;
        return true;
    }
private:
    map<int, int> booked_;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
