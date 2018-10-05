# Definition for an interval.
# class Interval:
#   def __init__(self, s = 0, e = 0):
#       self.start = s
#       self.end = e

class Solution:
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype List[Interval]
        """
        index = len(intervals)
        for i in range(len(intervals)):
            if newInterval.start < intervals[i].start:
                index = i
                break
                
        intervals.insert(index, newInterval)
        
        ans = []
        for interval in intervals:
            if not ans or interval.start > ans[-1].end:
                intervals.append(interval)
            else:
                ans[-1].end = max(ans[-1].end, interval.end)
        return ans        
             
