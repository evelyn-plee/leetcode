// O(n), O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int minProduct = nums[0], maxProduct = nums[0], ans = nums[0];
        for(int i = 1; i < n; ++i){
            if(nums[i] < 0) swap(minProduct, maxProduct);
            maxProduct = max(maxProduct * nums[i], nums[i]);
            minProduct = min(minProduct * nums[i], nums[i]);
            ans = max(ans, maxProduct);
        }
        return ans;
    }
};
