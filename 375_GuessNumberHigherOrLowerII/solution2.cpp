// Brute-force : TLE
// Time complexity: O(n!), Space complexity: O(n) depth of recursion

class Solution{
public:
    int getMoneyAmount(int n){
        if(n < 2) return 0;
        return calculate(1, n);
    }
private:
    int calculate(int low, int high){
        if(low >= high) return 0;
        int minRes = INT_MAX;
        for(int i = low; i <= high; i++){
            int localMax = i + max(calculate(i+1, high), calculate(low, i-1))
            minRes = min(localMax, minRes);
        }
        return minRes;
    } 
};
