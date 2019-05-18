For each A[j], try to find the longest subarray.
If A[i] ~ A[j] has zeros <= K, we continue to increment j.
If A[i] ~ A[j] has zeros > K, we increment i.

class Solution{
public:
    int longestOnes(vector<int>& A, int K) {
        int i = 0, j;
        for(j = 0; j < A.size(); j++){
            if(A[j] == 0) K--;
            if(K < 0 && A[i++] == 0) K++;
        }
        return j - i;
    }
};
