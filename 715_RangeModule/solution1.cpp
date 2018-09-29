/*
Stores ordered ranges in vector, adding/deleting : O(n), query: O(nlog n)
*/

#include <vector>
using namespace std;

class Solution{
public:
    RangeModule(){}
    
    void addRange(int left, int right){
        vector<pair<int, int>> new_range;
        bool inserted = false;
        for(const auto &r : ranges_){
            if(r.first > right && !inserted){
                new_range.emplace_back(left, right);
                inserted = true;
            }
            // non-overlapping
            if(r.second < left || r.first > right) new_range.emplace_back(r);
            else{
                left = min(left, r.first);
                right = max(right, r.second);
            }
        }
        if(!inserted) new_range.emplace_back(left, right);
        ranges_.swap(new_range);
    }
    
    bool queryRange(int left, int right){
        // Binary Search
        const int n = ranges_.size();
        int l = 0, r = n-1;
        while(l <= r){
            int m = l + (r-l) /2;
            if(ranges_[m].second < left) l = m + 1;
            else if(ranges_[m].first > right) r = m - 1;
            else return ranges_[m].first <= left && ranges_[m].second >= right;
        }
        return false;
    }
    
    void removeRange(int left, int right){
        vector<pair<int, int>> new_range;
        for(const auto &r : ranges_){
            if(r.second <= left || r.first >= right){
                new_range.emplace_back(r);
            } else{
                if(r.first < left) new_range.emplace_back(r.first, left);
                if(r.second > right) new_range.emplace_back(right, r.second);
            }
        }
        ranges_.swap(new_range);
    }
    
private:
    vector<pair<int, int>> ranges_;
}
/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left, right);
 * bool param2 = obj.queryRange(left, right);
 * obj.removeRange(left, right);
 */
