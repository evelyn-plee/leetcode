class Solution{
public:
    int nextGreaterElement(int n){
        string str = to_string(n);
        int i = str.size() - 1;
        for(; i > 0 && str[i-1] >= str[i]; --i);
        if(!i) return -1;
        int j = i, k = i;
        for(; k < str.size(); ++k){
            if(str[k] > str[i-1] && str[k] <= str[j]) j = k;
        }
        swap(str[i-1], str[j]);
        reverse(str.begin() + i, str.end());
        long long ans = stoll(str);
        return ans > INT_MAX ? -1 : ans;
    }
};
