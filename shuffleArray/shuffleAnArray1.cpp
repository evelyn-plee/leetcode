#include <vector>
class Solution {
vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
        srand((unsigned)time(0));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int>res(nums.begin(), nums.end());
        for(int i = 0; i<res.size(); i++){
            swap(res[i], res[rand()%res.size()]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */