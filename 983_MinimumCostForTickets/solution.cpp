  class Solution{
  public:
    int mincostTickets(vector<int> &days, vector<int> &costs){
      unordered_set<int> travelDays(begin(days), end(days));
      int n = days.back() + 1;
      vector<int> dp(n, 0);
      
      for(int i = 1; i < n; i++){
        if(travelDays.find(i) == travelDays.end()) dp[i] = dp[i-1];
        else dp[i] = min(dp[i-1] + costs[0], min(dp[max(0, i-7)] + costs[1]), dp[max(0, i-31)] + costs[2]);
      }
      
      return dp[n-1];
    }
  }
  
// Optimized
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> travelDays(begin(days), end(days));
        int dp[31];
        dp[0] = 0;
        
        for(int i = 1; i <= days.back(); i++){
            if(travelDays.find(i) == travelDays.end()) dp[i % 31] = dp[(i-1) % 31];
            else dp[i % 31] = min(dp[(i-1) % 31] + costs[0], min(dp[max(0, i-7) % 31] + costs[1], dp[max(0, i-30) % 31] + costs[2]));
        }
        
        return dp[days.back() % 31];
    }
};
