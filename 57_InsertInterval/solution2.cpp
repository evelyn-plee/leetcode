#include <vector>

using namespace std;

class Solution{
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval){
        vector<Interval> l;
        vector<Interval> r;
        int start = newInterval.start; int end = newInterval.end;
        for(const Interval& interval : intervals){
            if(interval.end < start) l.push_back(interval);
            else if(interval.start > end) r.push_back(interval);
            else{
                start = min(start, interval.start);
                end = max(end, interval.end);
            }
        }
        vector<Interval> res(move(l));
        res.emplace_back(start, end);
        res.insert(res.end(), r.begin(), r.end());
        return res;
    }
};
