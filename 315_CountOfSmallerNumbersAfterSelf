/**
 * Time complexity: O(nlogn)
 * Space complexity: O(k) k, # of unique elements
 **/

#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class FenwickTree {    
public:
    FenwickTree(int n): sums_(n + 1, 0) {}
    
    void update(int i, int delta) {
        while (i < sums_.size()) {
            sums_[i] += delta;
            i += lowbit(i);
        }
    }
    
    int query(int i) const {        
        int sum = 0;
        while (i > 0) {
            sum += sums_[i];
            i -= lowbit(i);
        }
        return sum;
    }
private:
    static inline int lowbit(int x) { return x & (-x); }
    vector<int> sums_;
};
 
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        // Sort the unique numbers
        set<int> sorted(nums.begin(), nums.end());
        // Map the number to its rank
        unordered_map<int, int> ranks;
        int rank = 0;
        for (const int num : sorted)
            ranks[num] = ++rank;
        
        vector<int> ans;
        FenwickTree tree(ranks.size());
        // Scan numbers in reversed order
        for (int i = nums.size() - 1; i >= 0; --i) {
            // Check how many numbers are smaller than the current number.
            ans.push_back(tree.query(ranks[nums[i]] - 1));
            // Increse the count of the rank of current number.
            tree.update(ranks[nums[i]], 1);
        }
        
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
