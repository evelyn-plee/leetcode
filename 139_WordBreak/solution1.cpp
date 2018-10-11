/** Recursion with memoization
* Time complexity: O(n^2)
* Space complexity: O(n)
*/


#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution{
public:
    bool wordBreak(string s, vector<string>& wordDict){
        // Create a hashset for fast query
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        
        return wordBreak(s, dict);
    }
    
    bool wordBreak(string s, unordered_set<string>& dict){
        if(mem_.count(s)) return mem_[s];
        if(dict.count(s)) return mem_[s] = true;
        for(int j = 1; j < s.length(); j++){
            const left = s.substr(0, j);
            const right = s.substr(j);
            if(dict.count(right) && wordBreak(left, dict))
                return mem_[s] = true;
        }
        return mem_[s] = false;
    }
private:
    unordered_map<string, bool> mem_;
};
