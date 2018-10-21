// O(n), O(n)
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> dict;
        bool found = false;
        for(int i = 0; i < s.length(); ++i){
            if(dict.count(s[i])) --dict[s[i]];
            else ++dict[s[i]];
        }
        for(auto c : dict){
            if(dict[c.first] != 0){
                if(found) return false;
                found = true;
            }
        }
        return true;
    }
};
