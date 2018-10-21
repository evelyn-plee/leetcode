// O(m + n), O(m +n)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> stk;
        unordered_map<int, int> mp;
        for (auto n : nums) {
            while (!stk.empty() && stk.top() < n) {
                mp[stk.top()] = n, stk.pop();
            }
            stk.push(n);
        }
        
        vector<int> ans;
        for (auto n : findNums) ans.push_back(mp.find(n) != mp.end() ? mp[n] : -1);
        return ans;
    }
    
};
