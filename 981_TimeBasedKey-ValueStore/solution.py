class TimeMap(object):
    def __init__(self):
        self.M = collections.defaultdict(list)
        
    def set(self, key, value, timestamp):
        self.M[key].append((timestamp, value))
        
    def get(self, key, timestamp):
        if key not in self.M: return ""
        idx = bisect.bisect_right(self.M[key], (timestamp, 'z'*101))
        return "" if idx == 0 else self.M[key][idx-1][1]
