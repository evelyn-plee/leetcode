// O(n^2), O(n)


class Solution{
public:
    vector<int> nextGreaterElements(vector<int>& nums){
        int n = nums.size();
        vector<int> res(n);
        for(int i = 0; i < n; i++){
            res[i] = -1;
            for(int j = 1; j < n; j++){
                if(nums[(i+j) % n] > nums[i]){
                    res[i] = nums[(i+j) % n];
                    break;
                }
            }
        }
        return res;
    }
};
