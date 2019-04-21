class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int a_count = 0;
        int b_count = 0;
        int a_diff = 0;
        int b_diff = 0;
        int a_0 = A[0];
        int b_0 = B[0];
        int n = A.size();

        for (int i = 0; i < n; ++i) {
            a_count += A[i] == a_0 || B[i] == a_0;
            b_count += A[i] == b_0 || B[i] == b_0;
        }

        if (a_count < n && b_count < n) {
            return -1;
        }

        int major = a_count >= n ? a_0 : b_0;
        for (int i = 0; i < n; ++i) {
            a_diff += A[i] != major;
            b_diff += B[i] != major;
        }

        return min(a_diff, b_diff);
    }
};
