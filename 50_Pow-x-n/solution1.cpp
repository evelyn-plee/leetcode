//Brute Force: O(n)

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(n < 0){
            x = 1/x;
            N = -N;
        }
        double ans = 1;
        for(long long i = 0; i < N; ++i){
            ans *= x;
        }
        return ans;
    }
};

// log(n), log(n)
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        if(n < 0){
            x = 1/x;
            N = -N;
        }
        return fastPow(x, N);
    }
private:
    double fastPow(double x, long long n){
        if(n == 0) return 1.0;
        double half = fastPow(x, n/2);
        if(n%2 == 0) return half*half;
        else return half*half*x;
    }
};

