class Solution{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        for(int i = m - 1, j = n - 1, t = m + n - 1; i >= 0 || j >= 0; --t){
            int x = (i >= 0) ? nums1[i] : INT_MIN;
            int y = (j >= 0) ? nums2[j] : INT_MIN;
            nums1[t] = (x >= y) ? nums1[i--] : num2[j--];
        }
    }
};
