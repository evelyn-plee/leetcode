/** Time complexity: O(n), Space complexity: O(1) **/

#include <vector>

using namespace std;

class Solution{
public:
    void nextPermutation(vector<int>& nums){
        int i = nums.size()-2;
        while(i >= 0 && nums[i+1] <= nums[i]) --i;
        if(i >= 0){
            int j = nums.size() - 1;
            while(j >= 0 && nums[j] <= nums[i]) --j;
            swap(nums[i], nums[j]);
        }
        reverse(begin(nums) + i + 1, end(nums));
    }
};
