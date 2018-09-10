class Solution {
public:
    int numPermsDISequence(string S) {
        int n = S.length(), mod = 1e9 + 7;
        vector<int> dp(n + 1, 1), dp2(n);
        for (int i = 0; i < n; dp = dp2, i++) {
            if (S[i] == 'I'){
                for (int j = 0, cur = 0; j < n - i; j++)
                    dp2[j] = cur = (cur + dp[j]) % mod;
            }
            else{
                for (int j = n - i - 1, cur = 0; j >= 0; j--)
                    dp2[j] = cur = (cur + dp[j + 1]) % mod;
            }
        }
        return dp[0];
    }
};
