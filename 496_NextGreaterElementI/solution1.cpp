// Brute-force O(nxm), n - vector 1, m = vector2
// O(m) - vector1


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        int n = findNums.size();
        vector<int> res(n); int j;
        for(int i = 0; i < n; ++i){
            bool found = false;
            for(j = 0; j < nums.size(); ++j){
                if(found && nums[j] > findNums[i]){
                    res[i] = nums[j];
                    break;
                }
                if(nums[j] == findNums[i]) found = true;
            }
            if(j == nums.size()) res[i] = -1;
        }
        return res;
    }
};
