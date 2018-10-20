// Time complexity: O(n * 2^l),l is # of letters, Space complexity: O(n) + O(n * 2^l), stack + sol 

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        dfs(S, 0, res);
        return res;
    }
private:
    void dfs(string& S, int i, vector<string>& ans){
        if(i == S.length()){
            ans.push_back(S);
            return;
        }
        dfs(S, i+1, ans);
        if(!isalpha(S[i])) return;
        S[i] ^= (1 << 5);
        dfs(S, i+1, ans);
        S[i] ^= (1 << 5);
    }
};
