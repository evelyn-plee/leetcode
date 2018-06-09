class Solution{
public:
    int missingNumber(vector<int>& nums){
        if(!nums.size()) return 0;
        int sum = 0;
        for(int num: nums) sum+= num;
        return nums.size() * (1+nums.size())/2 -sum;
    }
}