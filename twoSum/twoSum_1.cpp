class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> m;

      for(int i = 0; i < nums.size(); i++) {
        int buddy = target - nums[i];
        auto buddyIt = m.find(buddy);

        if(buddyIt != m.end()) {
          return vector<int>{ buddyIt->second, i };
        }

        m[nums[i]] = i;
      }
    }
};
