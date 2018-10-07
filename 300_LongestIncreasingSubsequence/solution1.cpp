/**
* Use dynamic programming 
* Longest increasing subsequence possible upto the i-th index in a given array 
* is independent of the elements coming later on in the array.
* Need to try to append the current element (nums[i]) in every possible increasing
* subsequences up to the (i-1)-th index, such that new sequence formed by adding
* the current element is also an increasing subsequence.
* Time complexity: O(n^2) 
* Space complexity: O(n)
*/


#include <vector>

using namespace std;

class Solution{
public:
    int lengthOfLIS(vector<int>& nums){
        if(nums.empty()) return 0;
        int n = nums.size();
        auto f = vector<int>(n, 1);

        for(int i = 1; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j])
                f[i] = max(f[j]+1, f[i]);
            }
        } 
        return *max_element(f.begin(), f.end());
    }
};
