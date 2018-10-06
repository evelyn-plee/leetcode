
class Solution{
public:
    int findMaxConsecutiveOnes(vector<int>& nums){
        int res = 0, left = 0, k = 1, zero = 0; 
        for(int right = 0; right < nums.size(); ++right){
            if(nums[right] == 0) ++zero;
            while(zero > k){
                if(nums[left++] == 0) --zero;
            }
            res = max(res, right-left+1);
        }
        return res;
    }
};
