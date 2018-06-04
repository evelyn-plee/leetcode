#include <vector>

class Solution{
public:
    int countPrimes(int n) {
        if (n<=2) return 0;
        vector<bool> passed(n, false);
        int sum = 1;
        int upper = sqrt(n);
        for(int i = 3; i<n; i+=2){
            if(!passed[i]){
                sum++;
                if(i>upper) continue;
                for(int j = i*i; j<n; j+=2*i){
                    passed[j] = true;
                }
            }
        }
        return sum;
    }
};