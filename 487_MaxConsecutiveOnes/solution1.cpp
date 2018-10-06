/**
* Time complexity: O(n), Space complexity: O(1), but can't change k (the amount of times to flip 0)
*/


#include <vector>

using namespace std;

class Solution{
public:
    int findMaxConsecutiveOnes(vector<int>& nums){
        int cnt = 0, cur = 0, res = 0;
        for(int num : nums){
            ++cnt;
            if(num == 0){
                cur = cnt;
                // restart cnt
                cnt = 0;
            }
            res = max(res, cnt + cur);
        }
        return res;
    }
};
