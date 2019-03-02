// TC: O(n^2), SC: O(1)  -- Brute Force
// Idea is to extend the current partition label by finding the index of the last position of a char.
  
class Solution{
  public:
    vector<int> partitionLabels(string S){
        vector<int> ans = 0;
        size_t start = 0, end = 0;
        for(size_t i = 0; i < S.size(); i++){
            end = max(end, S.find_last_of(S[i]));
            if(i == end){
                ans.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return ans;
    }
};

// TC: O(n), SC: O(26/128) -- Greedy
// Store the index of the last position of a char in a vector

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> lastIndex(128, 0);
        for(int i = 0; i < S.size(); i++){
            lastIndex[S[i]] = i;
        }
        vector<int> ans;
        int start = 0, end = 0;
        for(int i = 0; i < S.size(); i++){
            end = max(end, lastIndex[S[i]]);
            if(i == end){
                ans.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return ans;
    }
};
