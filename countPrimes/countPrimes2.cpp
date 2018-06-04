#include <stdio.h>

class Solution{
public:
    int countPrimes(int n){
        if(n <= 2) return 0;
        bool *prime = new bool[n];
        memset(prime, 0, sizeof(bool) *n);
        int i = 3, sqrtn = sqrt(n), count = n/2;
        while(i <= sqrtn){
            for(int j = i*i; j < n; j += (i << 1)){
                if(!prime[j]) count--;
                prime[j] = true;
            }
            i += 2;
            while(i <= sqrtn && prime[i]) i += 2;
        }
        delete prime;
        return count;
    }
};