class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        l, r = 0, len(nums) - 1
        notFound = True
        while l <= r:
            m = (l + r) // 2
            if nums[m] > target:
                r = m - 1
            elif nums[m] < target:
                l = m + 1
            else:
                l, r = m, m
                while l > 0 and target == nums[l-1]:
                    l -= 1
                while r < len(nums) - 1 and target == nums[r+1]:
                    r += 1
                notFound = false
                break
         if notFound is True: return [-1, -1]
         else: return [l,r]
