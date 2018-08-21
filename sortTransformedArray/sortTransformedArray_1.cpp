class Solution{
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c){
        vector<int> result;
        priority_queue<int, vector<int>, greater<int>> q;
        for(auto d : nums){
            q.emplace(a * d * d + b * d + c);
        }
        while(!q.empty()){
            result.emplace_back(q.top()); q.pop();
        }
        return result;
    }
};
