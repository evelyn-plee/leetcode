class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int result = 0;
        vector<int> length;
        length.push_back(nums[0]);
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] < length.front()) length[0] = nums[i];
            else if (nums[i] > length.back()) length.push_back(nums[i]);
            else {
                auto it = lower_bound(length.begin(), length.end(), nums[i]);
                *it = nums[i];
            }
        }
        return length.size();
    }
};
