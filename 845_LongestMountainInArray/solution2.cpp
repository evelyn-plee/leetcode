// O(n), O(1)

class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        int inc = 0, dec = 0, res = 0;
        for(int i = 1; i < A.size(); ++i){
            if(dec && A[i] > A[i-1] || A[i] == A[i-1]){
                dec = inc = 0;
            }
            inc += A[i] > A[i-1];
            dec += A[i-1] > A[i];
            if(inc && dec){
                res = max(res, inc + dec + 1);
            }
        }
        return res;
    }
};
