/** Dp
* Time complexity: O(n^2)
* Space complexity: O(n)
*/

#include <vector>

using namespace std;

class Solution{
public:
    bool wordBreak(string s, vector<string>& wordDict){
        int ll = s.size();
        int dict = wordDict.size();
        
        vector<bool> dp(n+1, false);
        dp[0] = false;
        for(int i = 1; i < s.size(); ++i){
            for(int j = 0; j < dict; ++j){
                if(dp[i]){
                    string str = s.substr(i, wordDict[j].size());
                    if(wordDict[j] == str){
                        dp[i + wordDict[j].size()] = true;
                    }
                }
            }
        }
        return dp[ll];
    }
};
