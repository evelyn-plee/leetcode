/*
Using greedy
Runtime complexity = max(m, n) -- m, str.size and n, pattern.size()
*/

class Solution {
public:
    bool isMatch(string str, string pattern){
        int s = 0, p = 0;
        int starIdx = -1; int match = 0;
        
        while(s < str.size()){
            if(p < pattern.size() && (pattern[p] == str[s] || pattern[p] == '?')){ p++; s++; continue;}
            if(p < pattern.size() && pattern[p] == '*') {starIdx = p; p++; match = s; continue;}
            if(starIdx != -1){ match++; s = match; p = starIdx +1; continue;}
            return false;
        }
        while(p < pattern.size() && pattern[p]=='*') p++;
        return p == pattern.size();
    }
};
