class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(begin(words), end(words), [](const string& a, const string&b){
            return a.length() < b.length();
        });
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(valid(words[j], words[i])){
                    dp[i] = dp[j] + 1;
                }
            }
        }
        return *max_element(begin(dp), end(dp));
    }
    
private:
    bool valid(string& a, string& b){
        if(a.length() + 1 != b.length()) return false;
        int count = 0;
        for(int i = 0, j = 0; i < a.length(), j < b.length();){
            if(a[i] == b[j]){
                i++; j++;
            }else{
                count++; j++;
            }
        }
        return count <= 1;
    }
};
