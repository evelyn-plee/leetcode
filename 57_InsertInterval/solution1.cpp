#include <vector>

using namespace std;

/**
* Definition for an interval.
* struct Interval{
*   int start;
*   int end;
*   Interval() : start(0), end(0) {}
*   Interval(int s, int e) : start(s), end(e) {}
* };
*/

class Solution{
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval){
        auto it = intervals.begin();
        while(it != intervals.end() && newInterval.start > it->start) ++it;
        intervals.insert(it, newInterval);
        
        vector<Interval> res;
        for(const auto& interval: intervals){
            if(res.empty() || interval.start > res.back().end) res.push_back(interval);
            else res.back().end = max(res.back().end, interval.end);
        }
        return res;
    }
};
