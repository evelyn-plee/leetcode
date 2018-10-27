class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n-1;
        if(nums[l] > nums[r]){
            while(l+1 < r){
                int m = l + (r-l) /2;
                if(nums[l] < nums[m]) l = m;
                else r = m;
            }
            return min(nums[l], nums[r]);
        }
        return nums[0];
    }
};
