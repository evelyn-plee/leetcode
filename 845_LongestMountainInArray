// O(n), O(n)
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        vector<int> inc(n);
        vector<int> dec(n);
        for(int i = 1; i < A.size(); ++i){
            if(A[i] > A[i-1]) inc[i] = inc[i-1] + 1;
        }
        for(int i = n-2; i >= 0; --i){
            if(A[i] > A[i+1]) dec[i] = dec[i+1] + 1;
        }
        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(inc[i] && dec[i]){
                ans = max(ans, inc[i] + dec[i] + 1);
            }
        }
        return ans;
    }
};
