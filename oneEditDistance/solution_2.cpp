#include <iostream>
#include <string>
#include <algorithm>

class Solution {
public:
  bool isOneEditDistance(string s, string t) {
        if (s == t || abs(int(s.size()) - int(t.size())) > 1) return false;
        
        bool diff = false;
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] != t[j]) {
                if (!diff) {
                    diff = true;
                    if (s.size() == t.size()) { i++; j++; }
                    else if (s.size() < t.size()) { j++; }
                    else { i++;}
                } 
                else {return false;}
            } 
            else {i++; j++;}
        }
        return true;
    }
};