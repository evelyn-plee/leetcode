// O(nx), O(x)

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string maxStr = "";
        for(string word : d){
            if(isSubsequence(word, s)){
                if(word.length() > maxStr.length() || word.length() == maxStr.length() && word < maxStr) maxStr = word;
            }
        }
        return maxStr;
    }
private:
    bool isSubsequence(string word, string s){
        int j = 0;
        for(int i = 0; i < s.length() && j < word.length(); i++){
            if(word[j] == s[i]) j++;
        }
        return j == word.length();
    }
};
