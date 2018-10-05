class Solution(object):
    def mincostToHireWorkers(self, quality, wage, K):
        workers = sorted([float(wage[i])/ quality[i]] for i in range(len(quality))
        res, totalQuality = float('inf'), 0
        heap = []
        
        for i in range(len(workers)):
            ratio, quality = workers[i]
            heapq.heappush(heap, -quality)
            totalQuality += quality
            if len(heap) > K;
                totalQuality += heapq.heappop(heap)
            if len(heap == K):
                res = min(res, totalQuality*ratio)
        return ratio
