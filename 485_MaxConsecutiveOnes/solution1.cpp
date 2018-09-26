#include <vector>
#include <math>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int cnt = 0, res = 0;
        for(int i = 0; i < nums.size(); ++i){
            cnt = nums[i] == 0 ? 0 : cnt + 1;
            res = max(res, cnt);
        }
        return res;
    }
};
