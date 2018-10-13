// Backtracking

class Solution {
    bool traverse(vector<int>& nums, int sum, int i){
        // if(nums[i] > sum)
        //     return false;
        if(sum == nums[i])
             return true;
        if(nums[i] > sum)
            return false;
        return ( traverse(nums,sum - nums[i],i+1) || traverse(nums,sum,i+1));
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        sort(nums.rbegin(),nums.rend());
        sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2 == 1)
            return false;
        else
            sum = sum / 2;
        //cout << sum  << endl;
        return traverse(nums,sum,0);
    }
};
