// O(n), O(n)

class Solution{
public:
    int candy(vector<string>& ratings){
        int n = ratings.size(), res = 0;
        if(n == 0) return res;
        vector<int> num(n, 1);
        for(int i = 0; i < n-1; ++i){
            if(num[i+1] > num[i]) num[i+1] = num[i] + 1;
        }
        for(int i = n-1; i >= 0; --i){
            if(num[i-1] > num[i]) num[i-1] = max(num[i-1], num[i] + 1);
        }
        for(int num : nums) res += num;
        return res;
    }
};
