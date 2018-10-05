#include <vector>

using namespace std;

class Solution{
public:
    vector<int> searchRange(vector<int>& nums, int target){
         int n = nums.size();
         vector<int> res(2, -1);
         if(n == 0 || nums.empty()) return res;
         
         int left = 0, right = n-1;
         while(left <= right){
            int m = (left + right) / 2;
            if(nums[m] < target) left = m+1;
            else if(nums[m] > target) right = m-1;
            else{
                res[0] = m; res[1] = m;
                int j = m-1;
                while(j >= 0 && nums[j] == target){
                    res[0] = j; --j;
                }
                int j = m + 1;
                while(j < n && nums[j] == target){
                    res[1] = j; ++j;
                }
                break;
            }
         }
         return res;
    }
};
