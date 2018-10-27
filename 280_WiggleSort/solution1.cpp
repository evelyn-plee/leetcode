// O(n log n)
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.size() == 0 || nums.empty()) return;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size()-1; i+=2){
            swap(nums[i],nums[i+1]);
        }
    }
};

// O(n)
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.empty() || nums.size() == 0) return;
        bool less = true;
        for(int i = 0; i < nums.size()-1; ++i){
            if(less){
                if(nums[i] > nums[i+1]) swap(nums[i], nums[i+1]);
            } else{
                if(nums[i] < nums[i+1]) swap(nums[i], nums[i+1]);
            }
            less = !less;
        }
    }
};

// Or can be rewritten as if even index look for increasing, odd index look for decreasing
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if(nums.empty() || nums.size() == 0) return;
        bool less = true;
        for(int i = 0; i < nums.size()-1; ++i){
            if((i%2 == 0 && nums[i] > nums[i+1]) || (i%2 == 1 && nums[i] < nums[i+1])){
                swap(nums[i], nums[i+1]);
            }
        }
    }
};
