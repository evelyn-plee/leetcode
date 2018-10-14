/** Brute Force: Time complexity: O(n^2), Space complexity: O(n) **/

class MyCalendar {
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        for(const auto& e : booked_){
            int x = e.first;
            int y = e.second;
            if(max(start, x) < min(end, y)) return false; 
        }
        booked_.emplace_back(start, end);
        return true;
    }
private:
    vector<pair<int, int>> booked_;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
