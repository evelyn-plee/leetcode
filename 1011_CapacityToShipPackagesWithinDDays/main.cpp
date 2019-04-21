class Solution{
public:
    int shipWithinDays(vector<int>& weights, int D){
        int s = 0, e = 0;
        for(const auto& w : weights){
            e += w;
            s = max(s, w);
        }
        while(s < e){
            int m = (s + e)/2, cnt = 0, sum = 0;
            for(int i = 0; i < weights.size() && cnt < D; i++){
                sum += weights[i];
                if(sum > m){
                    sum = 0;
                    cnt++;
                    i--;
                }
            }
            if(i == weights.size()){ e = m; }
            else{ s = m + 1; }
        }
        return s;
    }
};
