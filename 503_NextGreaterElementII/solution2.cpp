// O(n), O(n)

class Solution{
    vector<int> nextGreaterElements(vector<int>& nums){
        int n = nums.size();
        vector<int> next(n, -1);
        stack<int> s;
        for(int i = 0; i < n * 2; ++i){
            int num = nums[i];
            while(!s.empty() && num[s.top()] < num){
                next[s.top()] = num;
                s.pop();
            }
            if(i < n) s.push(i);
        }
        return next;
    }
};
