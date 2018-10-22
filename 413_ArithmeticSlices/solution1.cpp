// Brute Force, O(n^3), O(1)

class Solution{
public:
    int numberOfArithmeticSlices(vector<int>& A){
        int count = 0;
        for(int start = 0; start < A.size() - 2; ++start){
            int diff = A[start+1] - A[start];
            for(int end = start + 2; end < A.size(); ++end){
                int i = 0;
                for(i = start + 1; i <= end; ++i){
                    if(A[i] - A[i-1] != diff) break;
                }
                if(i > end) ++count;
            }
        }
        return count;
    }
};

// Better Brute Force, O(n^2), O(1)
class Solution2{
public:
    int numberOfArithmeticSlices(vector<int>& A){
        int count = 0;
        for(int start = 0; start < A.size() - 2; ++start){
            int diff = A[start+1] - A[start];
            for(int end = start + 2; end < A.size(); ++end){
                if(A[end] - A[end-1] == diff) ++count;
                else break;
            }
        }
        return count;
    }
};

// Recursive O(n), O(n) - The recursive function is called at most n-2 times, depth of the recursive function trees goes up to n-2
class Solution3{
public:
    int numberOfArithmeticSlices(vector<int>& A){
        slices(A, A.size()-1)    
        return sum;
    }
private:
    int sum = 0;
    int slices(vector<int>& A, int i){
        if(i < 2) return 0;
        int cur = 0;
        if(A[i] - A[i-1] == A[i-1] - A[i-2]){
            cur = 1 + slices(A, i-1);
            sum += cur;
        } else{
            slices(A, i-1);
        }
        return cur;
    }
};

// DP O(n), O(n)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n);
        int sum = 0;
        for(int i = 2; i < n; ++i){
            if(A[i] - A[i-1] == A[i-1] - A[i-2]){
                dp[i] = dp[i-1] + 1;
                sum += dp[i];
            }   
        }
        return sum;
    }
};

// DP O(n), O(1)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        int dp = 0;
        int sum = 0;
        for(int i = 2; i < n; ++i){
            if(A[i] - A[i-1] == A[i-1] - A[i-2]){
                dp += 1;
                sum += dp;
            } else dp = 0;
        }
        return sum;
    }
};
