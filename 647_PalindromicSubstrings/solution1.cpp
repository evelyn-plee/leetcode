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
