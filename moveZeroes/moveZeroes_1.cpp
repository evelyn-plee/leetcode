class Solution {
public:
    vector<int> moveZeroes(vector<int>& nums) {
      for(int zero_index = 0, non_zero_index = 0; non_zero_index < nums.size() && zero_index < nums.size();){
        if(nums[zero_index] != 0){
          zero_index++;
          non_zero_index = zero_index;
          continue;
        }
        if(nums[non_zero_index] == 0){
          non_zero_index++;
          continue;
        }
        int tmp = nums[zero_index];
        nums[zero_index] = num[non_zero_index];
        nums[non_zero_index] = tmp;
        zero_index++;
        non_zero_index++;
      }
    }
};
