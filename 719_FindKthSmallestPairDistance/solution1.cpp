/*
using bucket sort/ brute force
Time complexity: O(n^2)
Space complexity: O(max(nums))
*/


#include<vector>

class Solution{
public:
    int smallestDistancePair(vector<int>& nums, int k){
        sort(nums.begin(), nums.end());
        const int N = nums.back();
        const int n = nums.size();
        vector<int> cnt(N+1, 0);
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                ++cnt[nums[j] - nums[i]];
            }
        }
        
        for(int i = 0; i <= N; ++i){
            k -= cnt[i];
            if(k <= 0) return i;
        }
        return 0;
    }
};
