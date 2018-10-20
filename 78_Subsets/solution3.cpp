// Bit manipulation

 class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = pow(2, nums.size()); 
        vector<vector<int>> subs(n, vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < n; j++) {
                if ((j >> i) & 1) {
                    subs[j].push_back(nums[i]);
                }
            }
        }
        return subs;
    }
};
