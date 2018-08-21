/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution{
public:
    struct compInterval{
        bool operator()(const Interval &a, const Interval &b) const{
            return a.start<b.start;
        }
    };

    vector<Interval> merge(vector<Interval>& intervals){
        sort(intervals.begin(), intervals.end(), compInterval());
        vector<Interval> result;
        
        for(int i = 0; i < intervals.size(); ++i){
            // no overlap
            if(result.empty() || result.back().end < intervals[i].start){
                result.push_back(intervals[i]);
            } else{
                result.back().end = max(result.back().end, intervals[i].end);
            }
        }
        return result;
    }
};
