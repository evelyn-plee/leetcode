// Brute force - consider every character of s and check if all occurences of it map to the same character in t
// Time complexity: O(n^2)

// Optimized - use array to store mappings

using namespace std;
#define MAX_CHARS 256
class Solution{
    bool areIsomorphic(string s, string t){
        if(s.length() != t.length()) return false;
        bool marked[MAX_CHARS] = {false};
        int map[MAX_CHARS];
        memset(map, -1, sizeof(map));
        
        for(int i = 0; i < s.length(); ++i){
            if(map[s[i]] == -1){
                if(marked[t[i]]) return false;
                marked[t[i]] = true;
                map[s[i]] = t[i];
            }else if(map[s[i]] != t[i]) return false;
        }
        return true;
    }
};
