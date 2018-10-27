/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
   static bool cmpStart(Interval x, Interval y){ return x.start < y.start;}
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), cmpStart);
        int cnt = 1;
        priority_queue<int, vector<int>, std::greater<int>> pq;
        pq.push(intervals[0].end);
        for(int i = 1; i < intervals.size(); ++i){
            if(pq.top() <= intervals[i].start)
                pq.pop();
            pq.push(intervals[i].end);
            cnt = max(cnt, (int)pq.size());
        }
        return cnt;
    }
};



