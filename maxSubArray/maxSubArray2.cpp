#include <vector>

class Solution{
public:
    int maxSubArray(vector<int>& nums)
        if(nums.empty()) return 0;
        return helper(nums, 0, nums.size()-1);

    int helper(vector<int>& nums, int left, int right){
        if(left >= right) return nums[left];
        int mid = left + (right - left)/2;
        int lmax = helper(nums, left, mid-1);
        int rmax = helper(nums, mid+1, right);
        int mmax = nums[mid], t = mmax;
        for(int i = mid-1; i >=left; i--){
            t += nums[i];
            mmax = max(mmax, t);
        }
        t = mmax;
        for(int i = mid+1; i <= right; i++){
            t += nums[i];
            mmax = max(mmax, t);
        }
        return max(mmax, max(lmax, rmax));
    }
};