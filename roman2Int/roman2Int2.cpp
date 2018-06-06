class Solution {
public:
    int romanCharToInt(char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500; 
            case 'M': return 1000;
        }
        return 0;
    }
    int romanToInt(string s){
        int res = 0;
        if(s.empty()) return 0;
        if(s.size() == 1) return romanCharToInt(s[0]);
        int temp = romanCharToInt(s[0]);
        for(int i = 1; i < s.size(); i++){
            int v = romanCharToInt(s[i]);
            if(v > temp){
                res -= temp; temp = v;
            } else{
                res += temp; temp = v;
            }
        }
        res += temp;
        return res;
    }
};