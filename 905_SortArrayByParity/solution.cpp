class Solution{
public:
    vector<int> sortArrayByParity(vector<int>& A){
        int n = A.size();
        int i = 0, j = n-1;
        
        while(i < j){
            while(i < j && A[i] % 2){
                swap(A[i], A[j]);
                j--;
            }
            i++;
        }
        return A;
    }
}
