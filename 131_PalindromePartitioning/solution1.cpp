// O(n* 2^n), O(n* 2^n)

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > res;
        if(s.empty()) return res;
        
        vector<string> path;
        dfs(0, s, path, res);
        
        return res;
    }
    
    void dfs(int start, string& s, vector<string>& cur, vector<vector<string> >& res) {
        if(start == s.size()) {
            res.push_back(cur);
            return;
        }
        for(int i = start; i < s.size(); ++i) {
            if(isPalindrome(s, start, i)) {
                cur.push_back(s.substr(start, i - start + 1));
                dfs(i+1, s, cur, res);
                cur.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
};
