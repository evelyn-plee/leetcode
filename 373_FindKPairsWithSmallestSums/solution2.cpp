/*
Multimap in C++ STL is ordered
Time complexity: O(k^2)
Space complexity: O(k)
Runtime = 308ms
*/

#include<vector>

using namespace std;

class Solution{
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k){
        vector<pair<int, int>> res;
        multimap<int, pair<int, int>> mp;
        int m = nums1.size();
        int n = nums2.size();
        for(int i = 0; i < min(m, k); ++i){
            for(int j = 0; j < min(n, k); ++j){
                mp.insert({nums1[i] + nums2[j], {nums1[i], nums2[j]}});
            }
        }
        for(auto it = mp.begin(); it != mp.end(); ++it){
            res.push_back(it->second);
            if(--k <= 0) return res;
        }
        return res;
    }
};
