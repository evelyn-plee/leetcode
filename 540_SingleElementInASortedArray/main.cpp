// TC: O(n), SC: O(1) -- Brute Force
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        int ans = -1;
        while(l < r){
            if(nums[l] != nums[l+1]){
                ans = nums[l];
            }
            else l = l + 2;
        }
        if(ans == -1) ans = nums[r];
        return ans;
    }
};

// TC: O(log n), SC: O(1) -- Using binary search

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), left = 0, right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid-1]) right = mid - 2;
                else if (nums[mid] == nums[mid+1]) left = mid + 2;
                else return nums[mid];
            }
            else {
                if (nums[mid] == nums[mid-1]) left = mid + 1;
                else if (nums[mid] == nums[mid+1]) right = mid - 1;
            }
        }
        return nums[left];
    }
};
