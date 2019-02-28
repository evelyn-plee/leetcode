class Solution{
public:
    vector<int> sortArrayByParityII(vector<int>& A){
        int n = A.size();
        vector<int> idx = {0, 1};
        for(int i = 0; i < n; i++){
            while(A[i] % 2 != i % 2){
                swap(A[i], A[idx[1-i%2]]);
                idx[1-i%2] += 2;
            }
        }
        return A;
    }
};
