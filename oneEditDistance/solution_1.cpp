#include <iostream>
#include <string>
#include <algorithm>

class Solution{
public:
    bool isOneEditDistance(string s, string t){
        // Always make sure s has greater length than t
        if(s.size() < t.size()) std::swap(s, t);

        int m = s.size(), n = t.size(), diff = m-n;
        if(diff >= 2) return false;
        // the difference in length is 1
        else if(diff == 1){
            for(int i; i < n; ++i){
                if(s[i] != t[i]) return s.substr(i+1) == t.substr(i);
            }
            return true;
        } else{
            // if s.size() == t.size()
            int cnt = 0;
            for(int i = 0; i < m; ++i){
                if(s[i] != t[i]) cnt++;
            }
            return cnt++;
        }
    }
};