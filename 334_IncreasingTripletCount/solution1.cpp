#include <vector>

using namespace std;

class Solution{
public:
    bool increasingTriplet(vector<int>& nums){
        int firstMin = INT_MAX;
        int secondMin = INT_MAX;
        for(int num : nums){
            if(num < firstMin) firstMin = num;
            else if(num < secondMin && num > firstMin) secondMin = num;
            if(num > secondMin) return true;
        }
        return false;
    }
};
