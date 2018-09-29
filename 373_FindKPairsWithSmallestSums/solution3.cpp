/*
Use priority queue
Runtime 8ms
*/

class Solution{
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k){
        vector<pair<int, int>> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        int m = nums1.size(); 
        int n = nums2.size();
        for(int i = 0; i < min(k, m); ++i){
            for(int j = 0; j < min(k, n); ++j){
                if(q.size() < k) q.push({nums1[i], nums2[j]});
                else if(nums1[i] + nums2[j] < q.top().first + q.top().second){
                    q.push({nums1[i], nums2[j]});
                    q.pop();
                }
            } 
        }
        while(!q.empty()){
            res.push_back(q.top()); q.pop();
        }
        return res;
    }
    struct cmp{
        bool operator()(pair<int, int> &a, pair<int, int> &b){
            return a.first + a.second < b.first + b.second;
        }
    };
};
