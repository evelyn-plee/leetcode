#include <vector>

class Solution{
public:
    int rob(vector<int>& nums){
        int lastRob = 0, lastNotRob = 0;
        int tmpRob = 0, tmpNotRob = 0;
        for(size_t i = 0; i < nums.size(); i++){
            tmpRob = lastNotRob + nums[i];
            tmpNotRob = lastRob > lastNotRob? lastRob : lastNotRob;
            lastRob = tmpRob;
            lastNotRob = tmpNotRob;
        }
        return lastRob > lastNotRob ? lastRob : lastNotRob;
    }
};