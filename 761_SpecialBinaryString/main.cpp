class Solution{
public:
    static bool cmp(string &a, string &b){
        return a > b;
    }
    
    string makeLargestSpecial(string S){
        int N = S.length();
        vector<string> validSubstr;
        int cnt = 0, j = 0;
        for(int i = 0; i < N; i++){
            cnt += (S[i] == '1') ? 1 : -1;
            if(cnt == 0){
                validSubstr.push_back('1' + makeLargestSpecial(j+1, i-j) +'0');
                j = i+1;
            }
        }
        sort(validSubstr.begin(), validSubstr.end(), cmp);
        
        string ans = "";
        for(int i = 0; i < validSubstr.size(); i++){
            ans += validSubstr[i];
        }
        return ans;
    }
};
