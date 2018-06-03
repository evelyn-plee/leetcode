class Solution{
public:
    int climbStairs(int n){
        if(n<=0) return 0;
        int p1 = 1, p2 = 1;
        for(int i = 2; i<=n; i++){
            int temp = p1 + p2;
            p1 = p2;
            p2 = temp;
        }
        return p2;
    }
};