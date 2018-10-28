//Brute Force - O(n * min(n,k)), O(1)
class Solution{
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
        for(int i = 0; i < nums.size(); ++i){
            for(int j = max(i-k, 0); j < i; ++j){
                if(abs(nums[j]-nums[i] <= t) return true;
            }
        }
        return false;
    }
};

// Binary Search Tree - O(n log(min(n, k))), O(min(n, k))
class Solution{
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
        multiset<long> s
        for(int i = 0; i < (int)(nums.size()); ++i){
            if(i > k) s.erase(nums[i-k-1]);
            
            // Find the sucessor of the current element
            auto it = s.lower_bound(nums[i]);
            if(it != s.end() && *it - nums[i] <= t) return true;
            
            // Find the predecessor of the current element
            if(it != s.end() && nums[i] - *(--it) <= t) return true;
            s.insert(nums[i]);
        }
        return false;
    }
};

// Bucket sort -- O(n), O(min(n, k))
class Solution{
private:
    long long getBucketId(long long i, long long w){
        return i < 0 ? (i+1)/(w-1) : i/w;
    }
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t){
        int n = nums.size();
        if(n < 2 || k < 1 || t < 0) return false;
        
        unordered_map<long long, long long> buckets;
        long long width = (long long)t + 1;
        for(int i = 0; i < n; ++i){
            long long id = getBucketId(nums[i], width);
            
            // found the value in the same bucket
            if(buckets.find(id) != buckets.end()) return true;
            
            // found the value in the adjacent bucket
            if((buckets.find(id-1) != buckets.end() && nums[i]-buckets[id-1] < width) ||
                (buckets.find(id+1) != buckets.end() && buckets[id+1]-nums[i] < width)) return true;
            
            buckets[id] = nums[i];
            
            if(i >= k){
                buckets.erase(getBucketId(nums[i-k], width));
            }
         }
         return false;
    }
};
