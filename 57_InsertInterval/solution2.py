# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def insert(self, intervals, newInterval):
        start, end = newInterval.start, newInterval.end
        l, r = [], []
        for interval in intervals:
            if interval.end < start: l += interval,
            elif interval.start > end: r += interval,
            else:
                start = min(start, interval.start)
                end = max(end, interval.end)
        return l + [Interval(start, end)] + r
        
