class Solution{
public:
    int numSquares(int n){
        static vector<int> dp = {0};
        while(dp.size() <= n){
            int m = dp.size(), squares = INT_MAX;
            for(int i = 1; i*i <= m; ++i){
                squares = min(squares, dp[m-i*i]+1);
            }
            dp.push_back(squares);
        }
        return dp[n];
    }
};


class Solution2{
public:
    int numSquares(int n) {
        int dp[n+1] = {INT_MAX};
        dp[0] = 0;
        for(int i = 1; i <= n; ++i){
            int squares = INT_MAX;
            int j = 1;
            while(i - j*j >=0){
                squares = min(squares, dp[i-j*j]+1);
                ++j;
            }
            dp[i] = squares;
        }
        return dp[n];
    }
};
