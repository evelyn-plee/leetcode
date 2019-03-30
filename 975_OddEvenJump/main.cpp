// Using dp + binary search
class Solution{
public:
    int oddEvenJumps(vector<int>& a){
        int n = a.size();
        vector<int> up(n);
        vector<int> down(n);
        // to map vector value to its corresponding index
        map<int, int> mp;
        
        for(int i = n-1; i >= 0 ; i--){
            auto it = mp.lower_bound(a[i]);
            // Find the index of the next increasing value
            up[i] = (it == mp.end()) ? n : it->second;
            
            // Find the index of the next decreasing value
            if(it != mp.end() && it->first == a[i]) down[i] = it->second; // want to get the largest value if a[i] == it->first
            else if(it != mp.begin()){
                it--;
                down[i] = it->second;
            }else down[i] = n; // invalid
        }
        
        vector<vector<int>> dp(2, vector<int>(n));
        // final values can always achieve the target
        dp[0][n-1] = dp[1][n-1] = 1;
        int ans = 1;
        for(int i = n-2; i >= 0; i--){
            dp[1][i] = down[i] == n ? 0 : dp[0][down[i]];
            dp[0][i] = up[i] == n ? 0 : dp[1][up[i]];
            // if can start with increasing
            if(dp[0][i]) ans++;
        }
        return ans;
    }
};
