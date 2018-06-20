class Solution{
public: 
    int lengthOfLongestSubstring(string s){
        unordered_map<char, int> ht;
        int maxLen = 0, curLen = 0, start = 0;
        for(int i = 0; i < s.size(); i++){
            if(ht.count(s[i])){
                for(int j = start; j < ht[s[i]]; j++){
                    ht.erase(s[j]);
                }
                start = ht[s[i]] + 1;
                curLen = i - ht[s[i]];
            } else{
                curLen++;
            }
            ht[s[i]] = i;
            maxLen = max(maxLen, curLen);
        }
        return maxLen;
    }
};
