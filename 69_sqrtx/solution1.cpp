/*
Using brute force, time complexity: sqrt(x)
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
