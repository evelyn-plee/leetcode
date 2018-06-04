#include <vector>

class Solution{
public:
    vector<string> fizzBuzz(int n){
        vector<string> index(n);
        for(int i = 1; i <= n; i++){
            if(i % 3 == 0) index[i-1] += "Fizz";
            if(i % 5 == 0) index[i-1] += "Buzz";
            if(index[i-1].empty()) index[i-1] += to_string(i);
        }
        return index;
    }
};