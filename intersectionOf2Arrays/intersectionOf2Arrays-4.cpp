class Solution{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> res;
        sort(nums2.begin(), nums2.end());

        for(auto num : nums1){
            if(binarySearch(nums2, num)) res.insert(num);
        }
        return vector<int>(res.begin(), res.end());

    }

    bool binarySearch(vector<int> &nums, int target){
        int left = 0, right = nums.size();
        while(left < right){
            int mid = left + (right-left) /2;
            if(nums[mid] == target) return true;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return false;
    }
};
