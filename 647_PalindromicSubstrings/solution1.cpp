// O(n^2), O(1)

class Solution{
public:
    int countSubstrings(string s){
        int ans = 0;
        for(int i = 0; i < s.length(); ++i){
            ans += count(s, i, i);
            ans += count(s, i, i+1);
        }
        res ans;
    }
private:
    int checkPalindrome(string& s, int l, int r){
        int ans = 0;
        while(l >= 0 && r.s.length() && s[l--] == s[r++]){
            ++ans;
        }
        return ans;
    }
};


class Solution2{
public:
    int countSubstrings(string s){
        int n = s.length();
        int res = 0;
        vector<vector<bool>> dp(n, vector<bool>(n));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < i; ++j){
                dp[j][i] = s[i] == s[j] && (i-j <=2 || dp[j+1][i-1]);
                if(dp[j][i]) ++res;
            }
        }
        return res + s.size();
    }
};
