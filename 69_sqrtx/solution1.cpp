/*
Using brute force, time complexity: sqrt(x)
40 ms, if use (s > x /s) and int, runtime is 162ms. Division in c++ is more expensive than multiplication
*/

using namespace std;

class Solution{
public:
    int mySqrt(int x){
        if(x <= 1) return x;
        for(long long s = 1; s <= x; ++s){
            if(s * s > x) return s - 1;
        }
        return -1;
    }
};
