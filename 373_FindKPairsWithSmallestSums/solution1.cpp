/*
Using bruteforce, Time complexity: O(k^2logk), space complexity: O(k)
*/


#include <vector>

using namespace std;

class Solution{
public:
    vector<pair<int, int>> kSmallestPairs(vector<int> & nums1, vector<int> & nums2, int k){
        vector<pair<int, int>> res;
        int m = nums1.size(); int n = nums2.size();
        for(int i = 0; i < min(k, m); ++i){
            for(int j = 0; j < min(k, n); ++j){
                res.push_back({nums1[i], nums2[j]});
            }
        }
        sort(res.begin(), res.end(), [](pair<int, int> &a, pair<int, int> &b) {return a.first + a.second < b.first + b.second; });
        if(res.size() > k) res.erase(res.begin() + k, res.end());
        return res;
    }
};
