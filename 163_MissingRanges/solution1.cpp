// O(n) & O(n)

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        if (nums.empty()) {
            res.push_back(getRange(lower, upper));
            return res;
        }
        
        long pre = (long) lower; 
        for (int i = 0; i <= nums.size(); ++i) {
            long cur = i == nums.size() ? (long) upper : (long) nums[i] - 1;
            if (cur - pre >= 0) {
                res.push_back(getRange(pre, cur));
            }
            pre = (long) nums[i] + 1;
        }
        return res;
    }
private:
    string getRange(int lower, int upper){
        return lower == upper ? to_string(lower) : to_string(lower)+"->"+to_string(upper); 
    }
};
