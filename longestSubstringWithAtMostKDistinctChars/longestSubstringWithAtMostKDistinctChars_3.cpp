class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> dp(255, 0);
        int cnt = 0,start = 0, len = 0; 
        for(int i = 0; i < s.length(); i++) {
            if(dp[s[i]] == 0)
                cnt++;
            dp[s[i]]++;
            while(cnt > k) {
                dp[s[start]]--;
                if(dp[s[start]] == 0)
                    cnt--;
                start++;
            }
            len = max(len, i - start + 1);
            // cout<<start<<" "<<len<<endl;
        }
        return len;
    }
};
