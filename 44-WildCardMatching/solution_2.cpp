class Solution{
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1,vector<bool>(p.size()+1,false));
        dp[0][0] = true;
        for (int i=0;i<p.size();i++)
            if (p[i]=='*' && dp[0][i]) dp[0][i+1] = true;
        for (int i=0;i<s.size();i++)
            for (int j=0;j<p.size();j++){
                if (s[i] == p[j] || p[j]=='?') dp[i+1][j+1] = dp[i][j];
                else if (p[j]=='*') dp[i+1][j+1] = dp[i+1][j] | dp[i][j+1];
            }
        return dp[s.size()][p.size()];
    }
};
