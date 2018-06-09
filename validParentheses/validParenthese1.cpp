class Solution {
public:
    bool isValid(string s) {
        stack<char> res;
        for(int i = 0; i < s.size(); i++){
            if(isLeft(s[i])) res.push(s[i]);
            else{
                if(res.empty() || !validClosed(res.top(), s[i])) return false;
                res.pop();
            }
        }
        return res.empty();
    }
    
    bool isLeft(char a) {
        return (a=='(' || a=='{' || a=='[');
    }
    
    bool validClosed(char a, char b){
        if(a=='(') return b==')';
        if(a=='[') return b==']';
        if(a=='{') return b=='}';
        return false;
    }
};