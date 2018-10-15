/** Brute-Force with caching **/


class Solution{
public:
    int numMatchingSubseq(string S, vector<string>& words){
        int ans = 0;
        unordered_map<string, bool> m;
        for(const string& word: words){
            auto it = m.find(word);
            if(it == m.end()){
                bool match = isMatch(S, words);
                ans += m[word] = match;
            } else{
                ans += it->second;
            }
        }
        return ans;
    }
private:
    bool isMatch(const string S, const string word){
        int start = 0;
        for(char ch : word){
            bool found = false;
            for(int i = start; i < S.length(); ++i){
                if(S[i] == ch){
                    // not all of the characters are connecting
                    found = true;
                    start = i+1;
                    break;
                }
            }
            if(!found) return false; 
        }
        return true;
    }
};
