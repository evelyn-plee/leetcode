#include <vector>


class Solution{
public:
    int smallestDistancePair(vector<int>& nums, int k){
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        int l = 0, r = nums.back() - nums.front();
        while(l <= r){
            int m = l + (r-l) / 2;
            int dp = 0; 
            int j = 0
            for(int i = 0 ; i < n; ++i){
                while(j < n && nums[j] - nums[i] <= m) ++j;
                dp += j - i - 1;
            }
            dp >= k ? r = m - 1 : l = m + 1;
        }
        return l;
    }
};
