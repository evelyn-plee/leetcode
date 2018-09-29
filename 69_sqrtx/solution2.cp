class Solution{
public:
    int mySqrt(int x){
        if(x <= 1) return x;
        int l = 1;
        int r = x/2;
        while(l <= r){
            int m = (l + r)/2;
            if(m <= x/m && (m+1) > x/(m+1)) return m;
            if(m < x/m) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }
};
