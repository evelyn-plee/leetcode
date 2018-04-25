class Solution{
public:
    bool isPalindrome(string s){
        int left = 0, right = s.size()-1;
        while(left < right){
            while(left < s.size() && !isalnum(s[left])) left++;
            while(right >= 0 && !isalnum(s[right])) right--;
            if(left >= right) return true;
            if(tolower(s[left++]) != tolower(s[right--])) return false;
        }
        return true;
    }
};
