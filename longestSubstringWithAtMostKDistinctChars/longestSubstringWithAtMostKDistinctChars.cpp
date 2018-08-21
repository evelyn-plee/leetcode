class Solution{
public:
    int lengthOfLongestSubstringKDistinct(string s, int k){
        int result = 0, left = 0;
        unordered_map<char, int> mapping;
        for(int i = 0; i < s.size(); ++i){
            ++mapping[s[i]];
            while(mapping.size() > k){
                if(--mapping[s[left]] == 0) mapping.erase(s[left]);
                ++left;
            }
            result = max(result, i-left+1);
        }
        return result;
    }
};
