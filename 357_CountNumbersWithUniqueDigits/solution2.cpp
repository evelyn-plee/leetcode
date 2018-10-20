class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        dp[1] = 10;
        for(int i = 2;i<=n;i++){
            dp[i] = 9;
            int k = 9;
            int count = 1;
            while( count <i){
                dp[i] *= k;
                k--;
                count++;
            }
            dp[i] +=dp[i-1];
        }
        return dp[n];
    }
};
