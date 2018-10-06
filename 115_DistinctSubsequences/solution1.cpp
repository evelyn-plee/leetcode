#include <string>

using namespace std;

class Solution{
public:
    int numDistinct(string s, string t){
        int ls = s.length();
        int lt = t.length();
        
        int dp[lt+1][ls+1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        
        for(int i = 0; i <= ls; ++i) dp[0][i] = 1;
        
        for(int i = 1; i <= lt; ++i){
            for(int j = 1; j <= ls; ++j){
                dp[i][j] = dp[i][j-1] + (t[i-1] == s[j-1] ? dp[i-1][j-1] : 0);
            }
        }
        return dp[lt][ls];
    }
};
