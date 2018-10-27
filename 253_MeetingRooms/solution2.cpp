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
    int minMeetingRooms(vector<Interval>& intervals) {
       vector<int> starts, ends;
        for(auto i : intervals){
            starts.push_back(i.start);
            ends.push_back(i.end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int e = 0, rooms = 0, available = 0;
        for(int start : starts){
            while(ends[e] <= start){
                ++e;
                ++available;
            }
            available ? --available : ++rooms;
        }
        return rooms;
    }
};
